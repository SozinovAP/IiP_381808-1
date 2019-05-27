#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;
struct pos {
	int x, y;

	bool operator==(const pos& _O) const;//перегрузка сравнения
};
class shake
{
private:
	const int h = 16; //высота
	const int w = 16; //длина
	int speed = 95;//скорость
	int sizeShake;//длина змеи
	int score;//очки
	bool food;//
	pos Snake[50];//местоположение змеи
	pos Food; //местоположение еды
	char **Field;	//поле
public:
	shake();
	~shake();
	void CreateField();//создание игрового поля
	void CreateShake();//создание змейки
	void RedrawFieldAndShake();//перерисовка поля и змейки
	void Moving();//движение
	void CreateFood();//создание еды на поле
	void Eat();//работа с едой
	bool CheckGameOver();//проверка на конец игры

};
