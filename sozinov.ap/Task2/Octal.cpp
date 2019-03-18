#include "Octal.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


Octal::Octal()//конструктор по умолчанию
{
	length = 0;
	mass = NULL;
}

Octal::Octal(int Len)//конструктор инициализации
{
	length = Len;
	mass = new unsigned char[length];
}

Octal::Octal(string ST)//конструктор преобразования типа
{
	length = Leng(ST);
	mass = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		mass[i] = ST[length - 1 - i] - '0';
	}
}

Octal::Octal(const Octal& _Octal)//конструктор копирования
{
	length = _Octal.length;
	mass = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		mass[i] = _Octal.mass[i];
	}
}

Octal::~Octal()//деструктор
{
	length = 0;
	mass = NULL;
}

int Octal::Leng(string ST)//длина числа
{
	int i = length = 0;
	while (ST[i])
	{
		length++;
		i++;
	}
	return length;
}

void Octal::ToZero()//обнуление массива
{
	for (int i = 0; i < length; i++)
	{
		mass[i] = 0;
	}
}

void Octal::MaxIMinLength(int Len1, int Len2)//определение максимальной и минимальной длины из 2 чисел
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

void Octal::Del0(Octal &TMP)//удаление незначащих '0'
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
//перегрузки

//перегрузка "="
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
//перегрузка "+"
Octal Octal::operator+(const Octal& _Octal)
{
	MaxIMinLength(length, _Octal.length);
	Octal Sum(max + 1);//+1 необходимо для таких случаев, когда при сложении 2 чисел длинна суммы больше
	//длины наибольшего числа.(Пример: 777 + 1 = 1000)
	int tmp = 0;//переменная перехода в следующий разряд
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
	//если после выполнения предыдущего цикла длина суммы больше длины наибольшего числа( пример:
	//777 + 1 = 1000), необходимо самый старший разряд суммы сделать равным 1.
	if (tmp == 1)
	{
		Sum.mass[Sum.length - 1] = 1;
	}
	else
	{
		Sum.length--;
	}
	return Sum;
}
//перегрузка "-"
Octal Octal::operator-(const Octal& _Octal)
{
	MaxIMinLength(length, _Octal.length);
	Octal Raz(max);
	int tmp = 0;//переменная займа из разряда
	for (int i = 0; i < max; i++)
	{
		//mass[i] - _octal.mass[i] = delta
		int delta;
		if (i < length)//проверка на выход за пределы массива
		{
			delta = mass[i];
		}
		else
		{
			delta = 0;
		}
		if (i < _Octal.length)//проверка на выход за пределы массива
		{
			delta = delta - _Octal.mass[i];
		}

		if (delta + tmp < 0)
		{
			Raz.mass[i] = 8 + delta + tmp;
			tmp = -1;
		}
		else
		{
			Raz.mass[i] = delta + tmp;
			tmp = 0;
		}
	}
	if (Raz.mass[Raz.length - 1] == 0)//удаление незначащих 0
	{
		Del0(Raz);
	}
	return Raz;
}
//перегрузка "*"
Octal Octal::operator*(const Octal& _Octal)
{
	Octal proizv(length + _Octal.length);
	proizv.ToZero();//обнуление массива с результатом
	int tmp = 2;
	int t;//переменная перехода в следующий разряд
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
	//удаление незначащих нулей
	if (proizv.mass[proizv.length - 1] == 0)
	{
		Del0(proizv);
	}
	return proizv;
}

//перегрузка сравнений
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
	for (int i = _Octal.length - 1; i >= 0; i--)
	{
		if (mass[i] < _Octal.mass[i])
		{
			return false;
		}
	}
	return true;
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
		if (mass[i] > _Octal.mass[i])
		{
			return false;
		}
	}
	return true;
}

//перегрузка COUT
ostream& operator<<(ostream& stream, const Octal& _Octal)
{
	for (int i = _Octal.length - 1; i >=0; i--)
	{
		stream << (int)(_Octal.mass[i]);
	}
	return stream;
}
//перегрузка CIN
istream& operator>>(istream& stream, Octal& _Octal)
{
	string str;
	stream >> str;
	_Octal = str;
	return stream;
}



