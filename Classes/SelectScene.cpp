//
//  SelectScene.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/11.
//

#include "SelectScene.hpp"


bool SelectScene::init()
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
    //portraits_hero_0006.png
    //auto sprite1 = Sprite::createWithSpriteFrameName("portraits_hero_0006.png");
    //auto hero1 = MenuItemImage::c
    auto sprite1 = Sprite::createWithSpriteFrameName("portraits_hero_0006.png");
    sprite1->setScale(1.5f);
    
    
    auto item1 = MenuItemSprite::create(sprite1,sprite1, CC_CALLBACK_1(SelectScene::Callback1, this));
    item1->setPosition(visibleSize.width/2-200,visibleSize.height/2);
    auto sprite2 = Sprite::createWithSpriteFrameName("portraits_hero_0014.png");
    sprite2->setScale(1.5f);
    
    auto item2 = MenuItemSprite::create(sprite2,sprite2, CC_CALLBACK_1(SelectScene::Callback2, this));
    item2->setPosition(visibleSize.width/2+200,visibleSize.height/2);
    
    
    Menu *menu1 = Menu::create(item1,item2, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 20);
    return true;
}
Scene* SelectScene::createScene()
{
    return SelectScene::create();
    
    
}
void SelectScene::Callback1(cocos2d::Ref *pSender)
{
    GameManager::getInstance()->HeroType=1;
    
    
    Director::getInstance()-> replaceScene(GameScene::createScene());
    
}
void SelectScene::Callback2(cocos2d::Ref *pSender)
{
    GameManager::getInstance()->HeroType=2;
    
    
    Director::getInstance()-> replaceScene(GameScene::createScene());
    
}

