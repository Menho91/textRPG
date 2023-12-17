#ifndef __ITEM_H_
#define __ITEM_H_

#include "CommonInclude.h"

class Item
{
private:
	const string name;
	const string description;
public:
	Item(const string& names = NULL, const string& des = NULL);
	virtual void ShowItemInfo();
	virtual void ShowItemDetailInfo();
};

class Armor : public Item
{
private:
	int shiftHP;
	int shiftMP;
	int shiftATK;
public:
	Armor(const string& names, const string& des, int hp = 0, int mp = 0, int atk = 0);
	virtual void ShowItemInfo();
	virtual void ShowItemDetailInfo();
};
#endif