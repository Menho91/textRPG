#ifndef __ITEM_H_
#define __ITEM_H_

#include "CommonInclude.h"

class Item
{
private:
	string name;
	string description;
public:
	Item(string& names = NULL, string& des = NULL);
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
	Armor(string& names, string& des, int hp = 0, int mp = 0, int atk = 0);
	virtual void ShowItemInfo();
	virtual void ShowItemDetailInfo();
};
#endif