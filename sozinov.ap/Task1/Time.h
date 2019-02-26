#pragma once

#include <iostream>
using namespace std;

class Time
{
public:

	//Konstruktor po umolchaniyu
	Time(void);

	//Konstruktor inicializacii
	Time(unsigned char, unsigned char, unsigned char);

	//Konstruktor kopirovaniya
	Time(const Time&);

	//Konstruktor  preobrazovaniya stroki vida "12.24.35"
	Time(const char*);

	~Time();

	//Zapros strochnogo predstavleniya
	const char* GetString() const;

	//Metody dostupa
	unsigned char GetH() const { return hou; };
	unsigned char GetM() const { return min; };
	unsigned char GetS() const { return sec; };

	//Peregruzka operacii
	Time operator+(const Time&);
	Time operator-(const Time&);
	Time& operator=(const Time&);
	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;

	friend ostream& operator<<(ostream&, const Time&);
	friend istream& operator>>(istream&, Time&);


private:

	unsigned char hou, min, sec;
	char str[9];
	unsigned char Parse(const char*);		//Perevod iz strokovogo predstavleniya
	void ToString();
};

istream& operator>>(istream&, Time&);
ostream& operator<<(ostream&, const  Time&);

