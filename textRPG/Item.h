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
	const string& GetName() const { return name; }
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


struct InventoryItem
{
	Item item;
	int quantity;

	InventoryItem(const Item& itm, int quant)
		: item(itm), quantity(quant)
	{ }
};

class Inventory
{
private:
	vector<InventoryItem> arr;
public:
	void AddItem(const Item& itm, int quant = 1);
	bool RemoveItem(int index);
	void ShowInventory();
};
#endif