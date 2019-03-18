#include "Octal.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


Octal::Octal()//konstryctor po ymolchaniy
{
	length = 0;
	mass = NULL;
}
Octal::Octal(int Len)//конструктор инициализации
{
	length = Len;
	mass = new unsigned char[length];
}

Octal::Octal(string ST)//konstryctor preobrazovanya tipa
{
	length = Leng(ST);
	mass = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		mass[i] = ST[length - 1 - i] - '0';
	}
}

Octal::Octal(const Octal& _Octal)//konstryctor kopirovaniya
{
	length = _Octal.length;
	mass = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		mass[i] = _Octal.mass[i];
	}
}

Octal::~Octal()//destryctor
{
	length = 0;
	mass = NULL;
}

int Octal::Leng(string ST)//dlina chisla
{
	int i = length = 0;
	while (ST[i])
	{
		length++;
		i++;
	}
	return length;
}

void Octal::ToZero()//obnylenye massiva
{
	for (int i = 0; i < length; i++)
	{
		mass[i] = 0;
	}
}

void Octal::MaxIMinLength(int Len1, int Len2)//polychenie max i min dliny chisla
{

	if (Len1 > Len2)
	{
		max = Len1;
		min = Len2;
	}
	else
	{
		if (Len1 < Len2)
		{
			max = Len2;
			min = Len1;
		}
		else
		{
			max = min = Len1;
		}
	}
}

void Octal::Del0(Octal &TMP)//ydalenye neznacyashix '0'
{
	int i = TMP.length - 1;
	int k = 0;
	do
	{
		i--;
		k++;
	} while (TMP.mass[i] == 0);
	TMP.length = TMP.length - k;
}
//peregryzki

//peregryzka "="
Octal& Octal::operator=(const Octal& _Octal)
{

	if (this != &_Octal)
	{
		if (_Octal.length != length)
		{
			delete[] mass;
			length = _Octal.length;
			mass = new unsigned char[length];
		}
		for (int i = 0; i < length; i++)
		{
			mass[i] = _Octal.mass[i];
		}
	}
	return *this;
}
//peregryzka "+"
Octal Octal::operator+(const Octal& _Octal)
{
	MaxIMinLength(length, _Octal.length);
	Octal Sum(max);
	int tmp = 0;
	for (int i = 0; i < max; i++)
	{		
		if (i < min)
		{
			Sum.mass[i] = (tmp + mass[i] + _Octal.mass[i]) % 8;
			tmp = (tmp + mass[i] + _Octal.mass[i]) / 8;
		}
		else
		{
			if (i < _Octal.length)
			{
				Sum.mass[i] = (_Octal.mass[i] + tmp) % 8;
				tmp = (_Octal.mass[i] + tmp) / 8;
			}
			else
			{
				Sum.mass[i] = (mass[i] + tmp) % 8;
				tmp = (mass[i] + tmp) / 8;
			}
		}
	}
	return Sum;
}
//peregryzka "-"
Octal Octal::operator-(const Octal& _Octal)
{
	MaxIMinLength(length, _Octal.length);
	Octal Raz(max);
	int tmp = 0;
	for (int i = 0; i < min; i++)
	{
		if ((mass[i] + tmp) < _Octal.mass[i])
		{
			Raz.mass[i] = mass[i] + 8 + tmp - _Octal.mass[i];
			tmp = -1;
		}
		else
		{
			Raz.mass[i] = mass[i] + tmp - _Octal.mass[i];
			tmp = 0;
		}
	}
	if (length != _Octal.length)
	{
		if (length > _Octal.length)
		{
			for (int i = _Octal.length; i < length; i++)
			{
				if (tmp == -1)
				{
					if (mass[i] == 0)
					{
						Raz.mass[i] = 7;
					}
					else
					{
						Raz.mass[i] = mass[i] + tmp;
						tmp = 0;
					}
				}
				else
				{
					Raz.mass[i] = mass[i];
				}
			}
		}
		else
		{
			for (int i = length; i < _Octal.length; i++)
			{
				if (tmp == -1)
				{
					if (_Octal.mass[i] == 0)
					{
						Raz.mass[i] = 7;
					}
					else
					{
						Raz.mass[i] = _Octal.mass[i] + tmp;
						tmp = 0;
					}
				}
				else
				{
					Raz.mass[i] = _Octal.mass[i];
				}
			}
		}
	}
	if (Raz.mass[Raz.length - 1] == 0)
	{
		Del0(Raz);
	}
	return Raz;
}
//peregryzka "*"
Octal Octal::operator*(const Octal& _Octal)
{
	Octal proizv(length + _Octal.length);
	proizv.ToZero();
	int tmp = 2;
	int t;
	for (int i = 0; i < _Octal.length; i++)
	{
		for (int j = 0; j < length; j++)
		{
				if (((proizv.mass[i + j + 1] + (_Octal.mass[i] * mass[j] + proizv.mass[j + i]) / 8)) > 7)
				{
					proizv.mass[j + i + 1] = (proizv.mass[i + j + 1] + (_Octal.mass[i] * mass[j] + proizv.mass[j + i]) / 8) % 8;
					t = 1;
				}
				else
				{
					proizv.mass[j + i + 1] = (proizv.mass[i + j + 1] + (_Octal.mass[i] * mass[j] + proizv.mass[j + i]) / 8);
					t = 0;
				}
			proizv.mass[j + i] = (_Octal.mass[i] * mass[j] + proizv.mass[j + i]) % 8;
			while ((t == 1) && ((tmp + i + j) < proizv.length))
			{
				if ((proizv.mass[i + j + tmp] + t) == 8)
				{
					proizv.mass[i + j + tmp] = 0;
					t = 1;
				}
				else
				{
					proizv.mass[i + j + tmp] = proizv.mass[i + j + tmp] + t;
					t = 0;
				}
				tmp++;
			}
			tmp = 2;
		}
	}
	if (proizv.mass[proizv.length - 1] == 0)
	{
		Del0(proizv);
	}
	return proizv;
}

//peregryzki sravnenii
bool Octal::operator==(const Octal& _Octal)
{
	if (length == _Octal.length)
	{
		for (int i = 0; i < length; i++)
		{
			if (mass[i] != _Octal.mass[i])
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Octal::operator>(const Octal& _Octal)
{
	if (length > _Octal.length)
	{
		return true;
	}
	if (length < _Octal.length)
	{
		return false;
	}
	for (int i = length - 1; i >= 0; i--)
	{
		if (mass[i] <= _Octal.mass[i])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool Octal::operator<(const Octal& _Octal)
{
	if (length < _Octal.length)
	{
		return true;
	}
	if (length > _Octal.length)
	{
		return false;
	}
	for (int i = length - 1; i >= 0; i--)
	{
		if (mass[i] >= _Octal.mass[i])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

//peregryzka COUT
ostream& operator<<(ostream& stream, const Octal& _Octal)
{
	for (int i = _Octal.length - 1; i >=0; i--)
	{
		stream << (int)(_Octal.mass[i]);
	}
	return stream;
}
//peregryzka CIN
istream& operator>>(istream& stream, Octal& _Octal)
{
	string str;
	stream >> str;
	_Octal = str;
	return stream;
}



