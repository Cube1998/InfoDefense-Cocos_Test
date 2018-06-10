//
//  Thor.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/9.
//

#include "Thor.h"
#include "GameManager.h"
#include <cmath>
#include <iostream>
using namespace std;


Thor * Thor::createThor(Point point)
{
    auto thor = new Thor();
    if (thor&&thor->initThor())
    {
        thor->currState = StateNone;
        thor->setPosition(point);
        thor->createAndSetHpBar();
        
        return thor;
        
    }
    CC_SAFE_DELETE(thor);
    return NULL;
}
bool Thor::initThor()
{
    
    if (!Hero::init())
    {
        return false;
    }
    schedule(schedule_selector(Thor::update));
    this->setSpriteFrame("thor_0001.png");
    this->HP = 100;
    this->HPMax = 100;
    this->Range = 200;
    this->Speed = 50;
    createAndSetHpBar();
    lastState = StateNone;
    auto hero_key_listener = EventListenerKeyboard::create();
    hero_key_listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event *event)
    {
        this->runToPoint(Point(this->getPositionX() + StepWard, this->getPositionY()));
        return true;
        
    };
    hero_key_listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event *event)
    {
        
        if (this->getState() == StateNone) {
            if (keyCode == EventKeyboard::KeyCode::KEY_W)
                this->runToPoint(Point(this->getPositionX(), this->getPositionY() + 50));
            if (keyCode == EventKeyboard::KeyCode::KEY_S)
                this->runToPoint(Point(this->getPositionX(), this->getPositionY() - 50));
            if (keyCode == EventKeyboard::KeyCode::KEY_A) {
                this->runToPoint(Point(this->getPositionX() - 50, this->getPositionY()));
            }
            if (keyCode == EventKeyboard::KeyCode::KEY_D) {
                this->runToPoint(Point(this->getPositionX() + 50, this->getPositionY()));
            }
            if (keyCode == EventKeyboard::KeyCode::KEY_H)
                this->Attack();
            if (keyCode == EventKeyboard::KeyCode::KEY_J)
            {
                this->Skill(); this->HP -= rand_0_1() * 10;
            }
        }
    };
    EventDispatcher *eventdispatcher1 = Director::getInstance()->getEventDispatcher();
    eventdispatcher1->addEventListenerWithSceneGraphPriority(hero_key_listener, this);
    
    return true;
    
}
void Thor::createAndSetHpBar()
{
    hpBgSprite = Sprite::create("HPBar_bg.png");
    
    hpBgSprite->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height));
    this->addChild(hpBgSprite);
    
    hpBar = ProgressTimer::create(Sprite::create("HPBar.png"));
    hpBar->setType(ProgressTimer::Type::BAR);
    hpBar->setMidpoint(Point(0, 0.5f));
    hpBar->setBarChangeRate(Point(1, 0));
    hpBar->setPercentage(100 * HP / HPMax);
    hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
    hpBgSprite->addChild(hpBar, 1, 102);
    
}
void Thor::Attack()
{
    if (getState() != StateDeath) {
        //unscheduleAllCallbacks();
        //scheduleUpdate();
        setState(StateAttack);
        runAction(Sequence::create(
                                   DelayTime::create(1),
                                   CallFuncN::create(CC_CALLBACK_0(Hero::setState, this, StateNone)),
                                   NULL));
    }
}
void Thor::Skill()
{
    if (getState() != StateSkill) {
        //unscheduleAllCallbacks();
        //scheduleUpdate();
        stopAllActions();
        setState(StateSkill);
        runAction(Sequence::create(DelayTime::create(1.5),
                                   CallFuncN::create(CC_CALLBACK_0(Hero::setState, this, StateNone)),
                                   NULL));
    }
}
void Thor::update(float dt)
{
    if(HP<=0)
    {
        setState(StateDeath);
        //this->Death();
    }
    this->SetHpBar();
    this->searchTarget();
   
    
    
    if (fabs(pre_x) > 0.0001)
    {
        if (pre_x > this->getPosition().x + 0.001)
            StepWard = -0.001;
        else if (pre_x < this->getPosition().x - 0.001)
            StepWard = 0.001;
    }
    pre_x = this->getPosition().x;
    
    if (lastState != getState()) {
        switch (getState())
        {
            case(StateRun): {
                lastState = StateRun;
                stopHeroAnimation();
                auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("ThorRun")));
                action->setTag(StateRun);
                this->runAction(action); }
                break;
            case(StateNone): {
                lastState = StateNone;
                stopHeroAnimation();
                this->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("thor_0001.png")); }
                break;
            case(StateAttack): {
                lastState = StateAttack;
                stopHeroAnimation();
                auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("ThorAttack")));
                action->setTag(StateAttack);
                this->runAction(action);
                if(attackTarget)
                    this->attackTarget->subHP(this->damage);
                
                
            }
                break;
            case(StateDeath):
            {
                lastState = StateDeath;
                stopHeroAnimation();
                auto action = Animate::create(AnimationCache::getInstance()->getAnimation("ThorDeath"));
                action->setTag(StateDeath);
                
                this->runAction(Sequence::create(action,FadeOut::create(2.0f),CallFuncN::create(CC_CALLBACK_0(Thor::setNone, this)) ,NULL));
            }
                
            case(StateSkill): {
                lastState = StateSkill;
                stopHeroAnimation();
                //auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("ThorHalo")));
                auto action1 = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("ThorSkill")));
               // action->setTag(StateSkill);
                action1->setTag(StateSkill);
              //  Sprite *tmp = Sprite::create();
              //  tmp->setPosition(this->getContentSize().width / 2, 0);
               // this->addChild(tmp, -1, 101);
                this->runAction(action1);
               // tmp->runAction(action);
                if(attackTarget)
                    this->attackTarget->subHP(this->damage*10);
            }
              
                break;
        }
        
    }
    
}
void Thor::SetHpBar()
{
    this->hpBar ->setPercentage(100*HP/HPMax);
}
void Thor::setNone()
{
    this->removeFromParent();
}

