//
//  GameScene.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/4.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    void BackToWelcomeScene(Ref *pSpender);
    
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(GameScene);
};
    


#endif /* GameScene_hpp */
