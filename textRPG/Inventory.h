#ifndef __INVENTORY_H_
#define __INVENTORY_H_

#include "CommonInclude.h"
#include "Item.h"

const int INVENTORY_SIZE = 10;

class Inventory
{
private:
	Item arr[INVENTORY_SIZE];
	int itemCount;
public:
	Inventory();
	bool AddItem(Item itm);
	void ShowInventory();
};
#endif