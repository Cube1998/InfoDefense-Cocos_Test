//
//  Fire.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/7.
//

#ifndef Fire_hpp
#define Fire_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Hero.hpp"
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
    void SetHpBar();
    bool CheckAttack();
    int damage = 10;
    
};

#endif /* Fire_hpp */
