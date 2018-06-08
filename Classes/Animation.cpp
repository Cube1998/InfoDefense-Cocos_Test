//
//  Animation.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/7.
//

#include "Animation.hpp"
#include "cocos2d.h"
USING_NS_CC;


void loadAnimation::initAnimation()
{
    createFire();
    
    
}
void loadAnimation::createFire()
{
    Animation *firerun = Animation::create();
    SpriteFrame* frame = nullptr;
    __String *framename = __String::create("");
    for(int No=8;No<=12;No++)
    {
        framename = __String::createWithFormat("hero_elemental_0%03d.png",No);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());
        if(frame!=nullptr){
            firerun->addSpriteFrame(frame);
        }
    }
    firerun->setDelayPerUnit(0.1f);
    AnimationCache::getInstance()->addAnimation(firerun, "firerun");
    
    
    
    Animation *fireAttack = Animation::create();
    frame = nullptr;
    framename = __String::create("");
    for(int No=14;No<=24;No++)
    {
        framename = __String::createWithFormat("hero_elemental_0%03d.png",No);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());
        if(frame!=nullptr){
            fireAttack->addSpriteFrame(frame);
        }
    }
    fireAttack->setDelayPerUnit(0.1f);
    AnimationCache::getInstance()->addAnimation(fireAttack, "fireAttack");
    
    
    Animation *fireHalo = Animation::create();
    frame = nullptr;
    framename = __String::create("");
    for(int No=1;No<=11;No++)
    {
        framename = __String::createWithFormat("hero_elemental_blast_0%03d.png",No);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());
        if(frame!=nullptr){
            fireHalo->addSpriteFrame(frame);
        }
    }
    fireHalo->setDelayPerUnit(0.1f);
    AnimationCache::getInstance()->addAnimation(fireHalo, "fireHalo");
    
    
    Animation *fireSkill = Animation::create();
    frame = nullptr;
    framename = __String::create("");
    for(int No=32;No<=61;No++)
    {
        framename = __String::createWithFormat("hero_elemental_0%03d.png",No);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());
        if(frame!=nullptr){
            fireSkill->addSpriteFrame(frame);
        }
    }
    fireSkill->setDelayPerUnit(0.1f);
    AnimationCache::getInstance()->addAnimation(fireSkill, "fireSkill");
}
