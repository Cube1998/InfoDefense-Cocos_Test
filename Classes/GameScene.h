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
#include <fstream>

class GameScene : public cocos2d::Scene
{
	Menu * menu1, *menu2;
	Node node[7];
    bool Game = false;
	int _number = -1;
	int Towers = 0;
	int f = 0;
	int ff = 220;
public:
	static cocos2d::Scene* createScene();
	void BackToWelcomeScene(Ref *pSpender);

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	
	void update(float);
	void fire(float);
	void addEnemy(float);
    void Gameover(float);

	MenuItemSprite * MenuBuild(Point location, int number);
	void setNode();
    void GameOver();
	
	bool CCTouchEnded(Touch*	pTouch, Event* event);
	bool Overlap(Node * pNode, Point touch);

	void menuBuildCallback();
	void menuTower1Callback(cocos2d::Ref* pSender);
	void menuTower2Callback(cocos2d::Ref* pSender);
	void menuTower3Callback(cocos2d::Ref* pSender);
	void menuQuitCallback(cocos2d::Ref* pSender);

    void saveData();
    
    void initUIBtn();
    
    
	CREATE_FUNC(GameScene);
};



#endif /* GameScene_hpp */
