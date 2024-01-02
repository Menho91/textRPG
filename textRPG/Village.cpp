#include "Village.h"

Village::Village(const string& names, int ord, int roadnum, vector<Item> items, NPC person)
	: name(names), order(ord), road(roadnum), itemlist(items), villager(person)
{ }

void Village::Visit(Player& user)
{
	while (true)
	{
		int choice;
		user.SetCurrentVillage(1);
		cout << endl;
		cout << name << "�� �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
		cout << "1. ���ҿ��� ����	    2. ���� ����    3. �ֹΰ� ��ȭ�ϱ�    4. ���� ������ �̵��ϱ�    5. ���� ������ �̵��ϱ�" << endl;

		while (true)
		{
			cout << "���� : "; cin >> choice; cin.ignore();
			if (choice < 1 || choice > 5)
				cout << "�ٽ� �������ּ���." << endl << endl;
			else
				break;
		}

		switch (choice)
		{
		case 1:
			Heal(user);
			break;
		case 2:
			Sale(user);
			break;
		case 3:
			Interact(user);
			break;
		case 4:
			Travel(user, villageList[order - 2]);
			break;
		case 5:
			Travel(user, villageList[order]);
			break;
		}
	}
}

void Village::Heal(Player& user)
{
	cout << "���ҿ��� ����ϴ�." << endl;
	user.HealHP(user.GetMaxHP());
	user.HealMP(user.GetMaxMP());
}

void Village::Interact(Player& user)
{
	villager.StartConversation();
}

void Village::Sale(Player& user)
{
	int choice;
	for (int i = 0; i < itemlist.size(); i++)
	{
		cout << i + 1 << ". ";
		itemlist[i].ShowItemSalesInfo();
	}
	cout << endl << "� ���� �����Ͻðڽ��ϱ�?" << endl;
	while (true)
	{
		cout << "���� : "; cin >> choice; cin.ignore();
		if (choice >= itemlist.size() || choice < 1)
		{
			cout << "��ȣ�� �ٽ� �Է����ּ���." << endl;
		}
		else
		{
			break;
		}
	}
	if (user.DecreaseGold(itemlist[choice - 1].GetValue()))
	{
		user.GetInventory().AddItem(itemlist[choice - 1]);
		cout << "���� �Ϸ��߽��ϴ�." << endl << endl;
		return;
	}
	return;
}

void Village::Travel(Player& user, Village& town)
{
	cout << town.name << "���� �̵��մϴ�. ���� �̵� �� " << town.road << endl;
	for (int i = 0; i < town.road; i++)
	{
		Probability p;
		if (p(60))
		{
			cout << "���͸� �������ϴ�." << endl << endl;
			Monster* mon = new Monster((name + "�� ����"), order * 10 + p(), order * 10 + p(), order);
			user.Fight(*mon);
			delete mon;
			if (user.GetIsDead())
			{
				user.SetIsDead(false);
				return;
			}
		}
		else
		{
			cout << "������ ���� �ֽ��ϴ�." << endl;
		}
		cout << "���� �̵� �� " << town.road - i - 1 << endl << endl;
	}
	cout << endl;
	town.Visit(user);
}

Village dlfqjs("�Ϲ� ����", 1, 3, {basic_sword}, garam);
Village dlqjs("�̹� ����", 2, 4, {}, nara);
Village tkaqjs("��� ����", 3, 5, {}, daeum);
Village tkqjs("��� ����", 4, 6, {}, rara);
Village dhqjs("���� ����", 5, 7, {}, mari);
vector<Village> villageList = { dlfqjs, dlqjs, tkaqjs, tkqjs, dhqjs };