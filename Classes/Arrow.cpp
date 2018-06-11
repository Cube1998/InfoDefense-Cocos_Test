 #include "Arrow.h"

USING_NS_CC;

Arrow::Arrow(Obj *ta, int atk) : target(ta),ATK(atk) {}


void Arrow::setVelocity(const cocos2d::Vec2 &v)
{
	this->velocity = v;
}

cocos2d::Vec2 Arrow::getVelocity() const
{
	return this->velocity;
}

void Arrow::update(float dt)
{
	if (target == nullptr || target->getHP() <= 0 || this->HP < 0)
	{
		this->HP = -10;
		auto pr = getParent();
		pr->removeChild(this);
		return;
	}
	if (target!=nullptr && target->getHP() > 0)
	{
		
		Vec2 ds = target->getPosition()+ Vec2(-30,-5) - this->getPosition();

		float dl = sqrt(ds.x*ds.x + ds.y*ds.y);
		if (dl < 10 || target->getHP() < 0)
		{
			target->subHP(this->ATK);
			target = nullptr;
			this->HP = -10;
			auto k = getParent();
			k->removeChild(this);
			return;
		}

		velocity = ds / dl;

		if(dl>speed)this->setPosition(Vec2(this->getPosition() + velocity * this->speed));
		else this->setPosition(Vec2(this->getPosition() + ds));
	}
}

void Arrow::setTarget(Obj *p)
{
	target = p;
}
