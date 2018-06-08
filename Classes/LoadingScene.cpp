//
//  LoadingScene.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/5.
//

#include "LoadingScene.hpp"
#include "WelcomeScene.hpp"
#include "GameScene.hpp"
#include "Animation.hpp"
USING_NS_CC;

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
}

bool LoadingScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    schedule(schedule_selector(LoadingScene::logic));
    
    return true;
}
void LoadingScene::Load()
{
    Size size = Director::getInstance()->getVisibleSize();
    auto label = Label::createWithTTF("Loading... ", "SohoGothicProMedium.ttf", 54);
    label->setPosition(Point(size.width*0.5, size.height*0.5));
    label->setColor(Color3B::WHITE);
    this->addChild(label,1);
    
    //ManuThing
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("mainmenu_spritesheet_32_2-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("mainmenu_spritesheet_32_1-hd.plist");
    label->setString("Why not waiting");
    SpriteFrameCache::getInstance() ->addSpriteFramesWithFile("mainmenu_spritesheet_32_localized_zh-Hans-hd.plist");
    
    //HeroCache
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_thor-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_fire-hd.plist");
    label->setString("Why not waiting For More?");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_frost-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_frost_2-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_dwarf-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_mage-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_paladin-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_reinforcement-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_robot-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_samurai-hd.plist");
    label->setString("Almost finished");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_samurai_2-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_viking-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_viking_2-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroes_denas-hd.plist");
    
        //AllHeroGet
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite_level6_2-hd.plist");
    label->setString("Finished");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("credits_scene-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ingame_gui-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("common_spritesheet_16_a_2-hd.plist");
    
    
    //label->runAction(DelayTime::create(1));
    //auto scene = WelcomeScene::createScene();
    //Director::getInstance()->replaceScene(scene);
    //Director::getInstance()->runWithScene(scene);
    //Add Create Animation
    loadAnimation animation;
    animation.initAnimation();
    
    
    
}
void LoadingScene::logic(float dt)
{
    Load();
    auto scene = WelcomeScene::createScene();
    //auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
