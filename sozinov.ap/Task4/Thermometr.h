#pragma once
#include <ostream>

using namespace std;

class DataTemp
{
private:
	int hou;//часы
	int day;//день
	int mon;//месяц
	int year;//год
	double T;//температура
public:
	DataTemp();//конструктор по умолчанию
	DataTemp(int DAY, int MON, int YEAR, int HOU, double Temp);//конструктор копирования
	~DataTemp();//деструктор


	friend ostream& operator<< (ostream& stream, const DataTemp& Date);//перегрукза COUT
	friend istream& operator>> (istream& stream, DataTemp& Date);//перегузка CIN
	friend class Thermometr;
};

class Thermometr
{
private:
	int size;//текущая длина массива
	int MaxSize;//максимальная длина
	const int DelSize = 7;//на сколько увеличивается длина массива при нехватке длины
	DataTemp* ArrayObserve;//массив наблюдений
public:
	Thermometr();
	Thermometr(int _size);//конструктор копирования
	~Thermometr();

	DataTemp GetStartData();//установка начальной даты
	void Add_Observe(DataTemp _Observe);//добавление наблюдения
	int GetTemp(DataTemp _Data);//получить температуру в выбранную дату
	void SeriesOfObservations(DataTemp _Data);//выдать серию наблюдений по дате

	//средняя температура
	double AverageTempDay(DataTemp _Data);//в выбранный день
	double AverageTempMonth(int _Month);//в выбранный месяцц
	double AverageAllTimes();//за все время
	double AverageDaytimeTemp(int _Month);//днем в выбранном месяце
	double AverageNightTemp(int _Month);//ночью в выбранном месяце

	int Get_Size();


	friend ostream& operator<< (ostream& stream, const Thermometr& _T);//перегрукза COUT
	friend istream& operator>> (istream& stream, Thermometr& _T);//перегузка CIN
	friend class DataTemp;
};