#pragma once
#include <iostream>


using namespace std;
class Vector3D
{
private:
	double x, y, z;
public:
	Vector3D();//konstructor po ymolchaniy
	Vector3D(double X, double Y, double Z);//initilizations
	Vector3D(const Vector3D& V);//copirovanie
	~Vector3D();//destructor	
	double get_X();//metod polucheniya koordinaty x
	double get_Y();//metod polucheniya koordinaty y
	double get_Z();//metod polucheniya koordinaty z
	//SET X, Y, Z
	void set_X(double X);
	void set_Y(double Y);
	void set_Z(double Z);
	//vichislenie dlini vectora;
	double LenVec()
		const
	{ 
		return sqrt(x*x + y*y + z*z); 
	} 

	
	//Peregryzki 

	//peregryzka "="
	Vector3D& operator=(const Vector3D& V);
	//peregryzka "+"
	Vector3D operator+(const Vector3D& V);
	//peregryzka "-"
	Vector3D operator-(const Vector3D& V);
	//peregryzka "*" 2 vectorov
	double operator*(const Vector3D& V);
	//peregryzka "*" na skalyar
	Vector3D operator*(const double& scalyar);
	//peregryzka sravnenii
	bool operator==(const Vector3D& V);
	bool operator!=(const Vector3D& V);
	bool operator>(const Vector3D& V);
	bool operator>=(const Vector3D& V);
	bool operator<(const Vector3D& V);
	bool operator<=(const Vector3D& V);

	//peregryzka COUT u CIN
	friend ostream& operator<<(ostream& stream, const Vector3D& V);
	friend istream& operator>>(istream& stream, Vector3D& V);

};

