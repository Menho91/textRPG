#include "Character.h"

Character::Character(const string& names)
	: name(names)
{ }


NPC::NPC(const string& names, Conversation conv)
	: Character(names), talk(conv)
{ }

void NPC::StartConversation()
{
	int choice = 1;
	vector<string> str = {};
	cout << GetName() << " : " << talk.GetPrompt() << endl;
	if (talk.GetOptions() != str)
	{
		for (int i = 0; i < talk.GetOptions().size(); i++)
		{
			cout << i + 1 << " : " << talk.GetOptions()[i] << "    ";
		}
		cout << endl << "선택 : "; cin >> choice; cin.ignore(INT_MAX, '\n');
	}
	if (talk.GetEnding() != str)
	{
		cout << GetName() << " : " << talk.GetEnding()[choice - 1] << endl;
	}
}

NPC garam("가람", Conversation("처음 모험을 시작한다고? 재미있겠네."));
NPC nara("나라", Conversation("나도 모험을 떠나고 싶어!"));
NPC daeum("다음", Conversation("넌 어디까지 가고 있는 거야?", {"나도 몰라.", "이 세계의 끝까지!"}, {"참 용기있네.", "와, 멋있다!"}));
NPC rara("라라", Conversation("이 앞은 강력한 몬스터가 나온다고."));
NPC mari("마리", Conversation("난 최강이다."));


PC::PC(const string& names, int mhp, int mmp, int atk)
	: Character(names), health(mhp), maxHP(mhp), magic(mmp), maxMP(mmp), attack(atk), isDead(false)
{ }

void PC::SetHealth(int value)
{
	health = value;
}

void PC::SetIsDead(bool dead)
{
	isDead = dead;
}

void PC::DecreaseHealth(int value)
{
	health -= value;
}

void PC::Attack(PC& pc)
{
	Probability p;
	cout << GetName() << "의 차례" << endl;
	if (p(30))
	{
		pc.DecreaseHealth(attack * 2);
		cout << pc.GetName() << " " << attack * 2 << "만큼 공격! ";
	}
	else
	{
		pc.DecreaseHealth(attack);
		cout << pc.GetName() << " " << attack << "만큼 공격, ";
	}
	if (pc.GetHealth() <= 0)
	{
		pc.SetIsDead(true);
		pc.SetHealth(0);
	}
	cout << pc.GetName() << " 남은 HP " << pc.GetHealth() << endl;
}

void PC::ShowInfo() const
{
	cout << "[ " << GetName() << " ]" << endl;
	cout << "체력 : " << health << "/" << maxHP << " 마력 : " << magic << "/" << maxMP
		<<" 공격력 : " << attack << endl;
}


Player::Player(const string& names, int mhp, int mmp, int atk)
	: PC(names, mhp, mmp, atk), gold(0), exp(0), level(1), currentVillage(1)
{ }

void Player::HealHP(int hp)
{
	if (health + hp > maxHP)
	{
		cout << "체력이 " << maxHP - health << " 회복되었습니다. ";
		health = maxHP;
		cout << "현재 체력 : " << health << endl;
		return;
	}
	health += hp;
	cout << "체력이 " << hp << " 회복되었습니다. 현재 체력 : " << health << endl;
}

void Player::HealMP(int mp)
{
	if (magic + mp > maxMP)
	{
		cout << "마나가 " << maxMP - magic << " 회복되었습니다. ";
		magic = maxMP;
		cout << "현재 마나 : " << magic << endl;
		return;
	}
	magic += mp;
	cout << "마나가 " << mp << " 회복되었습니다. 현재 마나 : " << magic << endl;
}

void Player::IncreaseAbility(Armor& arm)
{
	maxHP += arm.GetShiftHP();
	maxMP += arm.GetShiftMP();
	attack += arm.GetShiftATK();
}

void Player::IncreaseGold(int value)
{
	cout << value << " 골드를 획득했습니다." << endl;
	gold += value;
	cout << "현재 골드 : " << gold << endl << endl;
}

bool Player::DecreaseGold(int value)
{
	if (gold < value)
	{
		cout << "골드가 부족합니다. 현재 골드 : " << gold << endl;
		return false;
	}
	else
	{
		gold -= value;
		cout << value << " 골드를 차감했습니다. 남은 골드 : " << gold << endl;
		return true;
	}
}

void Player::IncreaseExp(int value)
{
	cout << value << " 경험치를 획득했습니다." << endl;
	exp += value;
	if (exp >= 100 * level)
	{
		LevelUP();
	}
	cout << "레벨 : " << level << " 경험치 : " << exp << "/" << 100 * level << endl << endl;
}

void Player::LevelUP()
{
	cout << "레벨업 했습니다." << endl;
	exp -= 100 * level;
	level += 1;
	maxHP += 10;
	maxMP += 10;
	HealHP(maxHP);
	HealMP(maxMP);
	attack += 1;
	if (level == 5)
	{
		skillList.AddSkill(final_attack);
		cout << "새로운 스킬을 배웠습니다." << endl;
		final_attack.ShowSkillInfo();
	}
	cout << endl;
}

bool Player::UseSkill(Skill& skill)
{
	cout << skill.GetSkillname() << " 사용합니다." << endl;
	if (magic < skill.GetRequiredMP())
	{
		cout << "마나가 부족하여 실패했습니다. 현재 마나 : " << magic << " / " << maxMP << endl;
		return false;
	}
	else
	{
		magic -= skill.GetRequiredMP();
		cout << "남은 마나 : " << magic << " / " << maxMP << endl;
		return true;
	}
}

void Player::Attack(PC& pc)
{
	Probability p;
	int choice;
	cout << GetName() << "의 차례" << endl;
	for (int i = 0; i < skillList.size(); i++)
	{
		cout << i + 1 << ". ";
		skillList[i].ShowSkillInfo();
	}

	choice = Choice(1, skillList.size());
	cout << endl;

	if (UseSkill(skillList[choice - 1]))
	{
		if (p(30))
		{
			pc.DecreaseHealth(attack * skillList[choice - 1].GetDamage() * 2);
			cout << pc.GetName() << " " << attack * skillList[choice - 1].GetDamage() * 2 << "만큼 공격! ";
		}
		else
		{
			pc.DecreaseHealth(attack * skillList[choice - 1].GetDamage());
			cout << pc.GetName() << " " << attack * skillList[choice - 1].GetDamage() << "만큼 공격, ";
		}
	}
	else
	{
		cout << skillList[0].GetSkillname() << "으로 공격합니다." << endl;
		pc.DecreaseHealth(attack);
		cout << pc.GetName() << " " << attack << "만큼 공격, ";
	}
	if (pc.GetHealth() <= 0)
	{
		pc.SetIsDead(true);
		pc.SetHealth(0);
	}
	cout << pc.GetName() << " 남은 HP " << pc.GetHealth() << endl << endl;
}

void Player::Fight(Monster& enemy)
{
	Probability p;
	while (!(isDead) && !(enemy.GetIsDead()))
	{
		Attack(enemy);
		Sleep(1000);
		if (enemy.GetIsDead())
			break;
		enemy.Attack(*this);
		Sleep(1000);
		cout << endl;
	}
	cout << "전투가 끝났습니다." << endl << endl;
	if (enemy.GetIsDead())
	{
		enemy.Defeat(*this);
	}
	else
	{
		cout << "죽었습니다. 마지막으로 방문한 마을에서 부활합니다." << endl << endl;
		health = 1;
	}
}

void Player::SetCurrentVillage(int order)
{
	currentVillage = order;
}

void Player::ShowInfo() const
{
	PC::ShowInfo();
	cout << "레벨 : " << level << " 경험치 : " << exp << "/" << 100 * level << endl;
	cout << "현재 골드 : " << gold << endl << endl;
	inven.ShowInventory();
}


Monster::Monster(const string& names, int mhp, int mmp, int atk, const vector<Armor>& arms)
	: PC(names, mhp, mmp, atk), givingArmor(arms)
{
	Probability p;
	givingGold = (mhp * 10) + p();
	givingExp = mhp + p();
}

void Monster::Defeat(Player& user)
{
	Probability p;
	user.IncreaseExp(givingExp);
	user.IncreaseGold(givingGold);
	user.GetInventory().AddItem(hunting_token);
	for (int i = 0; i < givingArmor.size(); i++)
	{
		if (p(20))
		{
			user.GetInventory().AddItem(givingArmor[i]);
			user.IncreaseAbility(givingArmor[i]);
		}
	}
}