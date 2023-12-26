#include "Character.h"
#include "Probability.h"

Character::Character(const string& names)
	: name(names)
{ }

const string& Character::GetName() const
{
	return name;
}


NPC::NPC(const string& names, Conversation& conv)
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


PC::PC(const string& names, int mhp, int mmp, int atk)
	: Character(names), health(mhp), maxHP(mhp), magic(mmp), maxMP(mmp), attack(atk), isDead(false)
{ }

bool PC::GetIsDead() const
{
	return isDead;
}

void PC::Attack(PC& pc)
{
	Probability p;
	if (p(30))
	{
		pc.health -= attack * 1.5;
		cout << pc.name << attack * 1.5 << "��ŭ ����! " << pc.name << " ���� HP " << pc.health << endl;
	}
	else
	{
		pc.health -= attack;
		cout << pc.name << attack << "��ŭ ����, " << pc.name << " ���� HP " << pc.health << endl;
	}
	if (pc.health <= 0)
	{
		pc.isDead = true;
		pc.health = 0;
	}
}

void PC::ShowInfo() const
{
	cout << "ü�� : " << health << "/" << maxHP << " ���� : " << magic << "/" << maxMP
		<<" ���ݷ� : " << attack << endl;
}


Player::Player(const string& names, int mhp, int mmp, int atk)
	: PC(names, mhp, mmp, atk), exp(0), level(1), currentVillage(1)
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

void Player::IncreaseExp(int value)
{
	cout << value << " ����ġ�� ȹ���ߴ�." << endl;
	exp += value;
	if (exp >= 100 + ((level - 1) * 10))
	{
		exp -= 100 + ((level - 1) * 10);
		level += 1;
		cout << "������ �߽��ϴ�." << endl;
	}
	cout << "���� : " << level << " ����ġ : " << exp << "/" << 100 + ((level - 1) * 10) << endl;
}

void Player::Fight(Monster& enemy)
{
	while (isDead && enemy.GetIsDead())
	{
		cout << name << "�� ����" << endl;
		Attack(enemy);
		if (enemy.GetIsDead())
			break;
		cout << enemy.GetName() << "�� ����" << endl;
		enemy.Attack(*this);
	}
	cout << "������ �������ϴ�." << endl;
	if (enemy.GetIsDead())
	{
		IncreaseExp(enemy.GetGivingExp());
	}
	else
	{
		cout << "���������� �湮�� �������� ��Ȱ�մϴ�." << endl;
		HealHP(1);
	}
}

int Player::GetCurrentVillage() const
{
	return currentVillage;
}

void Player::ShowInfo() const
{
	PC::ShowInfo();
	cout << "���� : " << level << " ����ġ : " << exp << "/" << 100 + ((level - 1) * 10) << endl;
}


Monster::Monster(const string& names, int mhp, int mmp, int atk)
	: PC(names, mhp, mmp, atk), givingExp(health * 1.5)
{ }

int Monster::GetGivingExp() const
{
	return givingExp;
}