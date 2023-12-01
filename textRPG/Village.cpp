#include "Village.h"

Village::Village(string names, int ord)
	: name(names), order(ord)
{ }

void Village::Heal(Player& user)
{
	user.HealHP(9999);
	user.HealMP(9999);
}

void Village::Interact(Player& user, Character& npc)
{
	
}

void Village::Sale(Player& user, Item* itemlist)
{
	for (int i = 0; i < 99; i++)
	{
		itemlist[i].ShowItemInfo();
		cout << endl;
	}
	cout << endl << "어떤 것을 구매하시겠습니까?";
}