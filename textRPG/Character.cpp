#include "Character.h"

Character::Character(string& names)
	: name(names)
{ }


NPC::NPC(string& names, Conversation& conv)
	: Character(names), talk(conv)
{ }

void NPC::StartConversation()
{
	int choice;
	cout << name << " : " << talk.GetPrompt() << endl;
	for (int i = 0; i < talk.GetOption().size(); i++)
	{
		cout << i + 1 << " : " << talk.GetOption()[i] << " ";
	}
	cout << endl << "���� : ";
	cin >> choice;
	talk.SetChoice(choice);
	cout << name << " : " << talk.GetEnding() << endl;
}


PC::PC(string& names, int hp, int mhp, int mp, int mmp, int atk)
	: Character(names), health(hp), maxHP(mhp), magic(mp), maxMP(mmp), attack(atk), isDead(false)
{ }

bool PC::GetIsDead()
{
	return isDead;
}

void PC::Attack(PC& pc)
{
	pc.health -= attack;
	cout << pc.name << attack << "��ŭ ����! " << pc.name << " ���� HP " << pc.health << endl;
	if (pc.health <= 0)
	{
		pc.isDead = true;
		pc.health = 0;
	}
}

void PC::Fight(PC& pc1, PC& pc2)
{
	while (pc1.GetIsDead() && pc2.GetIsDead())
	{
		cout << pc1.name << "�� ����" << endl;
		pc1.Attack(pc2);
		if (pc2.isDead)
			break;
		cout << pc2.name << "�� ����" << endl;
		pc2.Attack(pc1);
	}
	cout << "������ �������ϴ�." << endl;
}


Player::Player(string& names, int hp, int mhp, int mp, int mmp, int atk, int lev)
	: PC(names, hp, mhp, mp, mmp, atk), level(lev)
{ }

void Player::HealHP(int hp)
{
	if (health + hp > maxHP)
	{
		cout << "ü���� " << maxHP - health << " ȸ���Ǿ����ϴ�. ���� ü�� : " << health << endl;
		health = maxHP;
		return;
	}
	health += hp;
	cout << "ü���� " << hp << " ȸ���Ǿ����ϴ�. ���� ü�� : " << health << endl;
}

void Player::HealMP(int mp)
{
	if (magic + mp > maxMP)
	{
		cout << "������ " << maxMP - magic << " ȸ���Ǿ����ϴ�. ���� ���� : " << health << endl;
		magic = maxMP;
		return;
	}
	magic += mp;
	cout << "������ " << mp << " ȸ���Ǿ����ϴ�. ���� ���� : " << magic << endl;
}


Monster::Monster(string& names, int hp, int mhp, int mp, int mmp, int atk)
	: PC(names, hp, mhp, mp, mmp, atk)
{ }