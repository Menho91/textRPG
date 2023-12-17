#include "Item.h"

Item::Item(const string& names, const string& des)
	: name(names), description(des)
{ }

void Item::ShowItemInfo()
{
	cout << "[" << name << "]" << endl;
}

void Item::ShowItemDetailInfo()
{
	cout << "[" << name << "]" << endl;
	cout << description << endl;
}


Armor::Armor(const string& names, const string& des, int hp, int mp, int atk)
	: Item(names, des), shiftHP(hp), shiftMP(mp), shiftATK(atk)
{ }

void Armor::ShowItemInfo()
{
	Item::ShowItemInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}

void Armor::ShowItemDetailInfo()
{
	Item::ShowItemDetailInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}


Item hunting_token = Item("����� ��ǥ", "���͸� ����ϸ� ���� �� �ִ� ��ǥ. 10���� ��Ƽ� ���ư���.");
Armor basic_sword = Armor("�⺻ ��", "�⺻���� ���̴�.", 0, 0, 1);
Armor basic_armor = Armor("�⺻ ����", "�⺻���� �����̴�.", 5, 0, 0);