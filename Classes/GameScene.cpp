//
//  GameScene.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/4.
//

#include "GameScene.hpp"
#include "Hero.hpp"
#include "WelcomeScene.hpp"
#include "Fire.hpp"

#include "GameManager.hpp"
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
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()-> getVisibleSize();
    
    Sprite *map = Sprite::createWithSpriteFrameName("Stage_6.png");
    map->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    map->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(map,-1);
    
   //Add Characters
    
    Fire *fire = Fire::createFire(Vec2(visibleSize.width/2 , visibleSize.height/2 ));
    addChild(fire,5);
    
    
    auto enemy = Enemy::createEnemy(Vec2(visibleSize.width/2 , visibleSize.height/2 )+Vec2(-200,50));
    GameManager::getInstance()->enemyVector.pushBack(enemy);
    this->addChild(enemy,3);
    
    //EnemyBase *enemy1 = new EnemyBase();
    //enemy1->setPic("darkSlayer_0001.png");
    //this->addChild(enemy1,3);
    
    
    //characters created
    
    auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0001.png");
    //sprite1->setScale(0.3);
    
    auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_0002.png");
    //sprite2->setScale(0.3);
    
    auto item = MenuItemSprite::create(sprite1,sprite2,CC_CALLBACK_1(GameScene::BackToWelcomeScene,this));
    //auto item = MenuItemSprite::create(sprite1,sprite2,CC_CALLBACK_1(GameScene::menuCloseCallback,this));
    item->setAnchorPoint(Vec2::ZERO);
    item->setPosition(Vec2::ZERO);
    Menu *menu1 = Menu::create(item,NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1,1);
    
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
