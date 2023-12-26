#include "Item.h"

Item::Item(const string& names, const string& des)
	: name(names), description(des)
{ }

const string& Item::GetName() const
{
	return name;
}

void Item::ShowItemInfo() const
{
	cout << "[" << name << "]" << endl;
}

void Item::ShowItemDetailInfo() const
{
	cout << "[" << name << "]" << endl;
	cout << description << endl;
}



Armor::Armor(const string& names, const string& des, int hp, int mp, int atk)
	: Item(names, des), shiftHP(hp), shiftMP(mp), shiftATK(atk)
{ }

void Armor::ShowItemInfo() const
{
	Item::ShowItemInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}

void Armor::ShowItemDetailInfo() const
{
	Item::ShowItemDetailInfo();
	cout << showpos << "HP " << shiftHP << "	MP " << shiftMP << "	ATK " << shiftATK << endl;
}


Item hunting_token("����� ��ǥ", "���͸� ����ϸ� ���� �� �ִ� ��ǥ. 10���� ��Ƽ� ���ư���.");
Armor basic_sword("�⺻ ��", "�⺻���� ���̴�.", 0, 0, 1);
Armor basic_armor("�⺻ ����", "�⺻���� �����̴�.", 5, 0, 0);