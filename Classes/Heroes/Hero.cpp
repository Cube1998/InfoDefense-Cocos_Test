//
//  Hero.cpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/4.
//
#include "GameManager.h"
#include "Hero.h"
#include <iostream>
using namespace std;
void Hero::createAndSetHpBar()
{
	hpBgSprite = Sprite::create("HPBar_bg.png");

	hpBgSprite->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height));
	ProgressTimer * hpBar = ProgressTimer::create(Sprite::create("HPBar.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(100 * this->HP / this->HPMax);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBgSprite->addChild(hpBar);
	this->addChild(hpBgSprite, 0);
}

bool Hero::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->HP = 0;
	this->HPMax = 0;
	auto hero_listener = EventListenerTouchOneByOne::create();
	hero_listener->onTouchBegan = [&](Touch* touch, Event* event) {
        cout<<touch->getLocation().x<<"   "<<touch->getLocation().y<<endl;
        
        return true;
	};
	hero_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		if (this->getState() == StateNone)

			this->runToPoint(touch->getLocation() + Vec2(0, 40));
		else
		{
			this->setState(StateNone);
			this->update(0.01);
			this->runToPoint(touch->getLocation() + Vec2(0, 40));

		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(hero_listener, this);


	return true;
}

void Hero::runAnimation()
{
	Animation *heroAnimation = Animation::create();
	for (int i = 8; i <= 12; i++)
	{
		__String * framename = __String::createWithFormat("hero_elemental_0%03d.png", i);

		SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());

		if (frame != nullptr)
			heroAnimation->addSpriteFrame(frame);
	}
	heroAnimation->setDelayPerUnit(0.1f);
	heroAnimation->setRestoreOriginalFrame(true);
	this->runAction(RepeatForever::create(Animate::create(heroAnimation)));


}
void Hero::runToPoint(Vec2 point)
{
	if(checkMovable(point))
    {
	if (getState() != StateDeath) {
		//unscheduleAllCallbacks();
		//scheduleUpdate();
		stopAllActions();
		if ((point.x - this->getPositionX())>0) {
			this->setFlippedX(false);
		}
		else {
			this->setFlippedX(true);
		}
		setState(StateRun);
		auto action = Sequence::create(MoveTo::create(point.getDistance(this->getPosition()) / Speed, point),
			CallFuncN::create(CC_CALLBACK_0(Hero::setState, this, StateNone)),
			NULL);
		action->setTag(105);

		runAction(action);


	}
    }

}
void Hero::Attack()
{
	if (getState() != StateDeath) {
		
		stopAllActions();
		setState(StateAttack);
	}
}
void Hero::Skill()
{
	if (getState() != StateDeath) {
		
		stopAllActions();
		setState(StateSkill);
	}
}
void Hero::setState(HeroState state)
{
	this->currState = state;
}
HeroState Hero::getState()
{
	return currState;
}
void Hero::stopHeroAnimation()
{
	for (int i = 1; i <= 8; i++)
	{
		this->stopActionByTag(i);
	}

	this->removeChildByTag(101);

}
void Hero::searchTarget()
{
    auto enemyVector = GameManager::getInstance()->enemyVector;
    
    if(enemyVector.size()>0)
    {
        float shortestDistance = getDistanceToEnemy(enemyVector.at(0));
        this->attackTarget = nullptr;
        for(int i=0;i<enemyVector.size();i++)
        {
            auto tmp = enemyVector.at(i);
            auto disTmp = getDistanceToEnemy(tmp);
            if(shortestDistance>=disTmp)
            {
                shortestDistance = disTmp;
                if(shortestDistance < this->Range)
                    this->attackTarget = tmp;
                //CC_SAFE_DELETE(tmp);
            }
        }
    }
    else {
        this->attackTarget = NULL;
    }
    
}
float Hero::getDistanceToEnemy(EnemyBase* enemy)
{
    return this->getPosition().getDistance(enemy->getPosition());
}
bool Hero::checkMovable(Vec2 point)
{
    auto rect1 = Rect(220, 400, 300, 120);
    auto rect2 = Rect(650, 400, 300, 120);
    auto rect3 = Rect(360, 200, 400, 120);
    auto rect4 = Rect(0,0,500,140);
    return !(rect1.containsPoint(point)||rect2.containsPoint(point)||rect3.containsPoint(point)||rect4.containsPoint(point));
    
}
