#ifndef __VILLAGE_H_
#define __VILLAGE_H_

#include "CommonInclude.h"
#include "Character.h"
#include "Item.h"

class Village
{
private:
	string name;
	int order;
	int road;
public:
	Village(string& names, int ord, int roadnum);
	void Heal(Player& user);
	void Interact(Player& user, NPC& npc);
	void Sale(Player& user, Item* itemlist);
};
#endif