//
//  Animation.cpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/7.
//

#include "Animation.h"
#include "cocos2d.h"
USING_NS_CC;


void loadAnimation::initAnimation()
{
	createFire();
    createThor();
    createDarkSlayer();
    createDenas();

}
void loadAnimation::createDarkSlayer()
{
    
}
void loadAnimation::createFire()
{
    createAnimationByIndexAndName("hero_elemental_%04d.png",8,12,"FireRun",0.1f);
    createAnimationByIndexAndName("hero_elemental_%04d.png",14,24,"FireAttack",0.1f);
    createAnimationByIndexAndName("hero_elemental_blast_%04d.png",1,11,"FireHalo",0.1f);
    createAnimationByIndexAndName("hero_elemental_%04d.png",32,61,"FireSkill",0.1f);
    createAnimationByIndexAndName("hero_elemental_%04d.png",99,108,"FireDeath",0.1f);
}
void loadAnimation::createThor()
{
    createAnimationByIndexAndName("thor_%04d.png",2,7,"ThorRun",0.1f);
    createAnimationByIndexAndName("thor_%04d.png", 43, 63, "ThorAttack",0.05f);
    createAnimationByIndexAndName("thor_%04d.png",8,41,"ThorDeath",0.05f);
    createAnimationByIndexAndName("thor_%04d.png",65,95,"ThorSkill",0.05f);
    createAnimationByIndexAndName("thor_%04d.png",103,127,"ThorThrow",0.05f);
    createAnimationByIndexAndName("thor_%04d.png",131,147,"ThorUpdate",0.05f);

}
void loadAnimation::createDenas()
{
    createAnimationByIndexAndName("hero_king_%04d.png",2,6,"DenasRun",0.1f);
}
void loadAnimation::createAnimationByIndexAndName(char *str, int start_Index, int end_Index,char* AnimationName,float DelayPerUnit)
{
    Animation *tmpAnimation = Animation::create();
    SpriteFrame* frame = nullptr;
    __String *framename = __String::create("");
    for (int No = start_Index; No <= end_Index; No++)
    {
        framename = __String::createWithFormat(str, No);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());
        if (frame != nullptr) {
            tmpAnimation->addSpriteFrame(frame);
        }
    }
    tmpAnimation->setDelayPerUnit(DelayPerUnit);
    AnimationCache::getInstance()->addAnimation(tmpAnimation, AnimationName);
}
