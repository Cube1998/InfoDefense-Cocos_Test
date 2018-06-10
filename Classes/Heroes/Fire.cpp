//
//  Fire.cpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/7.
//

#include "Fire.h"
#include "GameManager.h"

#include <cmath>
#include <iostream>
using namespace std;

Fire * Fire::createFire(Point point)
{
	auto fire = new Fire();
	if (fire&&fire->initFire())
	{
		fire->currState = StateNone;
		fire->setPosition(point);
		fire->createAndSetHpBar();

		return fire;

	}
	CC_SAFE_DELETE(fire);
	return NULL;
}
bool Fire::initFire()
{

	if (!Hero::init())
	{
		return false;
	}
	schedule(schedule_selector(Fire::update));
	this->setSpriteFrame("hero_elemental_0001.png");
	this->HP = 100;
	this->HPMax = 100;
    this->Range = 200;
    this->Speed = 200;
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
void Fire::createAndSetHpBar()
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
void Fire::Attack()
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
void Fire::Skill()
{
	if (getState() != StateSkill&&getState()!=StateDeath) {
		//unscheduleAllCallbacks();
		//scheduleUpdate();
		stopAllActions();
		setState(StateSkill);
		runAction(Sequence::create(DelayTime::create(1.5),
			CallFuncN::create(CC_CALLBACK_0(Hero::setState, this, StateNone)),
			NULL));
	}
}
void Fire::Death()
{

        stopAllActions();
        setState(StateDeath);
 
   runAction(Sequence::create(DelayTime::create(1),CallFuncN::create(CC_CALLBACK_0(Fire::setDeath, this)), NULL));
    
}
void Fire::update(float dt)
{
    if(HP<=0)
    {
        setState(StateDeath);
       //this->Death();
    }
    this->searchTarget();
	this->SetHpBar();
	
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
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("FireRun")));
			action->setTag(StateRun);
			this->runAction(action); }
						break;
		case(StateNone): {
			lastState = StateNone;
			stopHeroAnimation();
			this->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_elemental_0001.png")); }
						 break;
		case(StateAttack): {
			lastState = StateAttack;
			stopHeroAnimation();
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("FireAttack")));
			action->setTag(StateAttack);
			this->runAction(action);
            if(attackTarget)
            this->attackTarget->subHP(this->damage);


		}
						   break;
		case(StateSkill): {
			lastState = StateSkill;
			stopHeroAnimation();
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("FireHalo")));
			auto action1 = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("FireSkill")));
			action->setTag(StateSkill);
			action1->setTag(StateSkill);
			Sprite *tmp = Sprite::create();
			tmp->setPosition(this->getContentSize().width / 2, 0);
			this->addChild(tmp, -1, 101);
			this->runAction(action1);
			tmp->runAction(action);
			this->damage = 100;
		}
						  break;
            case(StateDeath):
            {
                lastState = StateDeath;
                stopHeroAnimation();
                this->setSpriteFrame("hero_elemental_0108.png");
                auto action = Animate::create(AnimationCache::getInstance()->getAnimation("FireDeath"));
                action->setTag(StateDeath);
                
                this->runAction(Sequence::create(action,FadeOut::create(2.0f),CallFuncN::create(CC_CALLBACK_0(Fire::setNone, this)) ,NULL));
            }
		}

	}

}
void Fire::SetHpBar()
{
	  this->hpBar ->setPercentage(100*HP/HPMax);
}
void Fire::setDeath()
{
    this->setSpriteFrame("hero_elemental_0108.png");
}
void Fire::setNone()
{
    this->removeFromParent();
}
