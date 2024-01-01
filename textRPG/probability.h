#ifndef __PROBABILITY_H_
#define __PROBABILITY_H_

#include "CommonInclude.h"
#include <random>

class Probability
{
private:
	mt19937 mt;
	uniform_int_distribution<int> uniformDis;
public:
	Probability() : mt(random_device{}()), uniformDis(1, 100)
	{ }
	int GetRandomNumber()
	{
		return uniformDis(mt);
	}
	bool operator()(int percent)
	{
		if (GetRandomNumber() <= percent)
			return true;
		else
			return false;
	}
	int operator()()
	{
		return (GetRandomNumber() / 5) - 10;
	}
};
#endif