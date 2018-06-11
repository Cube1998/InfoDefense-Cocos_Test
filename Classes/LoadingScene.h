
//
//  LoadingScene.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/5.
//

#ifndef LoadingScene_h
#define LoadingScene_h

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class LoadingScene : public cocos2d::Scene
{

public:
	static cocos2d::Scene *createScene();
	void logic(float dt);
	virtual bool init();
	CREATE_FUNC(LoadingScene);
	void Load();
    void loadPathFromPlist(cocos2d::__String *str);
    void loadMapListFromPlist(cocos2d::__String *str);
    
    
 };


#endif /* LoadingScene_hpp */
