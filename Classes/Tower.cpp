#include "Tower.h"
#include "GameManager.h"
#include "ArrowP.h"
#include <iostream>
using namespace std;

Tower1::Tower1() : TowerBase(HP1,side1,could_a1,ATK1,range1) {}

USING_NS_CC;

Tower1 * Tower1::createTower1(Point point)
{
    auto tw1 = new Tower1();
    if (tw1&&tw1->initTower1())
    {
        tw1->setPosition(point);
        return tw1;
    }
    CC_SAFE_DELETE(tw1);
    return NULL;
}

bool Tower1::initTower1()
{
    if (!Sprite::init())
    {
        return false;
    }
    this->setSpriteFrame("arcane_tower_0017.png");
    return true;
}

bool Tower1::if_attack(Obj* o)
{
    cocos2d::Vec2 ds = o->getPosition() - this->getPosition();
    float dss = sqrt(ds.x * ds.x + ds.y * ds.y);
    if (dss < range)return true;
    else return false;
}

Arrow * Tower1::attack(Obj* o)
{
    auto ar = Magic::creatArrow(o,ATK);
    return ar;
}


Tower2::Tower2() : TowerBase(HP2, side2, could_a2, ATK2, range2) {}

Tower2 * Tower2::createTower2(Point point)
{
    auto tw1 = new Tower2();
    if (tw1&&tw1->initTower2())
    {
        tw1->setPosition(point);
        return tw1;
    }
    CC_SAFE_DELETE(tw1);
    return NULL;
}

bool Tower2::initTower2()
{
    if (!Sprite::init())
    {
        return false;
    }
    this->setSpriteFrame("sorcerer_tower_0001.png");
    return true;
}

bool Tower2::if_attack(Obj* o)
{
    cocos2d::Vec2 ds = o->getPosition() - this->getPosition();
    float dss = sqrt(ds.x * ds.x + ds.y * ds.y);
    if (dss < range)return true;
    else return false;
}

Arrow * Tower2::attack(Obj* o)
{
    auto ar = Light::creatArrow(o, ATK);
    return ar;
}

Tower3::Tower3() : TowerBase(HP3, side3, could_a3, ATK3, range3) {}

Tower3 * Tower3::creatTower3()
{
    return new Tower3;
}

Arrow * Tower3::attack(Obj *)
{
    return nullptr;
}
