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
		cout << "1. �����ϱ�" << endl;
		cout << "2. �����ϱ�" << endl;
		cout << "���� : "; cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "�����մϴ�." << endl;
			break;
		case 2:
			cout << "�����մϴ�." << endl;
			return 0;
		default:
			cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
			break;
		}
	}
	return 0;
}