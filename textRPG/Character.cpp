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
		cout << endl << "���� : "; cin >> choice; cin.ignore();
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

void PC::SetIsDead(bool dead)
{
	isDead = dead;
}

void PC::Attack(PC& pc) const
{
	Probability p;
	cout << GetName() << "�� ����" << endl;
	if (p(30))
	{
		pc.health -= attack * 2;
		cout << pc.GetName() << " " << attack * 2 << "��ŭ ����! ";
	}
	else
	{
		pc.health -= attack;
		cout << pc.GetName() << " " << attack << "��ŭ ����, ";
	}
	if (pc.health <= 0)
	{
		pc.isDead = true;
		pc.health = 0;
	}
	cout << pc.GetName() << " ���� HP " << pc.health << endl;
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
		cout << "������ " << maxMP - magic << " ȸ���Ǿ����ϴ�. ���� ���� : " << health << endl;
		magic = maxMP;
		return;
	}
	magic += mp;
	cout << "������ " << mp << " ȸ���Ǿ����ϴ�. ���� ���� : " << magic << endl;
}

void Player::IncreaseAbility(Armor& arm)
{
	cout << "?????????" << endl;
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
	exp -= 100 * level;
	level += 1;
	cout << "������ �߽��ϴ�." << endl;
	maxHP += 10;
	maxMP += 10;
	HealHP(maxHP);
	HealMP(maxMP);
	attack += 1;
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


Monster::Monster(const string& names, int mhp, int mmp, int atk, const vector<Item>& items)
	: PC(names, mhp, mmp, atk), givingItem(items)
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
	for (int i = 0; i < givingItem.size(); i++)
	{
		if (p(20))
		{
			user.GetInventory().AddItem(givingItem[i]);
			Armor* temp = dynamic_cast<Armor*>(&(givingItem[i]));
			if (temp != nullptr)
			{
				user.IncreaseAbility(dynamic_cast<Armor&>(givingItem[i]));
			}
			delete temp;
		}
	}
}