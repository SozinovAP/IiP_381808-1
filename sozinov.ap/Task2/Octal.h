#pragma once
#include <string>
#include <iostream>
#include <fstream>

/*—оздать класс Octal дл€ работы с беззнаковыми целыми восьмеричными числами, использу€ дл€ представлени€ числа массив 
элементов типа unsigned char, каждый элемент которого €вл€етс€ восьмеричной цифрой. ћладша€ цифра имеет меньший индекс 
(единицы Ч в нулевом элементе массива). –азмер массива задаетс€ как аргумент конструктора.*/
using namespace std;
class Octal
{
public:
	Octal();//konstryctor po ymolchaniy
	Octal(int Len);//konstryctor initializacii
	Octal(string ST);//konstryctor preobrazovanya tipa
	Octal(const Octal& _Octal);//konstryctor kopirovaniya
	~Octal();//destryctor
	void MaxIMinLength(int Len1, int Len2);//polychenie max i min dliny chisla
	int Leng(string ST);//dlina chisla
	void ToZero();//obnylenye massiva
	void Del0(Octal& TMP);//ydalenye neznacyashix '0'
	//peregryzki

	//peregryzka "="
	Octal& operator=(const Octal& _Octal);
	//peregryzka "+"
	Octal operator+(const Octal& _Octal);
	//peregryzka "-"
	Octal operator-(const Octal& _Octal);
	//peregryzka "*"
	Octal operator*(const Octal& _OCtal);
	//peregryzka sravnenii
	bool operator==(const Octal& _Octal);
	bool operator>(const Octal& _Octal);
	bool operator<(const Octal& _Octal);
	//peregryzka COUT
	friend ostream& operator<<(ostream& stream, const Octal& _Octal);
	//peregryzka CIN
	friend istream& operator>>(istream& stream, Octal& _Octal);


	int max, min;//max i min dliny chisel. Ispol`zyetcya v '+', '-', '*'
private:
	unsigned char *mass;
	int length;
};

