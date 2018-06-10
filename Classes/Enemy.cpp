//
//  Enemy.cpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/7.
//

#include "Enemy.h"
#include "GameManager.h"
#include <iostream>

void Enemy::createAndSetHpBar()
{
	hpBgSprite = Sprite::create("HPBar_bg.png");

	hpBgSprite->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height));
    hpBar = ProgressTimer::create(Sprite::create("HPBar.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(100*this->HP/this->HPMax);
	hpBar->setPosition(Point (hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2 ));
	hpBgSprite->addChild(hpBar);
	this->addChild(hpBgSprite,0);
}

bool Enemy::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	auto pathss = GameManager::getInstance()->path;
	if (pathss.size() != 0)
	{
		int num1 = rand() % (pathss.size());
		auto paths = pathss[num1];
		int num2 = rand() % (paths.size());
		this->path = paths[num2];
        for(auto &k : path)k.y -=200;
        for(const auto k : path)std::cout << k.x << " " << k.y << std::endl;
	}
	else
	{
		this->path = { Vec2(50,150),Vec2(850, 200),Vec2(860, 360),Vec2(560, 375),Vec2(550, 875) };
	}

	this->pit = path.begin();

	printf("");
	this->HP = baseHP;
	this->side = 1;
	this->range = baseRange;
	this->ATK = baseATK;
	this->HPMax = baseHP;
	this->setSpriteFrame("darkSlayer_0001.png");
    std::srand(90);
	
    //this->runToPoint(Vec2(400,500));
	schedule(schedule_selector(Enemy::update));
	return true;
}

Enemy * Enemy::createEnemy(cocos2d::Point location)
{
	auto enemy = new Enemy();
	if (enemy&&enemy->init())
	{
		enemy->setPosition(location);
		enemy->createAndSetHpBar();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}
Enemy * Enemy::createEnemy()
{
	auto enemy = new Enemy();
	if (enemy&&enemy->init())
	{
		enemy->setPosition((enemy->path)[0]);
		enemy->createAndSetHpBar();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}

void Enemy::update(float dt)
{
	this->SetHpBar();
	if (this->HP < 0) this->setVisible(false);
	auto nit = pit;
    auto ds = this->getPosition() - *pit;
    auto dds = sqrt(ds.x * ds.x + ds.y * ds.y);
	if (dds<0.1 && (++nit) != path.end())
	{
		runToPoint(*(++pit));
	}
}

void Enemy::runToPoint(Vec2 point)
{
	if ((point.x - this->getPositionX()) > 0) {
		this->setFlippedX(false);
	}
	else {
		this->setFlippedX(true);
	}
	runAction(Sequence::create(MoveTo::create(point.getDistance(this->getPosition()) / 70, point),
		NULL));
}
void Enemy::getHurt(int damage)
{
	this->HP -= damage;
}
void Enemy:: SetHpBar()
{
    this->hpBar ->setPercentage(100 * HP / HPMax);
}


