#include "Village.h"

Village::Village(const string& names, int ord, int roadnum, vector<Item> items, NPC person)
	: name(names), order(ord), road(roadnum), itemlist(items), villager(person)
{ }

void Village::Visit(Player& user)
{
	user.SetCurrentVillage(order);
	while (true)
	{
		int choice;
		cout << name << "�� �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
		cout << "1. ���ҿ��� ����\t2. ���� ����\t3. �ֹΰ� ��ȭ�ϱ�\t4. ���� ������ �̵��ϱ�\t5. ���� ������ �̵��ϱ�" << endl;
		cout << "���� : "; cin >> choice;
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
		case 4:
		case 5:
		default:
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
		cout << "���� : "; cin >> choice;
		if (choice >= itemlist.size())
		{
			cout << "��ȣ�� �ٽ� �Է����ּ���." << endl;
		}
		else
		{
			user.DecreaseGold(itemlist[choice - 1].GetValue());
			user.GetInventory().AddItem(itemlist[choice - 1]);
			cout << "���� �Ϸ��߽��ϴ�." << endl << endl;
			return;
		}
	}
}