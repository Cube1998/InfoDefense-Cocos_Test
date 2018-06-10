#include "SoundManager.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h" 

using namespace CocosDenshion;
USING_NS_CC;

bool SoundManager::checkEffectState()
{
	if(UserDefault::getInstance()->getIntegerForKey("backeffect",1)==1)
		return true;
	else
		return false;
}

void SoundManager::playMageShot()
{
    if(checkEffectState())
    {
       // SimpleAudioEngine::getInstance()->playEffect("Aleria_special_arrow.caf");
       // printf("SimpleAudioEngine");
    }
    
}
