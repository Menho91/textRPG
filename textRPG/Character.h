#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "CommonInclude.h"
#include "Conversation.h"
#include "Item.h"
#include "Inventory.h"

class Character
{
protected:
	string name;
public:
	Character(string& names);
};

class NPC : public Character
{
private:
	Conversation talk;
public:
	NPC(string& names, Conversation& conv);
	void StartConversation();
};

class Player : public Character
{
private:
	int health;
	int maxHP;
	int magic;
	int maxMP;
	int attack;
	int level;
	Inventory inven;
public:
	Player(string& names, int hp = 0, int mhp = 10, int mp = 0, int mmp = 10, int atk = 1, int lev = 1);
	void HealHP(int hp);
	void HealMP(int mp);
};

class Monster : public Character
{
private:
	int health;
	int maxHP;
	int magic;
	int maxMP;
	int attack;
public:
	Monster(string& names, int hp, int mhp, int mp, int mmp, int atk);
};
#endif