//
//  WelcomeScene.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/1.
//

#ifndef WelcomeScene_hpp
#define WelcomeScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class WelcomeScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();


	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(WelcomeScene);
	void initBackGround();
	void initLogo();
	void initButton_start();
	void initLogoAnimation();
	void initButton_startAnimation();

	void initMenu_save();

	void savemenuCloseCallback(cocos2d::Ref* pSender);

	void setSaveMenuInVisible();
	void setSaveMenuVisible();

	void init_creditBtn();
	void initSoundButton();
	void init_creditBtn_startAnimation();
	void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);

private:
	Size visibleSize;
	Point point_Logo;
	Sprite *sprite_Logo;
	Sprite *button_Start;
	Sprite *button_credit;
	Sprite *menu_Save;
	Point point_Menu_Save;
	MenuItemSprite *button_Menu_Save_Close;
	Point point_Button_Menu_Save_Close;
	void onEnterTransitionDidFinish();


};


#endif /* WelcomeScene_hpp */
