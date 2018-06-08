//
//  Enemy.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/7.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Hero.hpp"
USING_NS_CC;
class Enemy : public Sprite
{
public:
    virtual bool init();
    int HP;
    int HPMax;
    static Enemy* createEnemy(Point location);
    Sprite* hpBgSprite;
    void update(float dt);
    void getHurt(int damage);
   // virtual void update(float dt){}
protected:
    virtual void runToPoint(Vec2 point);
    virtual void createAndSetHpBar();
};


#endif /* Enemy_hpp */
