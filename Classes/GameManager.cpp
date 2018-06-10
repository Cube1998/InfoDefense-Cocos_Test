//
//  GameManager.cpp
//  Test0
//
//  Created by ÕÅ´ó·½ on 2018/6/8.
//

#include "GameManager.h"

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
	instance->arrowVector.clear();
	instance->towerVector.clear();
	instance->path.clear();
}

void GameManager::TowersFire()
{
	for (const auto & tw : towerVector)
	{
		auto em = enemyVector.end();
		double minDistance = 10000000;
		for (auto it = enemyVector.begin(); it != enemyVector.end(); ++it)
		{
			Vec2 ds = (*it)->getPosition() - tw->getPosition();
			auto distance = sqrt(ds.x * ds.x + ds.y * ds.y);
			if (distance < minDistance&& (*it)->getHP() > 0)
			{
				minDistance = distance;
				em = it;
			}
		}
		if (em!= enemyVector.end() && minDistance<1000000 && tw->if_attack(*em) && (*em)->getHP() > 0)
		{
			auto ar1 = tw->attack(*em);
			ar1->setPosition(tw->getPosition()+ Vec2(-30,0));
			auto pr = this->getParent();
			pr->addChild(ar1, 4);
			arrowVector.pushBack(ar1);
		}
	}
}

void GameManager::enemyUpdate()
{
	for (const auto &em : enemyVector)if (em->getHP()>0)em->update(5);
	else
	{
		auto pr = this->getParent();
		pr->removeChild(em);
	}
	Vector<EnemyBase *>::iterator it_to_erase;
	unsigned useless;
	do
	{
		useless = 0;
		for (auto it = enemyVector.begin(); it != enemyVector.end(); ++it)
		{
			if ((*it)->getHP() > 0)(*it)->update(0);
			else
			{
				it_to_erase = it;
				++useless;
			}
		}
		if (useless)
		{
			enemyVector.erase(it_to_erase);
		}
	} while (useless);
}

void GameManager::ArrowUpdate()
{
	Vector<Arrow *>::iterator it_to_erase;
	unsigned useless;
	do
	{
		useless = 0;
		for (auto it = arrowVector.begin(); it != arrowVector.end(); ++it)
		{
			if ((*it)->getHP()>0 && (*it)->getTarget() != nullptr)(*it)->update(0);
			else
			{
				it_to_erase = it;
				++useless;
			}
		}
		if (useless)
		{
			arrowVector.erase(it_to_erase);
		}
	} while (useless);
}