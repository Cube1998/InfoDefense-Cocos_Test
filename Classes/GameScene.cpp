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

	//tw = Tower1::createTower1(Vec2(600, 300));
	//this->addChild(tw, 5);
    //GameManager::getInstance()->towerVector.pushBack(tw);

	//Fire *fire = Fire::createFire(Vec2(496.5547*1.15, 36.352*1.20+50));
	//addChild(fire, 1);

    Thor *thor = Thor::createThor(Vec2(visibleSize.width / 2, visibleSize.height / 2) + Vec2(200, 50));
    addChild(thor, 4);
   
    schedule(schedule_selector(GameScene::createEnemy), 3.0f);
	//auto enemy = Enemy::createEnemy();
	//GameManager::getInstance()->enemyVector.pushBack(enemy);


	//this->addChild(enemy, 4);

	//EnemyBase *enemy1 = new EnemyBase();
	//enemy1->setPic("darkSlayer_0001.png");
	//this->addChild(enemy1,3);

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

	this->schedule(schedule_selector(GameScene::fire), 0.1f);
    setNode();
    
    auto myMouseListener = EventListenerTouchOneByOne::create();
    myMouseListener->onTouchBegan = [&](Touch* touch, Event* event) {
        if (CCTouchEnded(touch, event)) {
            menuBuildCallback();
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);

    
    this->addChild(GameManager::getInstance());

	return true;
}
void GameScene::setNode()
{
    // int i = 0;
    for (int i=0; i < 7; i++)
    {
  node[i].setAnchorPoint(Vec2::ZERO);
   node[i].setContentSize(Size(100, 100));
    }
    node[0].setPosition(Vec2(670, 220));
    node[1].setPosition(Vec2(550, 220));
    node[2].setPosition(Vec2(430, 220));
    
    node[3].setPosition(Vec2(270, 410));
    node[4].setPosition(Vec2(400, 410));
    
    node[5].setPosition(Vec2(720, 410));
    node[6].setPosition(Vec2(845, 410));
}
MenuItemSprite * GameScene::MenuBuild(Point location, int number)
{
    if (number == 1) {
        auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0005.png");
        auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0005.png");
        auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuCloseCallback, this));
        menu->setAnchorPoint(Vec2::ZERO);
        menu->setScale(0.7, 0.7);
        menu->setPosition(Vec2(location.x + 20, location.y + 20));
        return menu;
    }
    else if (number == 2){
        auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0006.png");
        auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0006.png");
        auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuTower1Callback, this));
        menu->setAnchorPoint(Vec2::ZERO);
        menu->setScale(0.5, 0.5);
        menu->setPosition(Vec2(location.x-20, location.y - 20));
        return menu;
    }
    else if (number == 3) {
        auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0011.png");
        auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0011.png");
        auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuTower2Callback, this));
        menu->setAnchorPoint(Vec2::ZERO);
        menu->setScale(0.5, 0.5);
        menu->setPosition(Vec2(location.x + 30, location.y + 86));
        return menu;
    }
    else if (number == 4) {
        auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0013.png");
        auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0013.png");
        auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuTower3Callback, this));
        menu->setAnchorPoint(Vec2::ZERO);
        menu->setScale(0.5, 0.5);
        menu->setPosition(Vec2(location.x + 84, location.y - 19));
        return menu;
    }
    else if (number == 0) {
        auto sprite1 = Sprite::createWithSpriteFrameName("Stage_6.png");
        auto menu = MenuItemSprite::create(sprite1, sprite1, CC_CALLBACK_1(GameScene::menuQuitCallback, this));
        menu->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        menu->setPosition(location);
        return menu;
    }
    
    return nullptr;
}
bool GameScene::CCTouchEnded(Touch * pTouch, Event * event)
{
    Point touchLocation = convertTouchToNodeSpace(pTouch);
    for (_number = 0; _number < 7; _number++) {
        if (Overlap(&node[_number], touchLocation))
            return true;
    }
    
    _number = -1;
    return false;
}
bool GameScene::Overlap(Node* pNode, Point touch)
{
    float _x = pNode->getPosition().x, _y = pNode->getPosition().y;
    float _width = pNode->getContentSize().width, _height = pNode->getContentSize().height;
    if (touch.x > _x && touch.x < _x + _width && touch.y > _y && touch.y < _y + _height)
        return true;
    return false;
}
void GameScene::menuBuildCallback()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto Destin = MenuBuild(node[_number].getPosition(), 1);
    
    auto Tower1 = MenuBuild(node[_number].getPosition(), 2);
    auto Tower2 = MenuBuild(node[_number].getPosition(), 3);
    auto Tower3 = MenuBuild(node[_number].getPosition(), 4);
    
    auto Quit = MenuBuild(Vec2(visibleSize.width / 2, visibleSize.height / 2), 0);
    
    menu1 = Menu::create(Destin, Tower1, Tower2, Tower3, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 2);
    
    menu2 = Menu::create(Quit, NULL);
    menu2->setAnchorPoint(Vec2::ZERO);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, 0);
}
void GameScene::menuTower2Callback(cocos2d::Ref * pSender)
{
}

void GameScene::menuTower3Callback(cocos2d::Ref * pSender)
{
}

void GameScene::menuQuitCallback(cocos2d::Ref * pSender)
{
    menu1->removeAllChildren();
    menu2->removeAllChildren();
}


void GameScene::menuTower1Callback(cocos2d::Ref * pSender)
{
    tw = Tower1::createTower1(Vec2(node[_number].getPositionX() -20, node[_number].getPositionY()+5));
    tw->setAnchorPoint(Vec2::ZERO);
    this->addChild(tw, 5);
    GameManager::getInstance()->towerVector.pushBack(tw);
    //tws.push_back(tw);
    menu1->removeAllChildren();
    menu2->removeAllChildren();
    node[_number].setPosition(Vec2::ZERO);
    node[_number].setContentSize(Size::ZERO);
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
    GameManager::getInstance()->ArrowUpdate();
    GameManager::getInstance()->enemyUpdate();
}

void GameScene::fire(float)
{
    GameManager::getInstance()->TowersFire();
}
void GameScene::createEnemy(float dt)
{
    auto enemy = Enemy::createEnemy();
    GameManager::getInstance()->enemyVector.pushBack(enemy);
    this->addChild(enemy,3);
    //GameManager::getInstance()->enemyVector .push_back(enemy);
}
