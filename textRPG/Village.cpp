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
		cout << name << "에 도착했습니다. 무엇을 하시겠습니까?" << endl;
		cout << "1. 숙소에서 쉬기  2. 상점 가기  3. 주민과 대화하기  4. 다음 마을로 이동하기  5. 현재 플레이어 정보 보기" << endl;
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
	cout << "0. 구매하지 않는다." << endl;
	for (int i = 0; i < itemlist.size(); i++)
	{
		cout << i + 1 << ". ";
		itemlist[i].ShowItemSalesInfo();
	}
	cout << endl << "어떤 것을 구매하시겠습니까?" << endl;

	choice = Choice(0, itemlist.size());
	cout << endl;

	if (choice == 0)
	{
		return;
	}
	if (user.DecreaseGold(itemlist[choice - 1].GetValue()))
	{
		user.GetInventory().AddItem(itemlist[choice - 1]);
		cout << "구매 완료했습니다." << endl << endl;
		return;
	}
	return;
}

void Village::Travel(Player& user, Village& town)
{
	cout << town.name << "까지 이동합니다. 남은 이동 수 " << town.road << endl << endl;
	for (int i = 0; i < town.road; i++)
	{
		Sleep(1000);
		Probability p;
		if (p(60))
		{
			cout << "몬스터를 만났습니다." << endl << endl;
			Monster* mon = new Monster((name + "의 몬스터"), order * order * 10 + p(), order * order * 10 + p(), order * order * 3, { BasicSword_ARMOR, BasicArmor_ARMOR });
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
			cout << "무사히 가고 있습니다." << endl;
		}
		cout << "남은 이동 수 " << town.road - i - 1 << endl << endl;
	}
	cout << endl;

	if (user.GetInventory().RemoveItem(HuntingToken_ITEM, 10) == true)
	{
		town.Visit(user);
	}
	else
	{
		cout << "사냥의 증표 10개를 모아야 들어갈 수 있습니다." << endl << endl;
		return;
	}
}

Village Wellspring_VILLAGE("웰스프링", 1, 3, { BasicSword_ARMOR }, Iris_NPC);
Village Calchester_VILLAGE("칼체스터", 2, 5, { BasicArmor_ARMOR }, Leah_NPC);
Village Kineallen_VILLAGE("키넬른", 3, 7, { BasicSword_ARMOR, BasicArmor_ARMOR }, Greyson_NPC);
Village Porthcrawl_VILLAGE("포스크롤", 4, 9, { BasicSword_ARMOR, BasicArmor_ARMOR }, Henry_NPC);
Village Sanlow_VILLAGE("샌로우", 5, 11, { StrongSword_ARMOR, StrongArmor_ARMOR }, Genesis_NPC);
vector<Village> villageList = { Wellspring_VILLAGE, Calchester_VILLAGE, Kineallen_VILLAGE, Porthcrawl_VILLAGE, Sanlow_VILLAGE };