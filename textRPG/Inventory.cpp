#include "Inventory.h"

void Inventory::AddItem(const Item& itm, int quant)
{
	for (InventoryItem& i : arr)
	{
		if (i.item.GetName() == itm.GetName())
		{
			i.quantity += quant;
			return;
		}
	}
	arr.emplace_back(itm, quant);
}

bool Inventory::RemoveItem(int index)
{
	if (index >= arr.size())
	{
		return false;
	}
	arr[index].item.ShowItemInfo();
	arr.erase(arr.begin() + index);
	return true;
}

void Inventory::ShowInventory()
{
	cout << "[ 인벤토리 ]" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ". ";
		arr[i].item.ShowItemInfo();
		cout << " " << arr[i].quantity << "개" << endl;
	}
	cout << endl;
}