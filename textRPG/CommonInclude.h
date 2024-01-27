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
		cout << "선택 : ";
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
					throw out_of_range("범위를 초과하였습니다.");
				}
			}
			else
			{
				throw invalid_argument("알 수 없는 오류입니다.");
			}
		}
		catch (const out_of_range& e)
		{
			cout << e.what() << " 다시 선택해주세요." << endl;
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << " 숫자만 넣어주세요." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
	return choice;
}