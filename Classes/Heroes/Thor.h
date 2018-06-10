//
//  Thor.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/9.
//

#ifndef Thor_hpp
#define Thor_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Hero.h"
USING_NS_CC;
class Thor :public Hero
{
public:
    
    bool initThor();
    CREATE_FUNC(Thor);
    static Thor* createThor(Point location);
    void createAndSetHpBar();
    void update(float dt);
    void Attack();
    void Skill();
    void SetHpBar();
    void setNone();
    
    
    
private:
    float StepWard = 0;
    float pre_x = 0;
};

#endif /* Thor_hpp */
