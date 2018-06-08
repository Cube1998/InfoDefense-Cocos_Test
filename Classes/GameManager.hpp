//
//  GameManager.hpp
//  Test0
//
//  Created by 张大方 on 2018/6/8.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Enemy.hpp"

class GameManager
{
public:
    static GameManager* getInstance();
    Vector<Enemy*> enemyVector;
    static void deleteThis();
private:
    static GameManager * instance;
};


#endif /* GameManager_hpp */
