//
//  Enemy.cpp
//  Test0
//
//  Created by 张大方 on 2018/6/7.
//

#include "Enemy.hpp"
#include "GameManager.hpp"

void Enemy::createAndSetHpBar()
{
    hpBgSprite = Sprite::create("HPBar_bg.png");
    
    hpBgSprite->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height));
    ProgressTimer * hpBar = ProgressTimer::create(Sprite::create("HPBar.png"));
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
    
    this->HP=30;
    this->HPMax= 30;
    this->setSpriteFrame("darkSlayer_0001.png");
    this->runToPoint(Vec2(1000,500));
    GameManager::getInstance()->enemyVector.pushBack(this);
    schedule(schedule_selector(Enemy::update));
    
    return true;
}
Enemy * Enemy::createEnemy(cocos2d::Point location)
{
    auto enemy = new Enemy();
    if(enemy&&enemy->init())
    {
        enemy->setPosition(location);
        //enemy->createAndSetHpBar();
        
        return enemy;
    }
    CC_SAFE_DELETE(enemy);
    return NULL;
}
void Enemy::update(float dt)
{
    this->createAndSetHpBar();
   // if(this->HP<0)this->setVisible(false);
    
}
void Enemy::runToPoint(Vec2 point)
{
    
        if((point.x - this->getPositionX())>0){
            this->setFlippedX(false);
        }else{
            this->setFlippedX(true);
        }
    
        runAction(Sequence::create(MoveTo::create(point.getDistance(this->getPosition())/100,point),
                                   NULL));
    
    
}
void Enemy::getHurt(int damage)
{
    HP-=damage;
}

