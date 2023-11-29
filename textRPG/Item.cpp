#include "Item.h"

Item::Item(string names, string des)
	: name(names), description(des)
{ }

void Item::ShowItemInfo()
{
	cout << "[" << name << "]" << endl;
	cout << description << endl;
}

Armor::Armor(string names, string des, int hp, int mp, int atk)
	: Item(names, des), shiftHP(hp), shiftMP(mp), shiftATK(atk)
{ }

void Armor::ShowItemInfo()
{
	Item::ShowItemInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}