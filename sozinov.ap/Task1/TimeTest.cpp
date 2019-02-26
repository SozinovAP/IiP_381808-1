#include <iostream>
#include "Time.h"
using namespace std;
void main()
{
	Time el1, el2, tmp;
	cout << "Vvedite pervii element (hh.mm.ss): ";
	cin >> el1; //Vvod elementov
	cout << "Vvedite vtoroi element (hh.mm.ss): ";
	cin >> el2;
	cout << "Pervii: " << el1 << endl; //Vyvod elementov
	cout << "Vtoroi: " << el2 << endl;
	cout << ((el1 > el2) ? "Pervii bol`she" : "Vtoroi bol`she") << endl; //sravnenie
	cout << "Sum " << el1 + el2 << " Raz: (Pervii - Vtoroi) " << el1 - el2 << " (Vtoroi - Pervii) " << el2 - el1 << endl; //summa i raznost`
	tmp = el1; el1 = el2; el2 = tmp; //Proverka prisvaivaniya togo zhe tipa
	cout << "Elementy posle obmena" << endl;
	cout << "Pervy: " << el1 << endl;
	cout << "Vtoroy: " << el2 << endl;
	el1 = "10.20.21"; //Proverka prisvaivaniya cheres stroky
	cout << "Element posle prisvoeniya stroki 10.20.21" << endl;
	cout << el1 << endl;
	return;
}