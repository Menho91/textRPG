#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "CommonInclude.h"
#include "Conversation.h"
#include "Item.h"
#include "Inventory.h"

class Character
{
protected:
	const string name;
public:
	Character(const string& names);
	const string& GetName() const;
};

class NPC : public Character
{
private:
	Conversation talk;
public:
	NPC(const string& names, Conversation& conv);
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
	PC(const string& names, int mhp = 10, int mmp = 10, int atk = 1);
	bool GetIsDead() const;
	void Attack(PC& pc);
	virtual void ShowInfo() const;
};

class Player : public PC
{
private:
	int exp;
	int level;
	int currentVillage;
	Inventory inven;
public:
	Player(const string& names, int mhp = 10, int mmp = 10, int atk = 1);
	void HealHP(int hp);
	void HealMP(int mp);
	void IncreaseExp(int value);
	void Fight(Monster& enemy);
	int GetCurrentVillage() const;
	virtual void ShowInfo() const;
};

class Monster : public PC
{
private:
	int givingExp;
public:
	Monster(const string& names, int mhp = 10, int mmp = 10, int atk = 1);
	int GetGivingExp() const;
};
#endif