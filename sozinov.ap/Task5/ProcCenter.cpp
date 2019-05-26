#include <iostream>
#include <fstream>
#include <cstring>
#include "Bankomat.h"
#include "ProcCenter.h"



void ProcCenter::SearchUser(int _NumCard, string &_family, string &_Name, string &_patr, int &_SumUs, int &_PinUs, int &_Block, bool &_CheckClient)
{
	int i = 0;
	bool user = false;
	while ((i < CountUser) && (!user))
	{
		if (NumCard[i] == _NumCard)
		{
			_family = family[i];
			_Name = name[i];
			_patr = patronymic[i];
			_SumUs = SumUser[i];
			_PinUs = PinUser[i];
			_Block = BlockC[i];
			_CheckClient = true;
			user = true;
		}
	}
}
void ProcCenter::ChangeUserInfo(int _SumUser, int Card)
{
	int i = 0;
	bool user = false;
	while ((i < CountUser) && (!user))
	{
		if (NumCard[i] == Card)
		{
			SumUser[i] = _SumUser;
			user = true;
		}
	}
}
void ProcCenter::BlockedCard(int StatusBlock, int Card)//заблокровать карту 
{
	int i = 0;
	bool user = false;
	while ((i < CountUser) && (!user))
	{
		if (NumCard[i] == Card)
		{
			BlockC[i] = StatusBlock;
			user = true;
		}
	}
}
ostream& operator << (ostream & stream, const ProcCenter &_P)
{
	stream.clear();
	ifstream is;
	is.open("C:/Users/alexs/Desktop/ИиПр!/IiP_381808 - 1/sozinov.ap/Task5/BaseClient.txt");
	stream << _P.CountUser << " ";
	for (int i = 0; i < _P.CountUser; i++)
	{
		stream << _P.NumCard[i] << " " << _P.family[i] << " " << _P.name[i] << " " << _P.patronymic[i]
			<< " " << _P.SumUser[i] << " " << _P.PinUser[i] << " " << _P.BlockC[i] << " ";
	}
	is.close();
	return stream;
}
istream& operator >> (istream & stream, ProcCenter &_P) 
{
	ifstream is;
	is.open("C:/Users/alexs/Desktop/ИиПр!/IiP_381808 - 1/sozinov.ap/Task5/BaseClient.txt");
	stream >> _P.CountUser;
	int Count = _P.CountUser;
	delete[] _P.NumCard;
	delete[] _P.family;
	delete[] _P.name;
	delete[] _P.patronymic;
	delete[] _P.SumUser;
	delete[] _P.PinUser;
	delete[] _P.BlockC;

	_P.NumCard = new int[Count];
	_P.family = new string[Count];
	_P.name = new string[Count];
	_P.patronymic = new string[Count];
	_P.SumUser = new int[Count];
	_P.PinUser = new int[Count];
	_P.BlockC = new int[Count];

	for (int i = 0; i < _P.CountUser; i++)
	{
		stream >> _P.NumCard[i] >> _P.family[i] >> _P.name[i] >> _P.patronymic[i]
			>> _P.SumUser[i] >> _P.PinUser[i] >> _P.BlockC[i];
	}
	is.close();
	return stream;
}