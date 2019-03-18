#include "Octal.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	Octal c1, c2, c3, c4;
	cout << "Vvod 1 chisla: ";
	cin >> c1;
	cout << "vvod 2 chisla: ";
	cin >> c2;
	cout << " summa = " << c1 + c2 << endl;
	cout << "raznost` = " << c1 - c2 << endl;
	cout << "proizvedenye = " << c1 * c2 << endl;
	cout << "1 chislo = " << c1 << endl;
	cout << "2 chislo = " << c2 << endl;
	if (c1 == c2)
	{
		cout << "chisla ravni" << endl;
	}
	else
	{
		if (c1 > c2)
		{
			cout << "chislo 1 bolshe chisla 2" << endl;
		}
		else
		{
			cout << "chislo 2 bolshe chisla 1" << endl;
		}
	}

	cout << "Vvod dvyx chisel dlya proverki zapici v fail i chtenya iz faila" << endl;
	ofstream in("Test.txt");
	cin >> c3; 
	cin >> c4;
	in << c3 << endl;
	in << c4;
	in.close();
	ifstream out("Test.txt");
	out >> c3;
	out >> c4;
	cout << "Iz faila bylo prochitano" << endl;
	cout << c3 << endl;
	cout << c4;
}