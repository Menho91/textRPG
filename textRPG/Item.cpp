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

Item hunting_token("����� ��ǥ", "���͸� ����ϸ� ���� �� �ִ� ��ǥ.");


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

Armor basic_sword("�⺻ ��", "�⺻���� ���̴�.", 0, 0, 1, 1000);
Armor basic_armor("�⺻ ����", "�⺻���� �����̴�.", 5, 0, 0, 1000);


void Inventory::AddItem(const Item& itm, int quant)
{
	for (InventoryItem& i : arr)
	{
		if (i.item.GetName() == itm.GetName())
		{
			i.quantity += quant;
			cout << itm.GetName() << " " << quant << "�� ȹ���߽��ϴ�." << endl << endl;
			return;
		}
	}
	arr.emplace_back(itm, quant);
	cout << itm.GetName() << " " << quant << "�� ȹ���߽��ϴ�." << endl << endl;
}

bool Inventory::RemoveItem(const Item& itm, int quant)
{
	for (InventoryItem& i : arr)
	{
		if (i.item.GetName() == itm.GetName())
		{
			if (i.quantity < quant)
			{
				cout << "������ ������ �����մϴ�." << endl << endl;
				return false;
			}
			else
			{
				i.quantity -= quant;
				cout << itm.GetName() << " " << quant << "�� ��ŭ ����ϴ�. ���� ���� : " << i.quantity << endl << endl;
				return true;
			}
		}
	}
	cout << "������ ���� ���� �������Դϴ�." << endl << endl;
	return false;
}

void Inventory::ShowInventory() const
{
	cout << "[ �κ��丮 ]" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ". ";
		arr[i].item.ShowItemDetailInfo();
		cout << "      ->" << arr[i].quantity << "��" << endl;
	}
	cout << endl;
}