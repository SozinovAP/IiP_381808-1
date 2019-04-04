#include <math.h>
#include <iostream>
#include "integral.h"

using namespace std;

integral::integral()
{
	a = 0;
	b = 0;
	n = 0;
	rez = 0;
}

integral::integral(double _A, double _B, int _N)
{
	a = _A;
	b = _B;
	n = _N;
	rez = 0;
}

integral::integral(const integral& _I)
{
	a = _I.a;
	b = _I.b;
	n = _I.n;
	rez = _I.rez;
}

integral::~integral()
{
	a = 0;
	b = 0;
	n = 0;
	rez = 0;
}

double integral::LeftRect(double(*Function)(double), const integral& _I)
{
	double len = (_I.b - _I.a) / _I.n;//длина одного отрезка
	double x = a;
	for (int i = 1; i <= _I.n; i++)
	{
    	rez += Function(x);
		x += len;
	}
	return rez;
}

double integral::RightRect(double(*Function)(double), const integral& _I)
{
	double len = (_I.b - _I.a) / _I.n;//длина одного отрезка
	double x = a + len;
	for (int i = 1; i <= _I.n; i++)
	{
		rez += Function(x);
		x += len;
	}
	return rez;
}

double integral::MiddleRect(double(*Function)(double), const integral& _I)
{
	double len = (_I.b - _I.a) / _I.n;//длина одного отрезка
	double x = a + len / 2;
	for (int i = 1; i <= _I.n; i++)
	{
		rez += Function(x);
		x += len;
	}
	return rez;
}