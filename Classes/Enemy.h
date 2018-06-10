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

#include "EnemyBase.h"
USING_NS_CC;

const int baseHP = 300;
const int baseATK = 10;
const int baseRange = 100;

class Enemy : public EnemyBase
{
public:
	virtual bool init();

	static Enemy* createEnemy(Point location);
	Sprite* hpBgSprite;
    ProgressTimer * hpBar;
	void update(float dt);
	void getHurt(int damage);
    void SetHpBar();
	Enemy() = default;
protected:
	int HPMax;
	virtual void runToPoint(Vec2 point);
	virtual void createAndSetHpBar();
};


#endif /* Enemy_hpp */
