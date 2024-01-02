#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "CommonInclude.h"
#include "Character.h"
#include "Village.h"

Player* NewPlayer(void)
{
	string temp;
	cout << "새 캐릭터를 생성합니다." << endl;
	cout << "캐릭터 이름을 입력하세요." << endl;
	cout << "입력 : "; cin >> temp; cin.ignore();
	Player* player = new Player(temp);
	cout << player->GetName() << " 캐릭터가 생성되었습니다." << endl << endl;
	return player;
}

void Prologue(Player& player)
{
	cout << "지금으로부터 아주 오래전" << endl;
	cout << player.GetName() << "의 모험이" << endl;
	cout << "막 시작된다." << endl << endl;
}

void Start(Player& player)
{
	dlfqjs.Visit(player);
}
#endif