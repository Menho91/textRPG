#include "CommonInclude.h"
#include "System.h"

int main(void)
{
	int choice;
	cout << "text RPG" << endl << endl;
	cout << "1. �����ϱ�" << endl;
	cout << "2. �����ϱ�" << endl;
	cout << "���� : ";
	while (true)
	{
		choice = Choice(1, 2);
		cout << endl;

		switch (choice)
		{
		case 1:
			{
				cout << "�����մϴ�." << endl << endl;
				Player* player1 = NewPlayer();
				Prologue(*player1);
				Start(*player1);
				delete player1;
				break;
			}
		case 2:
			cout << "�����մϴ�." << endl;
			return 0;
		default:
			cout << "�ٽ� �Է����ּ���." << endl;
		}
	}
	return 0;
}