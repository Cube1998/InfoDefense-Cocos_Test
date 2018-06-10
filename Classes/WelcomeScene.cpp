//
//  WelcomeScene.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/1.
//

#include "WelcomeScene.h"
#include <iostream>
#include "Information.h"
#include "SlotMenu.h"
#include "LoadingScene.h"
#include "GameScene.h"
USING_NS_CC;
using namespace std;
Scene* WelcomeScene::createScene()
{
	return WelcomeScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool WelcomeScene::init() {
	if (!Scene::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//导入背景文件
	//SpriteFrameCache * framecacha  = SpriteFrameCache::getInstance();

	/*
	//生成背景

	auto sprite_background = Sprite::createWithSpriteFrameName("mainmenu_bg.png");
	sprite_background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	this->addChild(sprite_background,-1);


	//生成logo
	Vec2 logo_point;
	Sprite * MainLogo = Sprite::createWithSpriteFrameName("logo.png");

	logo_point.set(visibleSize.width/2,visibleSize.height/2+100);

	MainLogo->setAnchorPoint(Vec2(0.5,0.5));
	MainLogo->setPosition(logo_point);
	MainLogo->setScale(0.2, 0.2);


	this->addChild(MainLogo,0);

	//从资源中加图片，设置位置
	auto sprite = Sprite::create();
	sprite->setPosition(logo_point);
	this->addChild(sprite,10);
	//生成帧动画
	Animation *animate = Animation::create();
	SpriteFrame* frame = nullptr;
	__String *framename = __String::create("");
	for(int No=1;No<=21;No++)
	{
	framename = __String::createWithFormat("logo_brillo_00%02d.png",No);
	std::cout<<framename->getCString()<<std::endl;

	frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename->getCString());
	if(frame!=nullptr){
	animate->addSpriteFrame(frame);
	std::cout<<"animate->addSpriteFrame(frame);"<<std::endl;
	}
	}
	animate->setDelayPerUnit(0.1f);
	//播放动画
	//sprite->runAction(RepeatForever::create(Animate::create(animate)));
	FiniteTimeAction *ac1 = (FiniteTimeAction *)MainLogo->runAction((Animate::create(animate)));
	FiniteTimeAction *ac0 = (FiniteTimeAction *)MainLogo->runAction(ScaleTo::create(1, 1));
	MainLogo->runAction(Sequence::create(ac0,ac1, NULL));

	*/
	initBackGround();
	initLogo();
	initMenu_save();
	initButton_start();
	init_creditBtn();
    auto sprite1 = Sprite::createWithSpriteFrameName("main_icons_0001.png");
    auto sprite2 = Sprite::createWithSpriteFrameName("main_icons_0002.png");
    auto item = MenuItemSprite::create(sprite1,sprite2,CC_CALLBACK_1(WelcomeScene::menuCloseCallback,this));
    item->setAnchorPoint(Vec2::ZERO);
    item->setPosition(Vec2::ZERO);
    Menu *menu1 = Menu::create(item, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);


	return true;
}
void WelcomeScene::onEnterTransitionDidFinish()
{
	auto Sequence = Sequence::create(ScaleTo::create(0.5f, 1.5f, 1.5f),
		ScaleTo::create(0.2f, 1.0f, 1.0f),
		CallFuncN::create(CC_CALLBACK_0(WelcomeScene::initLogoAnimation, this)),
		CallFunc::create(CC_CALLBACK_0(WelcomeScene::initButton_startAnimation, this)),
		CallFuncN::create(CC_CALLBACK_0(WelcomeScene::init_creditBtn_startAnimation, this)),
		NULL);
	sprite_Logo->runAction(Sequence);
}
void WelcomeScene::menuCloseCallback(Ref* pSender)
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
void WelcomeScene::initBackGround()
{

	auto sprite_background = Sprite::createWithSpriteFrameName("mainmenu_bg.png");
	sprite_background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite_background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	cout << visibleSize.width / 2 << " " << visibleSize.height / 2;
	this->addChild(sprite_background, -1);
}

void WelcomeScene::initLogo()
{

	sprite_Logo = Sprite::createWithSpriteFrameName("logo.png");
	sprite_Logo->setAnchorPoint(Vec2(0.5, 0.5));
	point_Logo.x = visibleSize.width / 2;
	point_Logo.y = visibleSize.height / 2 + 100;
	sprite_Logo->setScale(0.2f);
	sprite_Logo->setPosition(point_Logo);
	addChild(sprite_Logo, 9);
}
void WelcomeScene::initLogoAnimation()
{

	auto sprite = Sprite::createWithSpriteFrameName("logo_brillo_0001.png");
	sprite->setPosition(point_Logo);
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> aFrames(20);

	for (int len = 1; len <= 21; len++)
	{
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("logo_brillo_00%02d.png", len)->getCString());
		if (frame != nullptr)
			aFrames.pushBack(frame);
	}
	addChild(sprite, 10);
	auto animation = Animation::createWithSpriteFrames(aFrames, 0.1f);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
}
void WelcomeScene::initButton_start()
{

	button_Start = Sprite::createWithSpriteFrameName("menu_startchain_0001.png");

	button_Start->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_Start->setVisible(false);
	button_Start->setPosition(point_Logo.x, point_Logo.y);
	addChild(button_Start, 1);

	auto button_Start_listener = EventListenerTouchOneByOne::create();
	button_Start_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0 + 40, 0 + 30, size.width - 80, size.height / 3 + 15);
		if (rect.containsPoint(locationInNode) && target->isVisible())
		{
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_startchain_0002.png"));
			return true;
		}
		return false;
	};
	button_Start_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		static_cast<Sprite*>(event->getCurrentTarget())->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_startchain_0001.png"));

		button_Start->runAction(Sequence::create(
			DelayTime::create(0.3f),
			MoveTo::create(0.3f, Point(point_Logo.x, point_Logo.y)), NULL));
		button_Start->setVisible(false);
		Director::getInstance()->replaceScene(GameScene::createScene());
        

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(button_Start_listener, button_Start);
}
void WelcomeScene::initButton_startAnimation()
{
	button_Start->setVisible(true);
	button_Start->runAction(MoveTo::create(0.3f, Point(point_Logo.x, point_Logo.y - 180)));
}
void WelcomeScene::init_creditBtn()
{
	button_credit = Sprite::createWithSpriteFrameName("menu_creditschain_0001.png");
	button_credit->setVisible(false);

	button_credit->setPosition(point_Logo.x, point_Logo.y - 180);

	addChild(button_credit, 0);

	auto button_credit_listener = EventListenerTouchOneByOne::create();
	button_credit_listener->onTouchBegan = [&](Touch* touch, Event* event) {

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertTouchToNodeSpace(touch);

		Size size = target->getContentSize();
		Rect rect = Rect(0 + 40, 0 + 30, size.width - 80, size.height / 3 + 15);
		if (rect.containsPoint(locationInNode) && target->isVisible())
		{
			//SoundManager::playClickEffect();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_creditschain_0002.png"));
			return true;
		}
		return false;
	};
	button_credit_listener->onTouchEnded = [&](Touch* touch, Event* event) {
		static_cast<Sprite*>(event->getCurrentTarget())->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_creditschain_0001.png"));
		Director::getInstance()->replaceScene(Information::createScene());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(button_credit_listener, button_credit);
}
void WelcomeScene::init_creditBtn_startAnimation()
{
	button_credit->runAction(Sequence::create(
		DelayTime::create(0.3f),
		CallFuncN::create(CC_CALLBACK_0(Sprite::setVisible, button_credit, true)),
		MoveTo::create(0.3f, Point(point_Logo.x, point_Logo.y - 360)), NULL));
}
void WelcomeScene::initMenu_save()
{

	menu_Save = Sprite::createWithSpriteFrameName("mainmenu_saveslot_bg.png");

	point_Menu_Save.x = point_Logo.x;
	point_Menu_Save.y = point_Logo.y - sprite_Logo->getContentSize().height*1.4 / 2;

	menu_Save->setPosition(Point(point_Menu_Save.x, point_Menu_Save.y - 500));

	/*
	auto slot_0 = SlotMenu::createMenu(2);
	slot_0->setPosition(Point(menu_Save->getContentSize().width/2,menu_Save->getContentSize().height/2));
	menu_Save->addChild(slot_0);

	auto slot_1 = SlotMenu::createMenu(1);
	slot_1->setPosition(Point(menu_Save->getContentSize().width/4 -30,menu_Save->getContentSize().height/2));
	menu_Save->addChild(slot_1);

	auto slot_2 = SlotMenu::createMenu(3);
	slot_2->setPosition(Point(menu_Save->getContentSize().width/4*3 +30,menu_Save->getContentSize().height/2));
	menu_Save->addChild(slot_2);
	*/
	addChild(menu_Save, 0);
	button_Menu_Save_Close = MenuItemSprite::create(Sprite::createWithSpriteFrameName("mainmenu_saveslot_close_0001.png"),
		Sprite::createWithSpriteFrameName("mainmenu_saveslot_close_0002.png"),
		CC_CALLBACK_1(WelcomeScene::savemenuCloseCallback, this));

	point_Button_Menu_Save_Close.x = point_Logo.x;
	point_Button_Menu_Save_Close.y = point_Menu_Save.y - menu_Save->getContentSize().height / 2 + button_Menu_Save_Close->getContentSize().height + 2;
	button_Menu_Save_Close->setPosition(Point(point_Button_Menu_Save_Close.x, point_Button_Menu_Save_Close.y - 500));

	auto menu = Menu::create(button_Menu_Save_Close, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 0);
}
void WelcomeScene::savemenuCloseCallback(cocos2d::Ref* pSender)
{
	//SoundManager::playClickEffect();
	setSaveMenuInVisible();
	initButton_startAnimation();
	init_creditBtn_startAnimation();
}
void WelcomeScene::setSaveMenuInVisible()
{

	menu_Save->runAction(MoveBy::create(0.3f, Point(0, -500)));
	button_Menu_Save_Close->runAction(MoveBy::create(0.3f, Point(0, -500)));
}

