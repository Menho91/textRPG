#include "Inventory.h"

Inventory::Inventory()
	: itemCount(0)
{ }

bool Inventory::AddItem(Item itm)
{
	if (itemCount < INVENTORY_SIZE)
	{
		arr[itemCount] = itm;
	}
}