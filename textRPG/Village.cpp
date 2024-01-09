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
		while (true)
		{
			cout << "선택 : "; cin >> choice; cin.ignore();
			if (choice < 1 || choice > 5)
				cout << "다시 선택해주세요." << endl << endl;
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
	while (true)
	{
		cout << "선택 : "; cin >> choice; cin.ignore();
		if (choice > itemlist.size() || choice < 0)
		{
			cout << "번호를 다시 입력해주세요." << endl;
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
		cout << "구매 완료했습니다." << endl << endl;
		return;
	}
	return;
}

void Village::Travel(Player& user, Village& town)
{
	cout << town.name << "까지 이동합니다. 남은 이동 수 " << town.road << endl;
	for (int i = 0; i < town.road; i++)
	{
		Probability p;
		if (p(60))
		{
			cout << "몬스터를 만났습니다." << endl << endl;
			Monster* mon = new Monster((name + "의 몬스터"), order * 20 + p(), order * 20 + p(), order * 3, {hunting_token, basic_armor});
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
			cout << "무사히 가고 있습니다." << endl;
		}
		cout << "남은 이동 수 " << town.road - i - 1 << endl << endl;
	}
	cout << endl;

	if (user.GetInventory().RemoveItem(hunting_token, 10) == true)
	{
		town.Visit(user);
	}
	else
	{
		cout << "사냥의 증표 10개를 모아야 들어갈 수 있습니다." << endl << endl;
		return;
	}
}

Village dlfqjs("일번 마을", 1, 3, {basic_sword}, garam);
Village dlqjs("이번 마을", 2, 5, {basic_armor}, nara);
Village tkaqjs("삼번 마을", 3, 7, {basic_sword, basic_armor}, daeum);
Village tkqjs("사번 마을", 4, 9, {basic_sword, basic_armor}, rara);
Village dhqjs("오번 마을", 5, 11, {}, mari);
vector<Village> villageList = { dlfqjs, dlqjs, tkaqjs, tkqjs, dhqjs };