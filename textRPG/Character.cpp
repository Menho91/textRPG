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
		cout << endl << "���� : "; cin >> choice; cin.ignore(INT_MAX, '\n');
	}
	if (talk.GetEnding() != str)
	{
		cout << GetName() << " : " << talk.GetEnding()[choice - 1] << endl;
	}
}

NPC garam("����", Conversation("ó�� ������ �����Ѵٰ�? ����ְڳ�."));
NPC nara("����", Conversation("���� ������ ������ �;�!"));
NPC daeum("����", Conversation("�� ������ ���� �ִ� �ž�?", {"���� ����.", "�� ������ ������!"}, {"�� ����ֳ�.", "��, ���ִ�!"}));
NPC rara("���", Conversation("�� ���� ������ ���Ͱ� ���´ٰ�."));
NPC mari("����", Conversation("�� �ְ��̴�."));


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
	cout << GetName() << "�� ����" << endl;
	if (p(30))
	{
		pc.DecreaseHealth(attack * 2);
		cout << pc.GetName() << " " << attack * 2 << "��ŭ ����! ";
	}
	else
	{
		pc.DecreaseHealth(attack);
		cout << pc.GetName() << " " << attack << "��ŭ ����, ";
	}
	if (pc.GetHealth() <= 0)
	{
		pc.SetIsDead(true);
		pc.SetHealth(0);
	}
	cout << pc.GetName() << " ���� HP " << pc.GetHealth() << endl;
}

void PC::ShowInfo() const
{
	cout << "[ " << GetName() << " ]" << endl;
	cout << "ü�� : " << health << "/" << maxHP << " ���� : " << magic << "/" << maxMP
		<<" ���ݷ� : " << attack << endl;
}


Player::Player(const string& names, int mhp, int mmp, int atk)
	: PC(names, mhp, mmp, atk), gold(0), exp(0), level(1), currentVillage(1)
{ }

void Player::HealHP(int hp)
{
	if (health + hp > maxHP)
	{
		cout << "ü���� " << maxHP - health << " ȸ���Ǿ����ϴ�. ";
		health = maxHP;
		cout << "���� ü�� : " << health << endl;
		return;
	}
	health += hp;
	cout << "ü���� " << hp << " ȸ���Ǿ����ϴ�. ���� ü�� : " << health << endl;
}

void Player::HealMP(int mp)
{
	if (magic + mp > maxMP)
	{
		cout << "������ " << maxMP - magic << " ȸ���Ǿ����ϴ�. ";
		magic = maxMP;
		cout << "���� ���� : " << magic << endl;
		return;
	}
	magic += mp;
	cout << "������ " << mp << " ȸ���Ǿ����ϴ�. ���� ���� : " << magic << endl;
}

void Player::IncreaseAbility(Armor& arm)
{
	maxHP += arm.GetShiftHP();
	maxMP += arm.GetShiftMP();
	attack += arm.GetShiftATK();
}

void Player::IncreaseGold(int value)
{
	cout << value << " ��带 ȹ���߽��ϴ�." << endl;
	gold += value;
	cout << "���� ��� : " << gold << endl << endl;
}

bool Player::DecreaseGold(int value)
{
	if (gold < value)
	{
		cout << "��尡 �����մϴ�. ���� ��� : " << gold << endl;
		return false;
	}
	else
	{
		gold -= value;
		cout << value << " ��带 �����߽��ϴ�. ���� ��� : " << gold << endl;
		return true;
	}
}

void Player::IncreaseExp(int value)
{
	cout << value << " ����ġ�� ȹ���߽��ϴ�." << endl;
	exp += value;
	if (exp >= 100 * level)
	{
		LevelUP();
	}
	cout << "���� : " << level << " ����ġ : " << exp << "/" << 100 * level << endl << endl;
}

void Player::LevelUP()
{
	cout << "������ �߽��ϴ�." << endl;
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
		cout << "���ο� ��ų�� ������ϴ�." << endl;
		final_attack.ShowSkillInfo();
	}
	cout << endl;
}

bool Player::UseSkill(Skill& skill)
{
	cout << skill.GetSkillname() << " ����մϴ�." << endl;
	if (magic < skill.GetRequiredMP())
	{
		cout << "������ �����Ͽ� �����߽��ϴ�. ���� ���� : " << magic << " / " << maxMP << endl;
		return false;
	}
	else
	{
		magic -= skill.GetRequiredMP();
		cout << "���� ���� : " << magic << " / " << maxMP << endl;
		return true;
	}
}

void Player::Attack(PC& pc)
{
	Probability p;
	int choice;
	cout << GetName() << "�� ����" << endl;
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
			cout << pc.GetName() << " " << attack * skillList[choice - 1].GetDamage() * 2 << "��ŭ ����! ";
		}
		else
		{
			pc.DecreaseHealth(attack * skillList[choice - 1].GetDamage());
			cout << pc.GetName() << " " << attack * skillList[choice - 1].GetDamage() << "��ŭ ����, ";
		}
	}
	else
	{
		cout << skillList[0].GetSkillname() << "���� �����մϴ�." << endl;
		pc.DecreaseHealth(attack);
		cout << pc.GetName() << " " << attack << "��ŭ ����, ";
	}
	if (pc.GetHealth() <= 0)
	{
		pc.SetIsDead(true);
		pc.SetHealth(0);
	}
	cout << pc.GetName() << " ���� HP " << pc.GetHealth() << endl << endl;
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
	cout << "������ �������ϴ�." << endl << endl;
	if (enemy.GetIsDead())
	{
		enemy.Defeat(*this);
	}
	else
	{
		cout << "�׾����ϴ�. ���������� �湮�� �������� ��Ȱ�մϴ�." << endl << endl;
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
	cout << "���� : " << level << " ����ġ : " << exp << "/" << 100 * level << endl;
	cout << "���� ��� : " << gold << endl << endl;
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