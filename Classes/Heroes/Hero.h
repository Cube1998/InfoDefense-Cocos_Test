//
//  Hero.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/4.
//

#ifndef Hero_h
#define Hero_h

#include <stdio.h>
#include "cocos2d.h"
#include "EnemyBase.h"
//#include "GameManager.h"
USING_NS_CC;
typedef enum {
	StateNone = 0,
	StateRun,
	StateAttack,
	StateSkill,
	StateSelected,
	StateDeath

}HeroState;
class Hero : public Sprite
{
public:

	virtual bool init();
	static Hero* createHero(Point location);
	void setState(HeroState);
	HeroState getState();
	int HP;
	int HPMax;
    int Range = 100;
    int Speed = 100;
    int damage = 30000;
	Sprite* hpBgSprite;//LifeBar
	ProgressTimer * hpBar;
    void subHP(int da){HP-=da;}
    int getHP(){return HP;}
    bool checkMovable(Vec2 point);
    void Attack();
    void Skill();
protected:
    EnemyBase *attackTarget;
	HeroState lastState;
	virtual void runToPoint(Vec2 point);
	virtual void runAnimation();
	virtual void createAndSetHpBar();
	virtual void update(float dt) {}
	HeroState currState;
	void stopHeroAnimation();
	
    virtual void searchTarget();
    float getDistanceToEnemy(EnemyBase *enemy);
    

};

#endif /* Hero_hpp */
