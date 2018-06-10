#pragma once
#ifndef ARROWP_H

#include "Arrow.h"
class Magic : public Arrow
{
public:
	Magic(Obj *ta, int atk);
	Magic() = default;
	static Magic * creatArrow(Obj *ta, int atk);
	static Magic * creatArrow();
};

class Light : public Arrow
{
public:
	Light(Obj *ta, int atk);
	Light() = default;
	static Light * creatArrow(Obj *ta, int atk);
	static Light * creatArrow();
};


#endif // !ARROWP_H
