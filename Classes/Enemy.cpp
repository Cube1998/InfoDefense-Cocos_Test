//
//  Enemy.cpp
//  Test0
//
//  Created by ÕÅ´ó·½ on 2018/6/7.
//

#include "Enemy.h"
#include "GameManager.h"

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
        auto random1 = new RandomHelper;
		int num1 = random1->random_int(4, 78) % (pathss.size());
		auto paths = pathss[num1];
		int num2 = random1->random_int(4, 78) % (paths.size());
		this->path = paths[num2];
        for(auto &k : path)k = k + Vec2(0,-140);
	}
	else
	{
		std::vector<std::vector<Vec2>> tpaths;
		tpaths.push_back({ Vec2(50,150),Vec2(850, 160),Vec2(860, 360),Vec2(560, 375),Vec2(550, 875) });
		tpaths.push_back({ Vec2(1110,150),Vec2(350, 160),Vec2(360, 360),Vec2(560, 375),Vec2(550, 875) });
		tpaths.push_back({ Vec2(560,-20),Vec2(560, 160),Vec2(360, 160),Vec2(360, 375),Vec2(560, 375),Vec2(550, 875) });
		tpaths.push_back({ Vec2(560,-20),Vec2(560, 160),Vec2(860, 160),Vec2(860, 375),Vec2(560, 375),Vec2(550, 875) });
		this->path = tpaths[rand() % 4];

	}

	this->pit = path.begin();
	this->state = 1;

	
	this->HP = baseHP;
	this->side = 1;
	this->range = baseRange;
	this->ATK = baseATK;
	this->HPMax = baseHP;
	this->setSpriteFrame("darkSlayer_0001.png");
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
	auto dds = sqrt(ds.x*ds.x + ds.y*ds.y);

	auto fireDis = this->getPosition() - this->target->getPosition();
	auto dfireDis = sqrt(fireDis.x * fireDis.x + fireDis.y * fireDis.y);

	if (dfireDis < this->range && target->getHP()>0)
	{
		this->stopAllActions();
		state = 0;
		state2 = 1;
	}
    
	if (dfireDis >= this->range||target->getHP()<=0)
	{
		//stopAllActions();
		state = 1;
	}
	if (dds < 0.01 && (++nit) != path.end() && state)
	{
		runToPoint(*(++pit));
		state2 = 0;
	}
	if (dds > 0.01 && state && state2)
	{
		runToPoint(*(pit));
		state2 = 0;
	}
}

void Enemy::fire()
{
	target->subHP(2);
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
    if(HPMax<=0)setHPMax(300);
    this->hpBar ->setPercentage(100 * HP / HPMax);
}
