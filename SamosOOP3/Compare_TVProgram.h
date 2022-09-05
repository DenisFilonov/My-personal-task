#pragma once
#include "TVProgram.h"

class Compare_TVProgram : public binary_function<TVProgram*, TVProgram*, bool>
{
public:
	bool operator()(const TVProgram* obj1, const TVProgram* obj2) const
	{
		return obj1->getTime() > obj2->getTime();
	}
}; //Это глобальный объект, как переменная, класса objcompare



//atoi(obj1->getISBN().c_str()) < atoi(obj2->getISBN().c_str());