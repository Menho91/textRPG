#ifndef __INVENTORY_H_
#define __INVENTORY_H_

#include "CommonInclude.h"
#include "Item.h"

class Inventory
{
private:
	vector<Item> arr;
public:
	void AddItem(const Item& itm);
	bool RemoveItem(int index);
	void ShowInventory();
};
#endif