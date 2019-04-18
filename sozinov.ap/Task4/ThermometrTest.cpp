#include "Thermometr.h"
#include <ostream>
#include <iostream>
#include <fstream>

using namespace std;
/*
8)сохранить историю наблюдений в файл,
9) считать историю наблюдений из файла.*/

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int Hour, Day, Month, Year;
	Thermometr Ter;
	cout << "Ввод данных производится в следующем виде:" << endl;
	cout << "день месяц год время температура" << endl;
	cout << "Введите число наблюдений и сами наблюдения" << endl;
	cin >> Ter;
	cout << "TEST\n Начало наблюдений:\n";
	cout << Ter.GetStartData();
	cout << "TEST\n Добавление наблюдения:\n Введите новое наблюдение" << endl;
	DataTemp A;
	cin >> A;
	Ter.Push_Observe(A);
	cout << "Проверка добавления" << endl;
	cout << Ter;
	cout << "TEST\n Узнать температуру по введенной дате" << endl;
	cout << "Введите дату:" << endl;
	cin >> Day >> Month >> Year >> Hour;
	DataTemp A1(Day, Month, Year, Hour, 0);
	cout << "температура:" << Ter.GetTemp(A1) << endl;
	cout << "TEST\n задать серию наблюдений для выбранной даты" << endl;
	cout << "Введите дату:" << endl;
	cin >> Day >> Month >> Year;
	DataTemp A2(Day, Month, Year, 0, 0);
	Ter.SeriesOfObservations(A2);
	cout << "TEST\n средняя температура" << endl;
	cout << "для выбранной даты\n Введите дату" << endl;
	cin >> Day >> Month >> Year;
	DataTemp A3(Day, Month, Year, 0, 0);
	cout << "Средняя температура = " << Ter.AverageTempDay(A3) << endl;
	cout << "для выбранного месяца\n введит месяц:" << endl;
	cin >> Month;
	cout << "Средняя температура = " << Ter.AverageTempMonth(Month) << endl;
	cout << "За все время" << endl;
	cout << "средняя температура = " << Ter.AverageAllTimes() << endl;
	cout << "днем для выбранного месяца\n введит месяц:" << endl;
	cin >> Month;
	cout << "Средняя температура = " << Ter.AverageDaytimeTemp(Month) << endl;
	cout << "ночью для выбранного месяца\n введит месяц:" << endl;
	cin >> Month;
	cout << "Средняя температура = " << Ter.AverageNightTemp(Month) << endl;
	cout << "TEST\n Работа с файлами" << endl;
	ofstream out;
	out.open("Thermometr.txt");
	out << Ter;
	out.close();
	Thermometr TestFile;
	ifstream in;
	in.open("Thermometr.txt");
	in >> TestFile;
	in.close();
	cout << "Из файла было считано следущее:" << TestFile << endl;
	getchar();
	getchar();
}