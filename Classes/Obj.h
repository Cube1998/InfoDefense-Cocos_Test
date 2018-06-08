#pragma once

#ifndef OBJ_H
#define OBJ_H

#include "cocos2d.h"

class Obj : public cocos2d::Sprite
{
protected:
	cocos2d::Vec2 velocity;
	int HP;
	int side; // 2 means friend
	           // 1 means enemy
	            // 0 means neutrality
public:
	Obj(int _hp,int _side);
	static Obj* createWithHP_side(int _hp,int _side);

	void setHP(int _hp);
	void subHP(int _hp);
	int getHP() const;

	void setVelocity(cocos2d::Vec2);
	cocos2d::Vec2 getVelocity() const;
	
	int getSide() const;
};

#endif // !OBJ_H
