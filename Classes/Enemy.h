//
//  Enemy.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/7.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Hero.h"
#include "EnemyBase.h"
USING_NS_CC;

const int baseHP = 500;
const int baseATK = 10;
const int baseRange = 50;

class Enemy : public EnemyBase
{
public:
	virtual bool init();

	static Enemy* createEnemy(Point location);
	static Enemy* createEnemy();
	Sprite* hpBgSprite;
    ProgressTimer * hpBar;
	void getHurt(int damage);
    void SetHpBar();
	Enemy() = default;
	void update(float dt) override;
	void setTarget(Hero *h) { target = h; }
    void setHPMax(int hpmax){HPMax =hpmax;}
	void fire();
	int getState() { return state; }
protected:
	int HPMax ;
	std::vector<Vec2> path;
	std::vector<Vec2>::iterator pit;
	virtual void runToPoint(Vec2 point);
	virtual void createAndSetHpBar();
	int state = 1;
	int state2 = 1;
	Hero * target;
};

#endif /* Enemy_hpp */
