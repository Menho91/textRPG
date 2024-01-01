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
	vector<Item> itemlist;
	NPC villager;
public:
	Village(const string& names, int ord, int roadnum, vector<Item> items, NPC person);
	void Visit(Player& user);
	void Heal(Player& user);
	void Interact(Player& user);
	void Sale(Player& user);
};
#endif