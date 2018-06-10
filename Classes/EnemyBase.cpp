#include "EnemyBase.h"

void EnemyBase::update(float)
{
	if (HP <= 0)
	{
		/*auto pr = getParent();
		pr->removeChild(this);*/
	}
	else setPosition(getPosition() + cocos2d::Vec2(-2, 1));
}

EnemyBase::EnemyBase() : Obj(200, 1), ATK(0), range(0) {}

EnemyBase * EnemyBase::creat()
{
	return new EnemyBase();
}

void EnemyBase::setPic(char *str)
{
	this->setSpriteFrame(str);
}
