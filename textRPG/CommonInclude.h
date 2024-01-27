#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

static int Choice(int left, int right)
{
	int choice;
	while (true)
	{
		cout << "���� : ";
		try
		{
			if (cin >> choice)
			{
				if (choice >= left && choice <= right)
				{
					break;
				}
				else
				{
					throw out_of_range("������ �ʰ��Ͽ����ϴ�.");
				}
			}
			else
			{
				throw invalid_argument("�� �� ���� �����Դϴ�.");
			}
		}
		catch (const out_of_range& e)
		{
			cout << e.what() << " �ٽ� �������ּ���." << endl;
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << " ���ڸ� �־��ּ���." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
	return choice;
}