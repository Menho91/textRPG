#include "CommonInclude.h"
#include "System.h"

int main(void)
{
	int choice;
	cout << "text RPG" << endl;
	while (true)
	{
		cout << endl;
		cout << "1. �����ϱ�" << endl;
		cout << "2. �����ϱ�" << endl;
		cout << "���� : "; cin >> choice;

		switch (choice)
		{
		case 1:
			{
				cout << "�����մϴ�." << endl << endl;
				Player* player1 = NewPlayer();
				Prologue(*player1);
				test(*player1);
				delete player1;
				break;
			}
		case 2:
			cout << "�����մϴ�." << endl;
			return 0;
		default:
			cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
			throw -1;
		}
	}
	return 0;
}