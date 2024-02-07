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
		choice = Choice(1, 5);
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

	choice = Choice(0, itemlist.size());
	cout << endl;

	if (choice == 0)
	{
		return;
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
	cout << town.name << "���� �̵��մϴ�. ���� �̵� �� " << town.road << endl << endl;
	for (int i = 0; i < town.road; i++)
	{
		Sleep(1000);
		Probability p;
		if (p(60))
		{
			cout << "���͸� �������ϴ�." << endl << endl;
			Monster* mon = new Monster((name + "�� ����"), order * order * 10 + p(), order * order * 10 + p(), order * order * 3, { BasicSword_ARMOR, BasicArmor_ARMOR });
			user.Fight(*mon);
			if (user.GetIsDead())
			{
				user.SetIsDead(false);
				return;
			}
			delete mon;
		}
		else
		{
			cout << "������ ���� �ֽ��ϴ�." << endl;
		}
		cout << "���� �̵� �� " << town.road - i - 1 << endl << endl;
	}
	cout << endl;

	if (user.GetInventory().RemoveItem(HuntingToken_ITEM, 10) == true)
	{
		town.Visit(user);
	}
	else
	{
		cout << "����� ��ǥ 10���� ��ƾ� �� �� �ֽ��ϴ�." << endl << endl;
		return;
	}
}

Village Wellspring_VILLAGE("��������", 1, 3, { BasicSword_ARMOR }, Iris_NPC);
Village Calchester_VILLAGE("Įü����", 2, 5, { BasicArmor_ARMOR }, Leah_NPC);
Village Kineallen_VILLAGE("Ű�ڸ�", 3, 7, { BasicSword_ARMOR, BasicArmor_ARMOR }, Greyson_NPC);
Village Porthcrawl_VILLAGE("����ũ��", 4, 9, { BasicSword_ARMOR, BasicArmor_ARMOR }, Henry_NPC);
Village Sanlow_VILLAGE("���ο�", 5, 11, { StrongSword_ARMOR, StrongArmor_ARMOR }, Genesis_NPC);
vector<Village> villageList = { Wellspring_VILLAGE, Calchester_VILLAGE, Kineallen_VILLAGE, Porthcrawl_VILLAGE, Sanlow_VILLAGE };