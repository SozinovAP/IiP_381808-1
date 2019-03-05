#include <iostream>
#include "Vector3D.h"

using namespace std;
int main()
{
	Vector3D vec1, vec2, vec3, vec4 = Vector3D(4.2, 5.6, 1.3), vec5;
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
	cout << endl << endl;

	cout << "Proverka vyvoda" << endl;
	cout << "Ozhidaemyi rezyltat: X = 4.2, Y = 5.6, Z = 1.3" << endl;
	cout << "Itog: " << vec4 << endl << endl;
	
	cout << "Proverka vvoda" << endl;
	cout << "Ozhidaemyi rezyltat: " << "X = 1.2, Y = 3.4, Z = 5.6" << endl;
	cout << "Vvedyte koordinaty iz ozhidaemogo rezyltata" << endl;
	cin >> vec5;
	cout << "Itog: " << vec5;
}
