#include <iostream>
#include "Vector3D.h"

using namespace std;
int main()
{
	Vector3D vec1, vec2, vec3;
	cout << "Vvedite koordinati 1 vectora: ";
	cin >> vec1;
	cout << "Vvedite koordinati 2 vectora: ";
	cin >> vec2;
	cout << endl << "vector 3: " << vec3 << endl;
	vec3 = vec2;
    cout << "vector3 posle prisvoenya vectora 2: " << vec3 << endl;
	cout << "raznitsa vectora2 i vectora1: " << vec2 - vec1 << endl;
	cout << "summa vectora2 i vectora1: " << vec2 + vec1 << endl;
	cout << "proizvedenye vectora2 i vectora1: " << vec2 * vec1 << endl;
	cout << "ymnozhenye vectora2 na scalyar = 2: " << vec2 * 2 << endl;
	cout << "vector1 "<< vec1 << endl << "vector2" << vec2 << endl;
	if (vec1 == vec2)
	{
		cout << "vector1 i vector2 ravny";
	}
	else
	{
		if (vec1 > vec2)
		{
			cout << "vector1 bolshe vectora2";
		}
		else
		{
			cout << "vector2 bolshe vectora1";
		}
	}
}
