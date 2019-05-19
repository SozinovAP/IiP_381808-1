#include "Bankomat.h"
#include "ProcCenter.h"
#include <ostream>
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int Numb, pin, Sum;
	Bankomat Client;
returnC:
	cout << "1 - принять карту" << endl;
	cout << "2 - завершить работу" << endl;
	int job;
	cin >> job;
	switch (job)
	{
	case 1:
	{
		cout << "Номер карты: ";
		cin >> Numb;
		cout << endl << "пинкод: ";
		cin >> pin;
		Client.CardOnBank(Numb);
		if (!Client.BlockedCard(Numb))
		{
			Client.ReturnCard();
			goto returnC;
		}
		while (!Client.PinCodCheck(pin))
		{
			if (Client.BlockedCard(Numb))
			{
				cout << "пинкод: ";
				cin >> pin;
			}
			else
			{
				Client.ReturnCard();
				goto returnC;
			}
		}
		bool flag = true;
		while (flag)
		{
			cout << "\nМеню:\n";
			cout << "1 - Состояние счета\n";
			cout << "2 - Пополнить счет\n";
			cout << "3 - Снять со счета\n";
			cout << "0 - Вернуть карту\n";
			int menu;
			cin >> menu;
			switch (menu)
			{
			case 1:
			{
				Client.OutInfoUser();
				break;
			}
			case 2:
			{
				do
				{
					cout << "внесите наличные" << endl;
					cin >> Sum;
				} while (!Client.DepositOnCard(Sum));
				break;
			}
			case 3:
			{
				do
				{
					do
					{
						cout << "введите сумму, кратную 100" << endl;
						cin >> Sum;
						if (Sum % 100 != 0)
						{
							cout << "сумма должна быть кратна 100 " << endl;
						}
					} while (Sum % 100 > 0);
				} while (!Client.WithdrawMoney(Sum));
				break;
			}
			case 0:
			{
				flag = false;
				Client.ReturnCard();
				goto returnC;
			}
			}
		}
		break;
	}
	case 2:
	{
		cout << "заберите карту";
		break;
	}
	default:
	{
		cout << "введите цифру из списка";
		goto returnC;
	}
	}
}