#pragma once

#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include "cocos2d.h"
#include "Obj.h"
#include <string>
USING_NS_CC;
class EnemyBase : public Obj
{
protected:
	int ATK;
	int range;
public:
	virtual void update(float) override;
	EnemyBase();
	static EnemyBase * creat();
	void setPic(char* str);
};

#endif
