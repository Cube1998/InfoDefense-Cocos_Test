//
//  GameManager.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/8.
//

#include "GameManager.hpp"


GameManager* GameManager::instance;
GameManager* GameManager::getInstance()
{
    if (instance == NULL)
        instance = new GameManager();
    return instance;
}
void GameManager::deleteThis()
{
    instance->enemyVector.clear();
    
}
