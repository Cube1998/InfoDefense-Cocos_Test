#pragma once

#ifndef ARROW_H
#define ARROW_H

#include "cocos2d.h"
#include "Obj.h"


class Arrow : public cocos2d::Sprite
{
protected:
	cocos2d::Vec2 velocity;
	int speed = 8;
	int ATK;
	int HP = 10;
	Obj * target;
public:
	Arrow(Obj *ta,int atk);
	Arrow() = default;
	

	void setVelocity(const cocos2d::Vec2 &);
	cocos2d::Vec2 getVelocity() const;

	void update(float dt) override;

	void setTarget(Obj *);
	Obj * getTarget() {return target; }

	int getHP() { return HP; }
};


#endif // !ARROW_H
