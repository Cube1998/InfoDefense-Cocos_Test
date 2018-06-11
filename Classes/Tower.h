#pragma once
#ifndef TOWER_H
#define TOWER_H

#include "cocos2d.h"
#include <stdio.h>
#include "TowerBase.h"
USING_NS_CC;

/*
	1: arrow tower
	2: magic tower
	3: bait power
*/

const int HP1(1000);
const int HP2(1000);
const int HP3(1000);

const bool side1(0);
const bool side2(0);
const bool side3(0);

const bool could_a1(1);
const bool could_a2(1);
const bool could_a3(1);

const int ATK1(40);
const int ATK2(60);
const int ATK3(80);

const int range1(300);
const int range2(300);
const int range3(400);

class Tower1 : public TowerBase
{
public:
	Tower1();
	static Tower1 * createTower1(Point location);
	bool initTower1();
	CREATE_FUNC(Tower1);

	bool if_attack(Obj*) override;
	Arrow * attack(Obj*);
};

class Tower2 : public TowerBase
{
public:
	Tower2();
	static Tower2 * createTower2(Point point);

	bool initTower2();
	CREATE_FUNC(Tower2);

	bool if_attack(Obj*) override;
	Arrow * attack(Obj*) override;
};

class Tower3 : public TowerBase
{
public:
	Tower3();
	static Tower3 * createTower3(Point point);

	bool initTower3();
	CREATE_FUNC(Tower3);

	bool if_attack(Obj*) override;
	Arrow * attack(Obj*) override;
};

#endif