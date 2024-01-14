#ifndef __SKILL_H_
#define __SKILL_H_

#include "commonInclude.h"
#include "Character.h"

class Skill
{
private:
	string name;
	int requiredMP;
	int damage;
public:
	Skill(const string& names, int mp = 0, int dmg = 1)
		: name(names), requiredMP(mp), damage(dmg)
	{ }
	int GetRequiredMP() const { return requiredMP; }
	int GetDamage() const { return damage; }
	void ShowSkillInfo() const
	{
		cout << name << " MP 소모 " << requiredMP << " 대미지 " << damage << endl;
	}
};

Skill basic_attack("기본 공격", 0, 1);
Skill strong_attack("세게 때리기", 5, 2);
Skill final_attack("혼신의 일격", 15, 3);

class SkillInven
{
private:
	vector<Skill> skillInven;
public:
	SkillInven(vector<Skill> skills = {basic_attack})
		: skillInven(skills)
	{ }
	void AddSkill(Skill& newskill)
	{
		skillInven.push_back(newskill);
	}
};
#endif