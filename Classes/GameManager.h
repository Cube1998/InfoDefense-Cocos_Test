
//
//  GameManager.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/8.
//

#ifndef GameManager_h
#define GameManager_h

#include <stdio.h>
#include "cocos2d.h"
#include "Enemy.h"
#include "Arrow.h"
#include "Tower.h"
using namespace std;
USING_NS_CC;
class GameManager : public Node
{
public:
	static GameManager* getInstance();
	Vector<Enemy*> enemyVector;
    Vector<Arrow *> arrowVector;
    Vector<TowerBase *>towerVector;

    
    vector<vector<vector<Vec2 >>>  path;
	static void deleteThis();
    
    void TowersFire();
    void enemyUpdate();
    void ArrowUpdate();
private:
	static GameManager * instance;
};


#endif /* GameManager_hpp */
