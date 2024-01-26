#include "CommonInclude.h"
#include "System.h"

int main(void)
{
	int choice;
	cout << "text RPG" << endl << endl;
	cout << "1. 시작하기" << endl;
	cout << "2. 종료하기" << endl;
	cout << "선택 : ";
	while (true)
	{
		choice = Choice(1, 2);
		cout << endl;

		switch (choice)
		{
		case 1:
			{
				cout << "시작합니다." << endl << endl;
				Player* player1 = NewPlayer();
				Prologue(*player1);
				Start(*player1);
				delete player1;
				break;
			}
		case 2:
			cout << "종료합니다." << endl;
			return 0;
		default:
			cout << "다시 입력해주세요." << endl;
		}
	}
	return 0;
}