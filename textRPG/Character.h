#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "CommonInclude.h"
#include "Conversation.h"
#include "Item.h"
#include "Skill.h"
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
	NPC(const string& names, Conversation conv);
	void StartConversation();
};

extern NPC Iris_NPC;
extern NPC Leah_NPC;
extern NPC Greyson_NPC;
extern NPC Henry_NPC;
extern NPC Genesis_NPC;


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
	int GetMaxHP() const { return maxHP; }
	int GetMaxMP() const { return maxMP; }
	int GetHealth() const { return health; }
	void SetHealth(int value);
	bool GetIsDead() const { return isDead; }
	void SetIsDead(bool dead);
	void DecreaseHealth(int value);
	virtual void Attack(PC& pc);
	virtual void ShowInfo() const;
};


class Monster;
class Player : public PC
{
private:
	int gold;
	int exp;
	int level;
	int currentVillage;
	Inventory inven;
	SkillInven skillList;
public:
	Player(const string& names, int mhp = 20, int mmp = 20, int atk = 2);
	Inventory& GetInventory() { return inven; }
	void HealHP(int hp);
	void HealMP(int mp);
	void IncreaseAbility(Armor& arm);
	void IncreaseGold(int value);
	bool DecreaseGold(int value);
	void IncreaseExp(int value);
	void LevelUP();
	bool UseSkill(Skill& skill);
	virtual void Attack(PC& pc);
	void Fight(Monster& enemy);
	int GetCurrentVillage() const { return currentVillage; }
	void SetCurrentVillage(int order);
	virtual void ShowInfo() const;
};


class Monster : public PC
{
private:
	int givingGold;
	int givingExp;
	vector<Armor> givingArmor;
public:
	Monster(const string& names, int mhp = 10, int mmp = 10, int atk = 1, const vector<Armor>& arms = {});
	virtual int GetGivingGold() const { return givingGold; }
	virtual int GetGivingExp() const { return givingExp; }
	virtual const vector<Armor>& GetGivingItem() const { return givingArmor; }
	void Defeat(Player& user);
};
#endif