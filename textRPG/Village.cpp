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
		cout << name << "에 도착했습니다. 무엇을 하시겠습니까?" << endl;
		cout << "1. 숙소에서 쉬기\t2. 상점 가기\t3. 주민과 대화하기\t4. 이전 마을로 이동하기\t5. 다음 마을로 이동하기" << endl;
		cout << "선택 : "; cin >> choice;
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
	cout << "숙소에서 쉬어갑니다." << endl;
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
	cout << endl << "어떤 것을 구매하시겠습니까?" << endl;
	while (true)
	{
		cout << "선택 : "; cin >> choice;
		if (choice >= itemlist.size())
		{
			cout << "번호를 다시 입력해주세요." << endl;
		}
		else
		{
			user.DecreaseGold(itemlist[choice - 1].GetValue());
			user.GetInventory().AddItem(itemlist[choice - 1]);
			cout << "구매 완료했습니다." << endl << endl;
			return;
		}
	}
}