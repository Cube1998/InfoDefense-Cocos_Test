//
//  LoadingScene.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/5.
//

#ifndef LoadingScene_hpp
#define LoadingScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class LoadingScene : public cocos2d::Scene
{
    
public:
    static cocos2d::Scene *createScene();
    void logic(float dt);
    virtual bool init();
    CREATE_FUNC(LoadingScene);
    void Load();
};


#endif /* LoadingScene_hpp */
