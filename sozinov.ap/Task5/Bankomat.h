#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "ProcCenter.h"

using namespace std;



class Bankomat
{
	int Wrong = 3; //количество оставшихся попыток ввода пинкода
	ProcCenter *User = new ProcCenter();
	const int MaxBillsDepAndWit = 40; //максимальное кол-во купюр, которое может быть выдано/принято за раз
	const int MaxCountsBills = 2000; //максимальное количество купюр в кассете
	int Start = (int)(MaxCountsBills*0.8); //начальная загрузка кассет
	int CountBills[6];//количество купюр достоинства {5000, 2000, 1000, 500, 200, 100}
	struct
	{
		int NumCard;
		string family;
		string name;
		string patronymic;
		int SumUser;
		int PinUser;
		int BlockC;
	} UserActive;
public:
	
	Bankomat();       	

	bool CardOnBank(int NumCard); //получить карту
	bool PinCodCheck(int PinCod); //проверка верности пинкода
	void OutInfoUser(); //выдача информации о счете
	bool DepositOnCard(int SumDepos); //положить деньги
	bool WithdrawMoney(int SumWith); //снять деньги
	bool BlockedCard(int NumCard); //блокировка карты
	void ReturnCard(); //вернуть карту

};