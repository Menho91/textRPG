#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "CommonInclude.h"
#include "Conversation.h"
#include "Character.h"

Player& NewPlayer(void)
{
	string temp;
	cout << "�� ĳ���͸� �����մϴ�." << endl;
	cout << "ĳ���� �̸��� �Է��ϼ���." << endl;
	cout << "�Է� : "; cin >> temp;
	Player player(temp);
	cout << player.GetName() << " ĳ���Ͱ� �����Ǿ����ϴ�." << endl << endl;
	return player;
}

void Prologue(Player& player)
{
	cout << "�������κ��� ���� ������" << endl;
	cout << player.GetName() << "�� ������" << endl;
	cout << "�� ���۵ȴ�." << endl << endl;
}

void test(Player& player)
{
	for (int i = 0; i < 3; i++)
	{
		Monster mon("�̸� �� ����", 5, 5, 1);
		player.Fight(mon);
	}
}
#endif