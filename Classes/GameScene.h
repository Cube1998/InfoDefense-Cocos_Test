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
    Menu * menu1, * menu2;
    Node node[7];
	///std::vector<EnemyBase *> ems;
	//std::vector<Arrow *> ars;
	//std::vector<TowerBase *> tws;
    int _number = -1;

public:
	static cocos2d::Scene* createScene();
	void BackToWelcomeScene(Ref *pSpender);
    void setNode();
    MenuItemSprite * MenuBuild(Point location, int number);

    bool CCTouchEnded(Touch*    pTouch, Event* event);
    bool Overlap(Node * pNode, Point touch);

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
    void menuBuildCallback();
    void menuTower1Callback(cocos2d::Ref* pSender);
    void menuTower2Callback(cocos2d::Ref* pSender);
    void menuTower3Callback(cocos2d::Ref* pSender);
    void menuQuitCallback(cocos2d::Ref* pSender);
    void createEnemy(float dt);
	void update(float);
	void fire(float);
	CREATE_FUNC(GameScene);
};



#endif /* GameScene_hpp */
