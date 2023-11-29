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
		cout << "체력이 " << maxHP - health << " 회복되었습니다. 현재 체력 : " << health << endl;
		health = maxHP;
		return;
	}
	health += hp;
	cout << "체력이 " << hp << " 회복되었습니다. 현재 체력 : " << health << endl;
}

void Player::HealMP(int mp)
{
	if (magic + mp > maxMP)
	{
		cout << "마나가 " << maxMP - magic << " 회복되었습니다. 현재 마나 : " << health << endl;
		magic = maxMP;
		return;
	}
	magic += mp;
	cout << "마나가 " << mp << " 회복되었습니다. 현재 마나 : " << magic << endl;
}


Monster::Monster(string names, int hp, int mhp, int mp, int mmp, int atk)
	: Character(names), health(hp), maxHP(mhp), magic(mp), maxMP(mmp), attack(atk)
{ }