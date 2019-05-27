#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include "shake.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
Going:
	shake Go;
	cout << "1 - старт" << endl;
	cout << "2 - выход" << endl;
	int F;
	cin >> F;
	switch (F)
	{
	case 1:
		Go;
		Go.Moving();
		system("cls");
		goto Going;
		break;
	case 2:
		break;
	default:
		cout << "Введите цифру из меню" << endl;
		goto Going;
		break;
	}
	return 0;
}