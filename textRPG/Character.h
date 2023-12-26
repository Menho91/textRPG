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

class PC : public Character
{
protected:
	int health;
	int maxHP;
	int magic;
	int maxMP;
	int attack;
	bool isDead;
public:
	PC(string& names, int hp = 10, int mhp = 10, int mp = 10, int mmp = 10, int atk = 1);
	bool GetIsDead();
	void Attack(PC& pc);
	void Fight(PC& pc1, PC& pc2);
};

class Player : public PC
{
private:
	int level;
	Inventory inven;
public:
	Player(string& names, int hp = 10, int mhp = 10, int mp = 10, int mmp = 10, int atk = 1, int lev = 1);
	void HealHP(int hp);
	void HealMP(int mp);
};

class Monster : public PC
{
public:
	Monster(string& names, int hp = 10, int mhp = 10, int mp = 10, int mmp = 10, int atk = 1);
};
#endif