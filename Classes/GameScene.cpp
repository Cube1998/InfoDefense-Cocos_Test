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

	addChild(GameManager::getInstance());
    Fire *fire = Fire::createFire(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    addChild(fire, 5);
    GameManager::getInstance()->hero = fire;
    ifstream readdata ;
    readdata.open("/Users/cube.z/Test0/save4.dat",ios::binary|ios::in);
    if(readdata.is_open())
    {
        //GameManager::getInstance()->cleanup();
        int killEnemy;
        readdata.read((char*)&killEnemy,sizeof(int));
        int EnemyNum = 0;
        readdata.read((char*)&EnemyNum,sizeof(int));
        for(int i=0;i<EnemyNum;i++)
        {
            Vec2 * tmp = new Vec2;
            readdata.read((char*)tmp,sizeof(Vec2));
            GameManager::getInstance()->addEnemyByPosition(*tmp);
        }
    }
    
    
    for (const auto &em : GameManager::getInstance()-> enemyVector)if (em->getHP()>0)
    {
        em->setSpriteFrame("darkSlayer_0001.png");
        //em->setTarget()
        //this->addChild(em);
    
    }

	
	

	//characters created

	auto spritemoney = Sprite::createWithSpriteFrameName("backPack_icons_0006.png");
	spritemoney->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	spritemoney->setPosition(Vec2(920, 600));
	spritemoney->setScale(0.8, 0.8);
	this->addChild(spritemoney,2 );
    
    auto spriteHp = Sprite::createWithSpriteFrameName("backPack_icons_0005.png");
    spriteHp->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    spriteHp->setPosition(Vec2(370, 600));
    spriteHp->setScale(0.8, 0.8);
    this->addChild(spriteHp,2 );
    
	auto spriteScore = Sprite::create("inaps_gemParticle_0001-hd.png");
	spriteScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	spriteScore->setPosition(Vec2(740, 600));
	this->addChild(spriteScore, 2);

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
	this->addChild(menu1, 20);

	this->scheduleUpdate();

	this->schedule(schedule_selector(GameScene::fire), 0.6f);

	this->schedule(schedule_selector(GameScene::addEnemy), 0.01);
    

	setNode();

	auto myMouseListener = EventListenerTouchOneByOne::create();
	myMouseListener->onTouchBegan = [&](Touch* touch, Event* event) {
		if (CCTouchEnded(touch, event)) {
			menuBuildCallback();
		}
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);

	return true;
}

void GameScene::BackToWelcomeScene(Ref *pSpender)
{
    unscheduleAllCallbacks();
     saveData();
	this->removeAllChildrenWithCleanup(1);
    
	GameManager::getInstance()->deleteThis();
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
}
void GameScene::menuCloseCallback(Ref* pSender)
{
    
}

void GameScene::Gameover(float){
    this->removeAllChildrenWithCleanup(1);
    GameManager::getInstance()->deleteThis();
    Director::getInstance()->replaceScene(WelcomeScene::createScene());
}

void GameScene::GameOver()
{
    for(int i = 0;i!=800000000;++i)
    {
        sin(56*76);
    }
    this->removeAllChildrenWithCleanup(1);
    GameManager::getInstance()->deleteThis();
    Towers = 0;
    Director::getInstance()->replaceScene(WelcomeScene::createScene());
}

void GameScene::update(float)
{
    if(Game){
        GameOver();
    }
    if(GameManager::getEscapenemy() <= 0){
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Label * Gameover = Label::createWithTTF("Game Over !", "SohoGothicProMedium.ttf", 28);
        Gameover->setScale(2, 2);
        Gameover->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        Gameover->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        Gameover->setColor(Color3B::ORANGE);
        this->addChild(Gameover, 30);
        Game = true;
        
    }
    
	this->removeChildByTag(666);
	this->removeChildByTag(888);
    this->removeChildByTag(999);
	GameManager::getInstance()->ArrowUpdate();
	GameManager::getInstance()->enemyUpdate();

	int money = 400 + GameManager::getKillenemy() * 20 - Towers;
	int Scores = GameManager::getKillenemy() * 100;

	Label * Amtmoney = Label::createWithTTF("", "SohoGothicProMedium.ttf", 28);
	Amtmoney->setScale(1.2, 1.2);
	Amtmoney->setTag(666);
	Amtmoney->setPosition(Vec2(1010, 600));
	Amtmoney->setColor(Color3B::YELLOW);
	this->addChild(Amtmoney, 3);
	Amtmoney->setString(StringUtils::format("%d", money));

	Label * AmtScores = Label::createWithTTF("", "SohoGothicProMedium.ttf", 28);
	AmtScores->setScale(1.2, 1.2);
	AmtScores->setTag(888);
	AmtScores->setPosition(Vec2(820, 600));
	AmtScores->setColor(Color3B::BLUE);
	this->addChild(AmtScores, 3);
	AmtScores->setString(StringUtils::format("%d", Scores));
    
    Label * AmtHp = Label::createWithTTF("", "SohoGothicProMedium.ttf", 28);
    AmtHp->setScale(1.2, 1.2);
    AmtHp->setTag(999);
    AmtHp->setPosition(Vec2(440, 600));
    AmtHp->setColor(Color3B::RED);
    this->addChild(AmtHp, 3);
    AmtHp->setString(StringUtils::format("%d", GameManager::getEscapenemy()));
}

void GameScene::fire(float)
{
	GameManager::getInstance()->TowersFire();
}

void GameScene::addEnemy(float)
{
	++f;
	if (f == ff)
	{
		GameManager::getInstance()->addEnemy();
		if (ff > 80)ff = ----ff;
        if (ff <= 100&&ff>50)ff = --ff;
	}
	f %= ff;
}


void GameScene::setNode()
{
	int i = 0;
	for (i; i < 7; i++)
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
		menu->setAnchorPoint(Vec2(0.5, 0.5));
		menu->setScale(0.7, 0.7);
		menu->setPosition(Vec2(location.x + 20, location.y + 30));
		return menu;
	}
	else if (number == 2) {
		auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0006.png");
		auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0006.png");
		auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuTower1Callback, this));
		menu->setAnchorPoint(Vec2(0.5, 0.5));
		menu->setScale(0.5, 0.5);
		menu->setPosition(Vec2(location.x - 28, location.y - 18));
		return menu;
	}
	else if (number == 3) {
		auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0011.png");
		auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0011.png");
		auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuTower2Callback, this));
		menu->setAnchorPoint(Vec2(0.5, 0.5));
		menu->setScale(0.5, 0.5);
		menu->setPosition(Vec2(location.x + 20 , location.y + 82));
		return menu;
	}
	else if (number == 4) {
		auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0013.png");
		auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_disabled_0013.png");
		auto menu = MenuItemSprite::create(sprite2, sprite1, CC_CALLBACK_1(GameScene::menuTower3Callback, this));
		menu->setAnchorPoint(Vec2(0.5, 0.5));
		menu->setScale(0.5, 0.5);
		menu->setPosition(Vec2(location.x + 70, location.y - 17));
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
	this->addChild(menu1, 20);

	menu2 = Menu::create(Quit, NULL);
	menu2->setAnchorPoint(Vec2::ZERO);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 0);
}


void GameScene::menuTower1Callback(cocos2d::Ref * pSender)
{

	if (400 + GameManager::getKillenemy() * 20 - Towers - 100>= 0) {
		Towers += 100;
		auto tw = Tower1::createTower1(Vec2(node[_number].getPositionX(), node[_number].getPositionY() + 35));
		tw->setAnchorPoint(Vec2(0.5, 0.5));
		this->addChild(tw, 5);
		GameManager::getInstance()->towerVector.pushBack(tw);
		menu1->removeAllChildren();
		menu2->removeAllChildren();
		node[_number].setPosition(Vec2::ZERO);
		node[_number].setContentSize(Size::ZERO);
	}
	else {
		menu1->removeAllChildren();
		menu2->removeAllChildren();
	}

}

void GameScene::menuTower2Callback(cocos2d::Ref * pSender)
{

	if (400 + GameManager::getKillenemy() * 20 - Towers - 200>= 0) {
		Towers += 200;
		auto tw2 = Tower2::createTower2(Vec2(node[_number].getPositionX(), node[_number].getPositionY() + 35));
		tw2->setAnchorPoint(Vec2(0.5, 0.5));
		this->addChild(tw2, 5);
		GameManager::getInstance()->towerVector.pushBack(tw2);
		menu1->removeAllChildren();
		menu2->removeAllChildren();
		node[_number].setPosition(Vec2::ZERO);
		node[_number].setContentSize(Size::ZERO);
	}
	else {
		menu1->removeAllChildren();
		menu2->removeAllChildren();
	}

}

void GameScene::menuTower3Callback(cocos2d::Ref * pSender)
{

	if (400 + GameManager::getKillenemy() * 20 - Towers - 300>= 0) {
		Towers += 300;
		auto tw3 = Tower3::createTower3(Vec2(node[_number].getPositionX(), node[_number].getPositionY() + 35));
		tw3->setAnchorPoint(Vec2(0.5, 0.5));
		this->addChild(tw3, 5);
		GameManager::getInstance()->towerVector.pushBack(tw3);
		menu1->removeAllChildren();
		menu2->removeAllChildren();
		node[_number].setPosition(Vec2::ZERO);
		node[_number].setContentSize(Size::ZERO);
	}
	else
	{
		menu1->removeAllChildren();
		menu2->removeAllChildren();
	}
}

void GameScene::menuQuitCallback(cocos2d::Ref * pSender)
{
	menu1->removeAllChildren();
	menu2->removeAllChildren();
}
void GameScene::saveData()
{
    ofstream saveout;
    saveout.open("/Users/cube.z/Test0/save4.dat",ios::out|ios::binary|ios::trunc);
    auto tmp =  Vec2(0,0);
    auto enemyVector = GameManager::getInstance()->enemyVector;
    int killenemy =GameManager::getInstance()->getKillenemy();
    saveout.write((char*)&killenemy,sizeof(int));
    int size_Enemy = (int)enemyVector.size();
    saveout.write((char*)&size_Enemy,sizeof(int));
    for(int i = 0;i<size_Enemy;i++ )
    {
        tmp = enemyVector.at(i)->getPosition();
        saveout.write((char*)&tmp,sizeof(Vec2));
    }
    saveout.close();
    
}
