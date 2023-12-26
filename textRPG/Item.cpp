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


Item hunting_token("사냥의 증표", "몬스터를 사냥하면 얻을 수 있는 증표. 10개를 모아서 돌아가자.");
Armor basic_sword("기본 검", "기본적인 검이다.", 0, 0, 1);
Armor basic_armor("기본 갑옷", "기본적인 갑옷이다.", 5, 0, 0);