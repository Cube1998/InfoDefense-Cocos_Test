//
//  Fire.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/7.
//

#ifndef Fire_h
#define Fire_h

#include <stdio.h>
#include "cocos2d.h"
#include "Hero.h"
#include "SoundManager.h"
USING_NS_CC;

class Fire :public Hero
{
public:

	bool initFire();
	CREATE_FUNC(Fire);
	static Fire* createFire(Point location);
	void createAndSetHpBar();
	void update(float dt);
	void Attack();
	void Skill();
    void Death();
    void setDeath();
	void SetHpBar();
    void setNone();
	//bool CheckAttack();
	int damage = 10;

private:
	float StepWard = 0;
	float pre_x = 0;
};

#endif /* Fire_hpp */
