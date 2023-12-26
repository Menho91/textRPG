#ifndef __ITEM_H_
#define __ITEM_H_

#include "CommonInclude.h"

class Item
{
private:
	string name;
	string description;
public:
	Item(const string& names = NULL, const string& des = NULL);
	const string& GetName() const;
	virtual void ShowItemInfo() const;
	virtual void ShowItemDetailInfo() const;
};

class Armor : public Item
{
private:
	int shiftHP;
	int shiftMP;
	int shiftATK;
public:
	Armor(const string& names, const string& des, int hp = 0, int mp = 0, int atk = 0);
	virtual void ShowItemInfo()const ;
	virtual void ShowItemDetailInfo() const;
};


extern Item hunting_token;
extern Armor basic_sword;
extern Armor basic_armor;
#endif