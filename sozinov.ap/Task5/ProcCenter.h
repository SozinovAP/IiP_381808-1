#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Bankomat.h"

using namespace std;

class ProcCenter
{
	int CountUser;
	int *NumCard;
	string *family;
	string *name;
	string *patronymic;
	int *SumUser;
	int *PinUser;
	int *BlockC;

public:
	void SearchUser(int _NumCard, string &_family, string &_Name, string &_patr, int &_SumUs, int &_PinUs, int &_Block, bool &_CheckClient); //поиск клиента
	void ChangeUserInfo(int _SumUser, int Card); //изменение информации о счете
	void BlockedCard(int StatusBlock, int Card);//заблокровать карту 

	friend ostream & operator<< (ostream & stream, const ProcCenter &_P);
	friend istream & operator>> (istream & stream, ProcCenter &_P);
};
ostream & operator<< (ostream & stream, const ProcCenter &_P);
istream & operator>> (istream & stream, ProcCenter &_P);