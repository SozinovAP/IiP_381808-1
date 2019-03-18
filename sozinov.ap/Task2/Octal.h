#pragma once
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
class Octal
{
public:
	Octal();//конструктор по умолчанию
	Octal(int Len);//конструктор инициализации
	Octal(string ST);//конструктор преобразования типа
	Octal(const Octal& _Octal);//конструктор копирования
	~Octal();//деструктор
	int Leng(string ST);//длина числа
	void ToZero();//обнуление массива
	void MaxIMinLength(int Len1, int Len2);//определение максимальной и минимальной длины из 2 чисел
	void Del0(Octal& TMP);//удаление незначащих '0'
	//перегрузки

	//перегрузка "="
	Octal& operator=(const Octal& _Octal);
	//перегрузка "+"
	Octal operator+(const Octal& _Octal);
	//перегрузка "-"
	Octal operator-(const Octal& _Octal);
	//перегрузка "*"
	Octal operator*(const Octal& _OCtal);
	//перегрузка сравнений
	bool operator==(const Octal& _Octal);
	bool operator>(const Octal& _Octal);
	bool operator<(const Octal& _Octal);
	//перегрузка COUT
	friend ostream& operator<<(ostream& stream, const Octal& _Octal);
	//перегрузка CIN
	friend istream& operator>>(istream& stream, Octal& _Octal);


	int max, min;//значение максимальной и минимальной длин чисел(в операциях '+' и '-')
private:
	unsigned char *mass;
	int length;
};

