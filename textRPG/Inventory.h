#ifndef __INVENTORY_H_
#define __INVENTORY_H_

#include "CommonInclude.h"
#include "Item.h"

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