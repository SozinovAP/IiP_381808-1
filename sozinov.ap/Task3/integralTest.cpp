#include <clocale>
#include <iostream>
#include <string>
#include "integral.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double a1, b1;//границы интегрирования
	double Itog;//итог интегрирования
	int n1;//количество отрезков разбиения
	integral::Function F = 0;
	string FuncText;//текстовое представление функции
	cout << "Введите границы интеграла " << endl;
	cin >> a1 >> b1;
	cout << "введите количество отреков рабиения" << endl;
	cin >> n1;
	integral I(a1, b1, n1);
	Metka1:
	cout << "Выбор вида функции:\n 1 - sin(x)\n 2 - cos(x)\n 3 - exp" << endl;
	int tmp; //переменная для выбора вида интегрируемой функции и метода вычисления
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		F = sin;
		FuncText = "sin(x)";
		break;
	case 2:
		F = cos;
		FuncText = "cos(x)";
		break;
	case 3:
		F = exp;
		FuncText = "exp(x)";
		break;
	default:
		cout << "Пожалуйста, выберите цифру из списка\n";
		goto Metka1;
	}
	Metka2:
	cout << "выбор метода вычисления:" << endl;
	cout << "1 - метод левых прямоугольников" << endl;
	cout << "2 - метод средних прямоугольников" << endl;
	cout << "3 - метод правых прямоугольников" << endl;
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		Itog = I.LeftRect(F, I);
		break;
	case 2:
		Itog = I.MiddleRect(F, I);
		break;
	case 3:
		Itog = I.RightRect(F, I);
		break;
	default:
		cout << "Пожалуйста, выберите цифру из списка\n";
		goto Metka2;
	}
	cout << "интеграл функци " << FuncText << " в заданном интервале:" << Itog;
}