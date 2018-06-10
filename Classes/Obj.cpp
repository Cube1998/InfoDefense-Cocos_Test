#include "Obj.h"

Obj::Obj(int _hp, int _side) : HP(_hp), side(_side)
{
	this->velocity = cocos2d::Vec2::ZERO;
}

Obj * Obj::createWithHP_side(int _hp, int _side)
{
	Obj *obj = new Obj(_hp, _side);
	return obj;
}

void Obj::setHP(int _hp)
{
	this->HP = _hp;
}

void Obj::subHP(int _hp)
{
	HP -= _hp;
}

int Obj::getHP() const
{
	return this->HP;
}

void Obj::setVelocity(cocos2d::Vec2 g)
{
	this->velocity = g;
}

cocos2d::Vec2 Obj::getVelocity() const
{
	return this->velocity;
}

int Obj::getSide() const
{
	return this->side;
}
