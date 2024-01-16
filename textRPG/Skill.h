#ifndef __SKILL_H_
#define __SKILL_H_

#include "commonInclude.h"

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
	const string& GetSkillname() const { return name; }
	int GetRequiredMP() const { return requiredMP; }
	int GetDamage() const { return damage; }
	void ShowSkillInfo() const
	{
		cout << name << " MP �Ҹ� " << requiredMP << " ����� " << damage << endl;
	}
};

static Skill basic_attack("�⺻ ����", 0, 1);
static Skill strong_attack("���� ������", 5, 2);
static Skill final_attack("ȥ���� �ϰ�", 15, 3);

class SkillInven
{
private:
	vector<Skill> skillInven;
public:
	SkillInven(vector<Skill> skills = {basic_attack, strong_attack})
		: skillInven(skills)
	{ }
	void AddSkill(Skill& newskill)
	{
		skillInven.push_back(newskill);
	}
	size_t size() const
	{
		return skillInven.size();
	}
	Skill& operator[](int value)
	{
		return skillInven[value];
	}
};
#endif