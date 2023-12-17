#include "CommonInclude.h"
#include "Character.h"
#include "Item.h"
#include "Village.h"

int main(void)
{
	int choice;
	cout << "text RPG" << endl;
	while (true)
	{
		cout << endl;
		cout << "1. 시작하기" << endl;
		cout << "2. 종료하기" << endl;
		cout << "선택 : "; cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "시작합니다." << endl;
			break;
		case 2:
			cout << "종료합니다." << endl;
			return 0;
		default:
			cout << "유효하지 않은 숫자입니다. 다시 입력해주세요." << endl;
			break;
		}
	}
	return 0;
}