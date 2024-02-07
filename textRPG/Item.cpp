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
	cout << "[" << name << "] : " << value << "골드" << endl;
}

void Item::ShowItemDetailInfo() const
{
	cout << "[" << name << "]" << endl;
	cout << description << endl;
}

Item HuntingToken_ITEM("사냥의 증표", "몬스터를 사냥하면 얻을 수 있는 증표.");


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

Armor BasicSword_ARMOR("기본 검", "기본적인 검이다.", 0, 0, 1, 1000);
Armor BasicArmor_ARMOR("기본 갑옷", "기본적인 갑옷이다.", 5, 0, 0, 1000);
Armor StrongSword_ARMOR("강화된 검", "몬스터에게서 나오는 희귀한 광물로 강화한 검이다.", 0, 0, 5, 5000);
Armor StrongArmor_ARMOR("강화된 갑옷", "강한 몬스터의 단단한 가죽으로 강화한 갑옷이다.", 25, 0, 0, 5000);


void Inventory::AddItem(const Item& itm, int quant)
{
	for (InventoryItem& i : arr)
	{
		if (i.item.GetName() == itm.GetName())
		{
			i.quantity += quant;
			cout << itm.GetName() << " " << quant << "개 획득했습니다." << endl << endl;
			return;
		}
	}
	arr.emplace_back(itm, quant);
	cout << itm.GetName() << " " << quant << "개 획득했습니다." << endl << endl;
}

bool Inventory::RemoveItem(const Item& itm, int quant)
{
	for (InventoryItem& i : arr)
	{
		if (i.item.GetName() == itm.GetName())
		{
			if (i.quantity < quant)
			{
				cout << "아이템 개수가 부족합니다." << endl << endl;
				return false;
			}
			else
			{
				i.quantity -= quant;
				cout << itm.GetName() << " " << quant << "개 만큼 줬습니다. 남은 개수 : " << i.quantity << endl << endl;
				return true;
			}
		}
	}
	cout << "가지고 있지 않은 아이템입니다." << endl << endl;
	return false;
}

void Inventory::ShowInventory() const
{
	cout << "[ 인벤토리 ]" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i + 1 << ". ";
		arr[i].item.ShowItemDetailInfo();
		cout << "      ->" << arr[i].quantity << "개" << endl;
	}
	cout << endl;
}