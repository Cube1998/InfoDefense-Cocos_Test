//
//  GameScene.cpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/4.
//

#include "GameScene.h"
#include "Hero.h"
#include "Obj.h"
#include "WelcomeScene.h"
#include "Fire.h"
#include "Thor.h"
#include "EnemyBase.h"
#include "Tower.h"
#include "Arrow.h"
#include "Enemy.h"
#include <vector>
#include "GameManager.h"
#include <iostream>

USING_NS_CC;
using namespace std;
cocos2d::Scene* GameScene::createScene()
{
	return GameScene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite *map = Sprite::createWithSpriteFrameName("Stage_6.png");
	map->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(map, -1);

	//Add Characters

	tw = Tower1::createTower1(Vec2(600, 300));
	this->addChild(tw, 5);
	tws.push_back(tw);

	//Fire *fire = Fire::createFire(Vec2(496.5547*1.15, 36.352*1.20+50));
	//addChild(fire, 4);

    Thor *thor = Thor::createThor(Vec2(visibleSize.width / 2, visibleSize.height / 2) + Vec2(200, 50));
    addChild(thor, 4);
    
	auto enemy = Enemy::createEnemy(Vec2(visibleSize.width / 2, visibleSize.height / 2) + Vec2(0, 50));
	GameManager::getInstance()->enemyVector.pushBack(enemy);
	ems.push_back(enemy);

	this->addChild(enemy, 1);

	//EnemyBase *enemy1 = new EnemyBase();
	//enemy1->setPic("darkSlayer_0001.png");
	//this->addChild(enemy1,3);

    auto tmp = GameManager::getInstance()->path;
    for(int i = 0;i<tmp.size();i++)
        for(int j = 0 ;j<tmp.at(i).size();j++)
            for(int k = 0;k<tmp.at(i).at(j).size();k++)
                cout<<tmp.at(i).at(j).at(k).x<<"  "<<tmp.at(i).at(j).at(k).y<<endl;

	//characters created

	auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0001.png");
	//sprite1->setScale(0.3);

	auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_0002.png");
	//sprite2->setScale(0.3);

	auto item = MenuItemSprite::create(sprite1, sprite2, CC_CALLBACK_1(GameScene::BackToWelcomeScene, this));
	//auto item = MenuItemSprite::create(sprite1,sprite2,CC_CALLBACK_1(GameScene::menuCloseCallback,this));
	item->setAnchorPoint(Vec2::ZERO);
	item->setPosition(Vec2::ZERO);
	Menu *menu1 = Menu::create(item, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);

	this->scheduleUpdate();

	this->schedule(schedule_selector(GameScene::fire), 1.0f);

	return true;
}
void GameScene::BackToWelcomeScene(Ref *pSpender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
}
void GameScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}

void GameScene::update(float)
{
	for (const auto em : ems)if (em->getHP()>0)em->update(5);
	else (removeChild(em));

	std::vector<Arrow *>::iterator dit;
	int k = 0;
	for (auto g = ars.begin(); g != ars.end(); ++g)
	{
		if ((*g)->getHP()>0 && (*g)->getTarget() != nullptr)(*g)->update(0);
		else
		{
			dit = g;
			++k;
		}
	}
	if (k)ars.erase(dit);
}

void GameScene::fire(float)
{
	for (const auto & k : tws)for (const auto em : ems)
		if (k->if_attack(em) && em->getHP()>0)
		{
			auto ar1 = tw->attack(em);
			ar1->setSpriteFrame("arcanehit_0011.png");
			ar1->setPosition(k->getPosition());
			this->addChild(ar1, 4);
			ars.push_back(ar1);
		}
}
