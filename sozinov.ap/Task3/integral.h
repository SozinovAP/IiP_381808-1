#pragma once
#include <math.h>
#include <iostream>

class integral
{
public:
	typedef double(*Function)(double);
	integral();
	integral(double _A, double _B, int _N);//конструктор инициализации
	integral(const integral& _I);//конструктор копирования
	~integral();

	double LeftRect(double(*Function)(double), const integral& _I);//метод левых прямоугольников
	double RightRect(double(*Function)(double), const integral& _I);//метод правых прямоугольников
	double MiddleRect(double(*Function)(double), const integral& _I);//метод средних прямоугольников

private:
	double a, b;//границы интегрирования
	double rez;//результат
	int n;//количество отреков разбиения	
};

