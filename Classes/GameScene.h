//
//  GameScene.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/4.
//

#ifndef GameScene_h
#define GameScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "Tower.h"
#include "Arrow.h"
#include "EnemyBase.h"
#include "Enemy.h"
#include <vector>
#include "Fire.h"
#include "GameManager.h"
#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
private:
	//EnemyBase * em;
	Tower1 * tw;
	std::vector<EnemyBase *> ems;
	std::vector<Arrow *> ars;
	std::vector<TowerBase *> tws;

public:
	static cocos2d::Scene* createScene();
	void BackToWelcomeScene(Ref *pSpender);

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	
	void update(float);
	void fire(float);
	CREATE_FUNC(GameScene);
};



#endif /* GameScene_hpp */
