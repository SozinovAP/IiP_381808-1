#include "Thermometr.h"
#include <iostream>

using namespace std;



DataTemp::DataTemp()//конструктор по умолчанию
{
	hou = day = mon = year = 0;
	T = 0;
}

DataTemp::DataTemp(int DAY, int MON, int YEAR, int HOU, double Temp)//конструктор копирования
{
	hou = HOU;
	day = DAY;
	mon = MON;
	year = YEAR;
	T = Temp;
}

DataTemp::~DataTemp()//деструктор
{
	hou = day = mon = year = 0;
	T = 0;
};

//перегрузка COUT
ostream& operator<< (ostream& stream, const DataTemp& Date)
{
	stream << Date.day << " " << Date.mon << " " << Date.year << " " << Date.hou << " " << Date.T;
	return stream;
}
//перегрузка CIN
istream& operator>> (istream& stream, DataTemp& Date)
{
	stream >> Date.day >> Date.mon >> Date.year >> Date.hou >> Date.T;
	return stream;
}


Thermometr::Thermometr()
{
	size = MaxSize = 0;
	ArrayObserve = NULL;
}

Thermometr::Thermometr(int _size)//конструктор копирования
{
	size = _size;
	MaxSize = _size + DelSize;
	ArrayObserve = new DataTemp[MaxSize];
}

Thermometr::~Thermometr()
{
	size = MaxSize = 0;
	delete[] ArrayObserve;
}


DataTemp Thermometr::GetStartData()//установка начальной даты
{
	return ArrayObserve[0];
}

void Thermometr::Add_Observe(DataTemp _Observe)//добавление наблюдения 
{
	if (size < MaxSize)
	{
		ArrayObserve[size] = _Observe;
		size++;
	}
	else
	{
		MaxSize += DelSize;
		DataTemp* TmpArray = new DataTemp[MaxSize];
		for (int i = 0; i < size; i++)
		{
			TmpArray[i] = ArrayObserve[i];
		}
		TmpArray[size] = _Observe;
		delete[] ArrayObserve;
		ArrayObserve = TmpArray;
		size++;
	}
}

int Thermometr::GetTemp(DataTemp _Data)//получить температуру в выбранную дату
{
	bool F = true;
	int i = 0;
	double Temperature;
	while ((i < size) && (F))
	{
		DataTemp Check = ArrayObserve[i];
		if ((Check.day == _Data.day) && (Check.mon == _Data.mon) && (Check.year == _Data.year) && (Check.hou == _Data.hou))
		{
			F = false;
			Temperature = Check.T;
		}
		i++;
	}
	if (!F)
	{
		return Temperature;
	}
	else
	{
		return NULL;
	}
}

void Thermometr::SeriesOfObservations(DataTemp _Data)//выдать серию наблюдений по дате
{
	bool F = true;
	int Serios;
	cout << "Серия наблююдений за " << _Data.day << "." << _Data.mon << "." << _Data.year << endl;
	for (int i = 0;i < size; i++)
	{
		DataTemp Check = ArrayObserve[i];
		if ((Check.day == _Data.day) && (Check.mon == _Data.mon) && (Check.year == _Data.year))
		{
			F = false;
			cout << Check.hou << " Часов - Температура = " << Check.T << endl;
		}
	}
	if (F)
	{
		cout << "Для данной даты нет наблюдений" << endl;
    }
}

//Средние температуры
double Thermometr::AverageTempDay(DataTemp _Data)//в выбранный день
{
	double AverageT = 0;//средняя температура
	int kolvo = 0;//количество измерений в течении дня
	for (int i = 0; i < size; i++)
	{
		DataTemp Check = ArrayObserve[i];
		if ((Check.day == _Data.day) && (Check.mon == _Data.mon) && (Check.year == _Data.year))
		{
			kolvo++;
			AverageT += Check.T;
		}
	}
	if (kolvo > 0)
	{
		AverageT = AverageT / kolvo;
	}
	return AverageT;
}

double Thermometr::AverageTempMonth(int _Month)//в выбранный месяцц
{
	double AverageT = 0;//средняя температура
	int kolvo = 0;//количество измерений в течении месяца
	for (int i = 0; i < size; i++)
	{
		DataTemp Check = ArrayObserve[i];
		if (Check.mon == _Month)
		{
			kolvo++;
			AverageT += Check.T;
		}
	}
	if (kolvo > 0)
	{
		AverageT = AverageT / kolvo;
	}
	return AverageT;
}

double Thermometr::AverageAllTimes()//за все время
{
	double AverageT = 0;//средняя температура
	int kolvo = 0;//количество измерений за все время
	for (int i = 0; i < size; i++)
	{
		AverageT += ArrayObserve[i].T;
		kolvo++;
	}
	AverageT = AverageT / kolvo;
	return AverageT;
}

double Thermometr::AverageDaytimeTemp(int _Month)//днем в выбранном месяце
{
	double AverageT = 0;//средняя температура
	int kolvo = 0;//количество измерений днем в течении месяца
	for (int i = 0; i < size; i++)
	{
		DataTemp Check = ArrayObserve[i];
		if ((Check.mon == _Month) && (Check.hou > 7) && (Check.hou < 20))
		{
			kolvo++;
			AverageT += Check.T;
		}
	}
	if (kolvo > 0)
	{
		AverageT = AverageT / kolvo;
	}
	return AverageT;
}

double Thermometr::AverageNightTemp(int _Month)//ночью в выбранном месяце
{
	double AverageT = 0;//средняя температура
	int kolvo = 0;//количество измерений ночью в течении месяца
	for (int i = 0; i < size; i++)
	{
		DataTemp Check = ArrayObserve[i];
		if ((Check.mon == _Month) && ((Check.hou <= 7) || (Check.hou >= 20)))
		{
			kolvo++;
			AverageT += Check.T;
		}
	}
	if (kolvo > 0)
	{
		AverageT = AverageT / kolvo;
	}
	return AverageT;
}

int Thermometr::Get_Size()
{
	return size;
}

//перегрукза COUT
ostream& operator<< (ostream& stream, const Thermometr& _T)
{
	stream << _T.size << endl;
	for (int i = 0; i < _T.size; i++)
	{
		stream << _T.ArrayObserve[i] << endl;
	}
	return stream;
}
//перегузка CIN
istream& operator>> (istream& stream, Thermometr& _T)
{
	stream >> _T.size;
	if (_T.size >= _T.MaxSize)
	{
		delete[] _T.ArrayObserve;
		_T.MaxSize += _T.DelSize;
		_T.ArrayObserve = new DataTemp[_T.size];
	}
	for (int i = 0; i < _T.size; i++)
	{
		stream >> _T.ArrayObserve[i];
	}
	return stream;
}
