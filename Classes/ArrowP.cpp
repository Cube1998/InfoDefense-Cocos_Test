#include "ArrowP.h"
#include "SimpleAudioEngine.h"
Magic::Magic(Obj * ta, int atk) : Arrow(ta, atk) {}

Magic * Magic::creatArrow(Obj * ta, int atk)
{
	auto k = new Magic(ta, atk);
	k->setSpriteFrame("arcanehit_0010.png");
	
	return k;
}

Magic * Magic::creatArrow()
{
	auto k = new Magic();
	k->setSpriteFrame("arcanehit_0010.png");
	return k;
}

Light::Light(Obj * ta, int atk) : Arrow(ta, atk) {}

Light * Light::creatArrow(Obj * ta, int atk)
{
	auto k = new Light(ta, atk);
	k->setSpriteFrame("sorcererbolt_0011.png");
	return k;
}

Light * Light::creatArrow()
{
	auto k = new Light();
	k->setSpriteFrame("sorcererbolt_0011.png");
	return k;
}

Rocket::Rocket(Obj * ta, int atk) : Arrow(ta, atk) {}

Rocket * Rocket::creatArrow(Obj * ta, int atk)
{
	auto k = new Rocket(ta, atk);
	k->setSpriteFrame("burn_big_0006.png");
	return k;
}

Rocket * Rocket::creatArrow()
{
	auto k = new Rocket();
	k->setSpriteFrame("burn_big_0006.png");
	return k;
}
