#include "Inventory.h"

void Inventory::AddItem(const Item& itm)
{
	arr.push_back(itm);
}

bool Inventory::RemoveItem(int index)
{
	if (index >= arr.size())
	{
		return false;
	}
	arr[index].ShowItemInfo();
	arr.erase(arr.begin() + index);
	return true;
}

void Inventory::ShowInventory()
{
	cout << "[ 인벤토리 ]" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ". ";
		arr[i].ShowItemInfo();
	}
	cout << endl;
}