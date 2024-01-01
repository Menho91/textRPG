#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "CommonInclude.h"
#include "Conversation.h"
#include "Item.h"
#include "Probability.h"

class Character
{
private:
	string name;
public:
	Character(const string& names);
	const string& GetName() const { return name; }
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
	virtual int GetGivingGold() const = 0;
	virtual int GetGivingExp() const = 0;
	int GetMaxHP() const { return maxHP; }
	int GetMaxMP() const { return maxMP; }
	bool GetIsDead() const { return isDead; }
	void Attack(PC& pc);
	virtual void ShowInfo() const;
};

class Player : public PC
{
private:
	int gold;
	int exp;
	int level;
	int currentVillage;
	Inventory inven;
public:
	Player(const string& names, int mhp = 20, int mmp = 20, int atk = 2);
	Inventory& GetInventory() { return inven; }
	void HealHP(int hp);
	void HealMP(int mp);
	void IncreaseGold(int value);
	bool DecreaseGold(int value);
	void IncreaseExp(int value);
	void LevelUP();
	void Fight(PC& enemy);
	int GetCurrentVillage() const { return currentVillage; }
	void SetCurrentVillage(int order);
	virtual void ShowInfo() const;
};

class Monster : public PC
{
private:
	int givingGold;
	int givingExp;
public:
	Monster(const string& names, int mhp = 10, int mmp = 10, int atk = 1);
	virtual int GetGivingGold() const { return givingGold; }
	virtual int GetGivingExp() const { return givingExp; }
};
#endif