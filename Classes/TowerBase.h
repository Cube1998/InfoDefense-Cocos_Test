#pragma once

#ifndef TOWER_BASE_H
#define TOWER_BASE_H

#include "cocos2d.h"
#include "Obj.h"
#include "ArrowP.h"

class TowerBase : public Obj
{
protected:
	bool could_attack;  //�ܷ񹥻�
	int ATK; // ������
	int range; //��Χ
public:
	TowerBase(int hp, int side, bool b, int atk, int _range);

	virtual bool if_attack(Obj*);
	virtual Arrow * attack(Obj*) = 0;
};

#endif // !TOWER_H