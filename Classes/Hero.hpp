//
//  Hero.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/4.
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
typedef enum{
    StateNone = 0,
    StateRun,
    StateAttack,
    StateSkill,
    StateSelected,
    StateDeath
    
}HeroState;
class Hero : public Sprite
{
public:
    
    virtual bool init();
    static Hero* createHero(Point location);
    void setState(HeroState );
    HeroState getState();
    int HP;
    int HPMax;
    Sprite* hpBgSprite;//LifeBar
protected:
    
    HeroState lastState;
    virtual void runToPoint(Vec2 point);
    virtual void runAnimation();
    virtual void createAndSetHpBar();
    virtual void update(float dt){}
    HeroState currState;
    void stopHeroAnimation();
    virtual void Attack();
    virtual void Skill();
    bool isLocked;
    
};

#endif /* Hero_hpp */
