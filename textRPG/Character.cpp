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

	}
}


Monster::Monster(string names, int hp, int mhp, int mp, int mmp, int atk)
	: Character(names), health(hp), maxHP(mhp), magic(mp), maxMP(mmp), attack(atk)
{ }