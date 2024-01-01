#include "Item.h"

Item::Item(const string& names, const string& des, int cost)
	: name(names), description(des), value(cost)
{ }


void Item::ShowItemInfo() const
{
	cout << "[" << name << "]" << endl;
}

void Item::ShowItemSalesInfo() const
{
	cout << "[" << name << "] : " << value << "���" << endl;
}

void Item::ShowItemDetailInfo() const
{
	cout << "[" << name << "]" << endl;
	cout << description << endl;
}



Armor::Armor(const string& names, const string& des, int hp, int mp, int atk, int cost)
	: Item(names, des, cost), shiftHP(hp), shiftMP(mp), shiftATK(atk)
{ }

void Armor::ShowItemInfo() const
{
	Item::ShowItemInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}

void Armor::ShowItemSalesInfo() const
{
	Item::ShowItemSalesInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}

void Armor::ShowItemDetailInfo() const
{
	Item::ShowItemDetailInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}

Item hunting_token("����� ��ǥ", "���͸� ����ϸ� ���� �� �ִ� ��ǥ. 10���� ��Ƽ� ���ư���.");
Armor basic_sword("�⺻ ��", "�⺻���� ���̴�.", 0, 0, 1, 10);
Armor basic_armor("�⺻ ����", "�⺻���� �����̴�.", 5, 0, 0, 10);


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
	cout << "[ �κ��丮 ]" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ". ";
		arr[i].item.ShowItemInfo();
		cout << " " << arr[i].quantity << "��" << endl;
	}
	cout << endl;
}