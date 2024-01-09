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
		cout << "1. ���ҿ��� ����  2. ���� ����  3. �ֹΰ� ��ȭ�ϱ�  4. ���� ������ �̵��ϱ�  5. ���� �÷��̾� ���� ����" << endl;
		while (true)
		{
			cout << "���� : "; cin >> choice; cin.ignore();
			if (choice < 1 || choice > 5)
				cout << "�ٽ� �������ּ���." << endl << endl;
			else
				break;
		}
		cout << endl;
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
			Travel(user, villageList[order]);
			break;
		case 5:
			user.ShowInfo();
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
	cout << "0. �������� �ʴ´�." << endl;
	for (int i = 0; i < itemlist.size(); i++)
	{
		cout << i + 1 << ". ";
		itemlist[i].ShowItemSalesInfo();
	}
	cout << endl << "� ���� �����Ͻðڽ��ϱ�?" << endl;
	while (true)
	{
		cout << "���� : "; cin >> choice; cin.ignore();
		if (choice > itemlist.size() || choice < 0)
		{
			cout << "��ȣ�� �ٽ� �Է����ּ���." << endl;
		}
		else if (choice == 0)
		{
			return;
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
			Monster* mon = new Monster((name + "�� ����"), order * 20 + p(), order * 20 + p(), order * 3, {hunting_token, basic_armor});
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

	if (user.GetInventory().RemoveItem(hunting_token, 10) == true)
	{
		town.Visit(user);
	}
	else
	{
		cout << "����� ��ǥ 10���� ��ƾ� �� �� �ֽ��ϴ�." << endl << endl;
		return;
	}
}

Village dlfqjs("�Ϲ� ����", 1, 3, {basic_sword}, garam);
Village dlqjs("�̹� ����", 2, 5, {basic_armor}, nara);
Village tkaqjs("��� ����", 3, 7, {basic_sword, basic_armor}, daeum);
Village tkqjs("��� ����", 4, 9, {basic_sword, basic_armor}, rara);
Village dhqjs("���� ����", 5, 11, {}, mari);
vector<Village> villageList = { dlfqjs, dlqjs, tkaqjs, tkqjs, dhqjs };