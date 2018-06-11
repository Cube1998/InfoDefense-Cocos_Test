
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

	Vector<Enemy *> enemyVector;
	Vector<Arrow *> arrowVector;
	Vector<TowerBase *>towerVector;
	std::vector<std::vector<std::vector<Vec2 >>>  path;
    Hero *hero;


	void TowersFire();
	void enemyUpdate();
	void ArrowUpdate();

	static int getKillenemy() {
		return Killenemy;
	}
    static int getEscapenemy(){
        return Escapeenemy;
    }

	void addEnemy();
    void addEnemyByPosition(Vec2 p);

	static void deleteThis();
     int HeroType=0;
private:
	static GameManager * instance;
	static int Killenemy;
    static int Escapeenemy;
};


#endif /* GameManager_hpp */
