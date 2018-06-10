#include "TowerBase.h"

TowerBase::TowerBase(int hp, int side, bool b, int atk, int _range) : Obj(hp, side),
	could_attack(b), ATK(atk), range(_range) {}

bool TowerBase::if_attack(Obj*)
{
	if(!this->could_attack)return false;
	return true;
}

