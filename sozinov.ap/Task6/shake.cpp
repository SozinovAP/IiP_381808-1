#include "shake.h"

shake::shake()
{
	Field = new char*[h];
	for (int i = 0; i < h; i++)
	{
		Field[i] = new char[w];
	}
	sizeShake = 5;
	food = false;
	score = 0;
	//создание поля, змеи и еды
	CreateField();
	CreateShake();
	while (!food)
	{
		CreateFood();
	}
}
//создание змейки
void shake::CreateShake()
{
	Snake[0] = { 6 + rand() % (w - 6), 1 + rand() % (h - 2) };
	for (int i = 1; i < sizeShake; i++)
	{		
		Snake[i] = { Snake[i - 1].x + 1, Snake[i - 1].y };
	}
	for (int i = 3; i < 50; i++)
	{
		Snake[i] = { 0,0 };
	}
	Field[Snake[0].y][Snake[0].x] = '+';
	for (int i = 1; i < sizeShake; i++)
	{
		Field[Snake[i].y][Snake[i].x] = '@';
	}
}
//создание игрового поля
void shake::CreateField()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)		
		{
			Field[0][j] = '-';
			Field[h - 1][j] = '-';
			Field[i][0] = '|';
			Field[i][w - 1] = '|';
		}
	}
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			Field[i][j] = ' ';
		}
	}
}
//перерисовка поля и змейки
void shake::RedrawFieldAndShake()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { 0, 0 };
	SetConsoleCursorPosition(hOut, Position);
	cout << "	 Очки: " << score << " из 40";
	for (int i = 0; i < h; i++)
	{
		cout << endl;
		for (int j = 0; j < w; j++)
			cout << " " << Field[i][j];
	}
}
//движение
void shake::Moving()
{
	int left = 75, right = 77, up = 72, down = 80;
	char Key = ' ';
	char lastKey = left;//начадбное направление движения (влево)
	bool game = false;

	while (!game)
	{
		Sleep(speed);
		Eat();
		Field[Snake[sizeShake - 1].y][Snake[sizeShake - 1].x] = ' ';
		for (int i = sizeShake - 1; i > 0; --i)
		{
			Snake[i] = Snake[i - 1];
		}
		//определение нажатой клавиши
		if (_kbhit())
		{
			Key = _getch();
		}
		//движение змейки
		switch (lastKey)
		{
		case 72:
			if ((lastKey != 80) || (lastKey != 72))
			{
				Snake[0].y -= 1;
				if ((Key == left) || (Key == right))
				{
					lastKey = Key;
				}
			}
			break;
		case 75:
			if ((lastKey != 75) || (lastKey != 77))
			{
				Snake[0].x -= 1;
				if ((Key == up) || (Key == down))
				{
					lastKey = Key;
				}
			}
			break;
		case 77:
			if ((lastKey != 75) || (lastKey != 77))
			{
				Snake[0].x += 1;
				if ((Key == up) || (Key == down))
				{
					lastKey = Key;
				}
			}
			break;
		case 80:
			if ((lastKey != 80) || (lastKey != 72))
			{
				Snake[0].y += 1;
				if ((Key == left) || (Key == right))
				{
					lastKey = Key;
				}
			}
			break;
		default:
			break;
		}

		//изменение позиции змеи
		Field[Snake[0].y][Snake[0].x] = '+';
		for (int i = 1; i < sizeShake; i++)
			Field[Snake[i].y][Snake[i].x] = '@';
		game = CheckGameOver();	
		//перерисовка игрового поля
		RedrawFieldAndShake();
	}

}
//содание еды на поле
void shake::CreateFood()
{
	Food = { 1 + rand() % (w - 2) , 1 + rand() % (h - 2) };
	int i = 0;
	bool F = true;
	while ((i < sizeShake) && (F))
	{
		if (Food == Snake[i])
		{
			F = false;
		}
		i++;
	}
	if (F)
	{
		Field[Food.y][Food.x] = 'X';
		food = true;
	}
}
//работа с едой
void shake::Eat()
{
	//запоминаем положение конца змеи на случай, если змея поймала еду
	pos _EndSnake = Snake[sizeShake - 1];//положение конца змеи
	//проверка на пересечение головы змеи с едой
	if (Snake[0] == Food)
	{
		food = false;
		score += 1;
		if (speed > 30)
		{
			speed -= 2;
		}
		while (!food)
		{
			CreateFood();
		}			
		sizeShake++;
		Snake[sizeShake - 1] = _EndSnake;
	}
}
//проверка конца игры
bool shake::CheckGameOver()
{
	//столкновение с собой
	for (int i = 2; i < sizeShake; i++)
	{
		if (Snake[0] == Snake[i])
		{
			cout << endl << "       Вы проиграли!";
			return true;
		}
	}
	//столкновение с границей
	if ((Snake[0].x == w - 1) || (Snake[0].y == h - 1) || (Snake[0].x == 0) || (Snake[0].y == 0))	
	{
		cout << endl << "         Вы проиграли!";
		return true;
	}
	//победа
	if (sizeShake == 45)
	{
		cout << endl << "         Вы победили!";
		return true;
	}
	else
		return false;
}
shake::~shake()
{
	for (int i = 0; i < h; i++)
	{
		delete[] Field[i];
	}
	delete[] Field;
	sizeShake = 0;
	food = false;
	score = 0;
}
//перегрузка сравнения струкутры
bool pos::operator==(const pos & _O) const
{
	if ((_O.x == x) && (_O.y == y))
	{
		return true;
	}
	return false;
}
