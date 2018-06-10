
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
#include <vector>


class GameManager : public Node
{
public:
	static GameManager* getInstance();

	Vector<EnemyBase *> enemyVector;
	Vector<Arrow *> arrowVector;
	Vector<TowerBase *>towerVector;
	std::vector<std::vector<std::vector<Vec2 >>>  path;


	void TowersFire();
	void enemyUpdate();
	void ArrowUpdate();

	static void deleteThis();
private:
	static GameManager * instance;
};


#endif /* GameManager_hpp */
