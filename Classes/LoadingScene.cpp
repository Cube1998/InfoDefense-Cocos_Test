//
//  LoadingScene.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/5.
//

#include "LoadingScene.h"
#include "WelcomeScene.h"
#include "GameScene.h"
#include "Animation.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gui_menu_sprite_endless_32-hd.plist");
    
        //AllHeroGet
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite_level6_2-hd.plist");
    label->setString("Finished");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("credits_scene-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ingame_gui-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("common_spritesheet_16_a_2-hd.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("towers-hd.plist");
    
    loadPathFromPlist(__String::create("level6_paths.plist"));
    loadMapListFromPlist(__String::create("level6_astar.plist"));

    
    loadAnimation animation;
    animation.initAnimation();
    for(int i= 0;i<60;i++)
    {
        for(int j=0;j<50;j++)
                //printf("%d ",GameManager::getInstance()->MapList[i][j]);
        printf("\n");
    }
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic( "MusicMainMenu.mp3");
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic( "MusicMap.mp3");
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic( "MusicSuspense.mp3");
    
    
    
}
void LoadingScene::logic(float dt)
{
    Load();
    auto scene = WelcomeScene::createScene();
    //auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
void LoadingScene::loadPathFromPlist(__String *str)
{
    auto plistDic = Dictionary::createWithContentsOfFile(str->getCString());
    
    auto path_array = dynamic_cast<__Array*>(plistDic->objectForKey("paths"));
    
    for(int i = 0;i<path_array->count();i++)
    {
        std::vector<std::vector<Point>> tempPathVector;
        auto path_array2 = dynamic_cast<__Array*>(path_array->getObjectAtIndex(i));
        for(int j = 0;j<path_array2->count();j++)
        {
            std::vector<Point> tempRandomPathVector;
            auto path_array3 = dynamic_cast<__Array*>(path_array2->getObjectAtIndex(j));
            for(int k =0;k<path_array3->count();k++)
            {
                auto tempDic = dynamic_cast<__Dictionary*>(path_array3->getObjectAtIndex(k));
                Point tempPath = Point();
                tempPath.x = dynamic_cast<__String*>(tempDic->objectForKey("x"))->floatValue()*1.15;
                tempPath.y = dynamic_cast<__String*>(tempDic->objectForKey("y"))->floatValue()*1.20;
                tempRandomPathVector.push_back(tempPath);
            }
            tempPathVector.push_back(tempRandomPathVector);
        }
        GameManager::getInstance()->path.push_back(tempPathVector);
    }
}
void LoadingScene::loadMapListFromPlist(cocos2d::__String *str)
{
    auto plistDic = Dictionary::createWithContentsOfFile(str->getCString());
    auto map_array = dynamic_cast<__Array*>(plistDic->objectForKey("grid"));
    for(int i = 0;i<map_array->count();i++)
    {
        auto tempDic = dynamic_cast<__Dictionary*>(map_array->getObjectAtIndex(i));
        
        /*GameManager::getInstance()->MapList[dynamic_cast<__String*>(tempDic->objectForKey("column"))->intValue()][dynamic_cast<__String*>(tempDic->objectForKey("row"))->intValue()] = dynamic_cast<__String*>(tempDic->objectForKey("walkable"))->intValue();*/
    }
}
