#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Bankomat.h"
#include "ProcCenter.h"



Bankomat::Bankomat()
{
	for (int i = 0; i < 5; i++)
	{
		CountBills[i] = Start;
	}
	ifstream is;
	is.open("C:/Users/alexs/Desktop/ИиПр!/IiP_381808 - 1/sozinov.ap/Task5/BaseClient.txt");
	is >> *User;
	is.close();

}
bool Bankomat::CardOnBank(int NumCard) //получить карту
{
	bool CheckClient = false; //проверка наличия клиента 
	UserActive.NumCard = NumCard;
	User->SearchUser(UserActive.NumCard, UserActive.family, UserActive.name, UserActive.patronymic, UserActive.SumUser, UserActive.PinUser, UserActive.BlockC, CheckClient);
	if (CheckClient)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Bankomat::PinCodCheck(int PinCod) //проверка верности пинкода
{
	if (UserActive.PinUser != PinCod)
	{
		if (Wrong > 0)
		{
			Wrong--;
			cout << "\nневерный пинкод, попыток осталось: " << Wrong << endl;
			if (Wrong == 0)
			{
				UserActive.BlockC = 1;
				User->BlockedCard(UserActive.BlockC, UserActive.NumCard);
				cout << "\nКарта заблокирована, вставьте другую карту\n";
				return false;
			}
			return false;
		}
		
	}
	else
	{
		return true;
	}
}
void Bankomat::OutInfoUser() //выдача информации о пользователе
{
	cout << "Состояние счета клиента" << endl;
	cout << "номер карты: " << UserActive.NumCard << endl;
	cout << "Баланс: " << UserActive.SumUser;
}
bool Bankomat::DepositOnCard(int SumDepos) //положить деньги
{

	if (SumDepos > 5000 * MaxBillsDepAndWit)
	{
		cout << "Превышен лимит по количеству купюр за 1 раз";
		return false;
	}
	while ((SumDepos >= 5000) && (CountBills[0] <= 2000))
	{
		CountBills[0]++;
		SumDepos -= 5000;
		UserActive.SumUser += 5000;
	}
	while ((SumDepos >= 2000)&& (CountBills[1] <= 2000))
	{
		CountBills[1]++;
		SumDepos -= 2000;
		UserActive.SumUser += 2000;
	}
	while ((SumDepos >= 1000) && (CountBills[2] <= 2000))
	{
		CountBills[2]++;
		SumDepos -= 1000;
		UserActive.SumUser += 1000;
	}
	while ((SumDepos >= 500) && (CountBills[3] <= 2000))
	{
		CountBills[3]++;
		SumDepos -= 500;
		UserActive.SumUser += 500;
	}
	while ((SumDepos >= 200) && (CountBills[4] <= 2000))
	{
		CountBills[4]++;
		SumDepos -= 200;
		UserActive.SumUser += 200;
	}
	while ((SumDepos >= 100) && (CountBills[5] <= 2000))
	{
		CountBills[5]++;
		SumDepos -= 100;
		UserActive.SumUser += 100;
	}
	if (SumDepos != 0)
	{
		cout << "из-за переполнения кассет терминала, не было внесено " << SumDepos << " рублей\n";
		cout << "Заберите не внесенные купюры" << endl;
	}
	return true;
}
bool Bankomat::WithdrawMoney(int SumWith) //снять деньги
{
	if (SumWith > UserActive.SumUser)
	{
		cout << "Не хватает средств на счёте";
		return false;
	}
	if (SumWith > 5000 * MaxBillsDepAndWit)
	{
		cout << "Превышен лимит по количеству выдаваемых купюр за 1 раз";
		return false;
	}
	if (SumWith > (CountBills[0] * 5000 + CountBills[1] * 2000 + CountBills[2] * 1000 + CountBills[3] * 500 + CountBills[4] * 200 + CountBills[5] * 100))
	{
		cout << "В терминале не хватает денег";
		return false;
	}
	UserActive.SumUser -= SumWith;
	while ((SumWith >= 5000) && (CountBills[0] >= 0))
	{
		CountBills[0]--;
		SumWith -= 5000;
	}
	while ((SumWith >= 2000) && (CountBills[1] >= 0))
	{
		CountBills[1]--;
		SumWith -= 2000;
	}
	while ((SumWith >= 1000) && (CountBills[2] >= 0))
	{
		CountBills[2]--;
		SumWith -= 1000;
	}
	while ((SumWith >= 500) && (CountBills[3] >= 0))
	{
		CountBills[3]--;
		SumWith -= 500;
	}
	while ((SumWith >= 200) && (CountBills[4] >= 0))
	{
		CountBills[4]--;
		SumWith -= 200;
	}
	while ((SumWith >= 100) && (CountBills[5] >= 0))
	{
		CountBills[5]--;
		SumWith -= 100;
	}
	return true;
}
bool Bankomat::BlockedCard(int NumCard) //проверка блокировки карты
{
	if (UserActive.BlockC == 0)
	{
		return true;
	}
	else
	{
		cout << "Карта заблокирована\n";
		return false;
	}
}
void Bankomat::ReturnCard() //вернуть карту
{
	User->ChangeUserInfo(UserActive.SumUser, UserActive.NumCard);
	UserActive = { 0, "", "", "", 0, 0, 0 };
	Wrong = 3;
}
