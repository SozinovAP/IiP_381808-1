#include <iostream>
#include "Vector3D.h"
using namespace std;



Vector3D::Vector3D()
{
	x = y = z = 0.0;
}


Vector3D::Vector3D(double X, double Y, double Z)//initialization
{
	x = X;
	y = Y;
	z = Z;
}

Vector3D::Vector3D(const Vector3D& V)//copirovanie
{
	x = V.x;
	y = V.y;
	z = V.z;
}
Vector3D::~Vector3D()//destructor
{
	x = y = z = 0;
}
//poluchenie x, y, z
double Vector3D::get_X()
{ 
	return x; 
}
double Vector3D::get_Y() 
{ 
	return y;
}
double Vector3D::get_Z() 
{ 
	return z;
}

void Vector3D::set_X(double X) 
{
	x = X;
}
void Vector3D::set_Y(double Y)
{
	y = Y;
}
void Vector3D::set_Z(double Z)
{
	z = Z;
}

//Peregryzki


//peregryzka "="
Vector3D& Vector3D::operator=(const Vector3D& V)
{
	if (this != &V)
	{
		x = V.x;
		y = V.y;
		z = V.z;
	}
	return *this;
}
//peregryzka "+"
Vector3D Vector3D::operator+(const Vector3D& V)
{
	Vector3D tmp;
	tmp.x = x + V.x;
	tmp.y = y + V.y;
	tmp.z = z + V.z;
	return tmp;
}
//peregryzka "-"
Vector3D Vector3D::operator-(const Vector3D& V)
{
	Vector3D tmp;
	tmp.x = x - V.x;
	tmp.y = y - V.y;
	tmp.z = z - V.z;
	return tmp;
}
//peregryzka "*" 2 vectorov
double Vector3D::operator*(const Vector3D& V)
{
	return x * V.x + y * V.y + z*V.z;
}
//peregryzka "*" na scalyar
Vector3D Vector3D::operator*(const double& scalyar)
{
	Vector3D tmp;
	tmp.x = x * scalyar;
	tmp.y = y * scalyar;
	tmp.z = z * scalyar;
	return tmp;
}
//peregryzka sravnenii
bool Vector3D::operator==(const Vector3D& V)
{
	return (LenVec() == V.LenVec());
}
bool Vector3D::operator!=(const Vector3D& V)
{
	return (LenVec() != V.LenVec());
}
bool Vector3D::operator>(const Vector3D& V)
{
	return (LenVec() > V.LenVec());
}
bool Vector3D::operator>=(const Vector3D& V)
{
	return !(LenVec() < V.LenVec());
}
bool Vector3D::operator<(const Vector3D& V)
{
	return (LenVec() < V.LenVec());
}
bool Vector3D::operator<=(const Vector3D& V)
{
	return !(LenVec() > V.LenVec());
}

//peregryzka COUT u CIN
ostream& operator<< (ostream& stream, const Vector3D& V)
{
	stream << "X = " << V.x << ", Y = " << V.y << ", Z = " << V.z;
	return stream;
}
istream& operator>> (istream& stream, Vector3D& V)
{
	stream  >> V.x >> V.y >> V.z;
	return stream;
}



