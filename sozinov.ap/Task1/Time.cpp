#pragma once
#include "Time.h"
#include <iostream>

using namespace std;


Time::Time()
{
	hou = min = sec = 0;
	ToString();
}


Time::Time(unsigned char hou, unsigned char min, unsigned char sec)
{
	this->hou = hou;
	this->min = min;
	this->sec = sec;
	ToString();
}

Time::Time(const Time& t)
{
	hou = t.hou;
	min = t.min;
	sec = t.sec;
	ToString();
}

Time::Time(const char* c)
{
	hou = Parse(c);
	min = Parse(c + 3);
	sec = Parse(c + 6);
	ToString();
}

Time::~Time()
{
	hou = min = sec = 0;
}

const char* Time::GetString() const
{
	return str;
}

void Time::ToString()
{
	str[0] = (char)(hou / 10 + '0');
	str[1] = (char)(hou % 10 + '0');
	str[2] = '.';
	str[3] = (char)(min / 10 + '0');
	str[4] = (char)(min % 10 + '0');
	str[5] = '.';
	str[6] = (char)(sec / 10 + '0');
	str[7] = (char)(sec % 10 + '0');
	str[8] = '\0';
}

unsigned char Time::Parse(const char* str)
{
	unsigned char rez = 0;
	int i = 0;
	while (str[i] != 0 && str[i] != '.')
	{
		rez = rez * 10 + (str[i] - '0');
		i++;
	}
	return rez;
}

Time Time::operator+(const Time& c)
{
	Time tmp;
	if (sec + c.sec > 60)
	{
		tmp.min++;
		tmp.sec = (sec + c.sec) - 60;
	}
	else
		tmp.sec = sec + c.sec;
	if (min + c.min > 60)
	{
		tmp.hou++;
		tmp.min = (min + c.min) - 60;
	}
	else
		tmp.min = min + c.min;
	if (hou + c.hou > 24)
	{
		tmp.hou = (hou + c.hou) - 24;
	}
	else
		tmp.hou = hou + c.hou;
	return tmp;
}


Time Time::operator-(const Time& c)
{
	Time tmp;
	bool fs = false,
		fm = false; //fs i fm  ykazivayt, bil li zaim v razryade
	if (sec < c.sec)
	{
		fs = true;
		tmp.sec = (sec - c.sec) + 60;
	}
	else
		tmp.sec = sec - c.sec;
	if (min - (fs ? 1 : 0) < c.min)
	{
		fm = true;
		tmp.min = (min - (fs ? 1 : 0) - c.min) + 60;
	}
	else
		tmp.min = min - (fs ? 1 : 0) - c.min;
	if (hou - (fm ? 1 : 0) < c.hou)
	{
		tmp.hou = (hou - (fm ? 1 : 0) - c.hou) + 24;
	}
	else
		tmp.hou = hou - (fm ? 1 : 0) - c.hou;
	return tmp;

}


Time& Time::operator=(const Time& c)
{
	if (this != &c)
	{
		hou = c.hou;
		min = c.min;
		sec = c.sec;
		for (int i = 0; i < 9; i++)
		{
			str[i] = c.str[i];
		}
	}
	return *this;
}


bool Time::operator>(const Time& c) const
{
	if (hou < c.hou) return false;
	if (min < c.hou) return false;
	if (sec < c.sec) return false;
	return true;
}

bool Time::operator<(const Time& c) const
{
	if (hou > c.hou) return false;
	if (min > c.hou) return false;
	if (sec > c.sec) return false;
	return true;
}

bool Time::operator==(const Time& c) const
{
	if (hou == c.hou && min == c.min && sec == c.min) return true;
	return false;
}


bool Time::operator!=(const Time& c) const
{
	if (hou != c.hou) return true;
	if (min != c.min) return true;
	if (sec != c.sec) return true;
	return false;
}



ostream& operator<<(ostream& stream, const Time& c)
{
	stream << c.GetString();
	return stream;
}



istream& operator>>(istream& stream, Time& c)
{
	char str[9];
	stream.getline(str, 9);
	c = str;
	return stream;
}