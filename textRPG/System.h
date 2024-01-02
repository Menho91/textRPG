#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "CommonInclude.h"
#include "Character.h"
#include "Village.h"

Player* NewPlayer(void)
{
	string temp;
	cout << "�� ĳ���͸� �����մϴ�." << endl;
	cout << "ĳ���� �̸��� �Է��ϼ���." << endl;
	cout << "�Է� : "; cin >> temp; cin.ignore();
	Player* player = new Player(temp);
	cout << player->GetName() << " ĳ���Ͱ� �����Ǿ����ϴ�." << endl << endl;
	return player;
}

void Prologue(Player& player)
{
	cout << "�������κ��� ���� ������" << endl;
	cout << player.GetName() << "�� ������" << endl;
	cout << "�� ���۵ȴ�." << endl << endl;
}

void Start(Player& player)
{
	dlfqjs.Visit(player);
}
#endif