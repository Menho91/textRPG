#include "Character.h"

Character::Character(string names)
	: name(names)
{ }


Player::Player(string names, int hp, int mhp, int mp, int mmp, int atk, int lev)
	: Character(names), health(hp), maxHP(mhp), magic(mp), maxMP(mmp), attack(atk), level(lev)
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


Monster::Monster(string names, int hp, int mhp, int mp, int mmp, int atk)
	: Character(names), health(hp), maxHP(mhp), magic(mp), maxMP(mmp), attack(atk)
{ }