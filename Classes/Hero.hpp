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
#include "Enemy.hpp"
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
    int Range;
    Sprite* hpBgSprite;//LifeBar
protected:
    
    HeroState lastState;
    HeroState currState;
    virtual void runToPoint(Vec2 point);
    virtual void createAndSetHpBar();
    virtual void update(float dt){}
    void stopHeroAnimation();
    virtual void Attack();
    virtual void Skill();
    virtual void searchTarget();
    float getDistanceToEnemy(Enemy *enemy);
    
    
    Enemy *attackTarget;
    
};

#endif /* Hero_hpp */
