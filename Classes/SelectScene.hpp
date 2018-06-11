//
//  SelectScene.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/11.
//

#ifndef SelectScene_hpp
#define SelectScene_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "GameScene.h"
#include "GameManager.h"



USING_NS_CC;

class SelectScene : public Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SelectScene);
    void Callback1(cocos2d::Ref * pSender);
    void Callback2(cocos2d::Ref * pSender);
    
    
};


#endif /* SelectScene_hpp */
