#include <iostream>
using namespace std;

#define PI 3.1415;

// 1
double dln(double);
double plo(double);
double obj(double);

// 2
void dln2(double&);
void plo2(double&);
void obj2(double&);

void main()
{
	double radius = 10;

	cout << dln(radius) << endl;
	cout << plo(radius) << endl;
	cout << obj(radius) << endl;

	dln2(radius);
	cout << radius << endl;

	plo2(radius);
	cout << radius << endl;

	obj2(radius);
	cout << radius << endl;

	system("pause");
}

double dln(double r)
{
	return r*2*PI;
}
double plo(double r)
{
	return (r*r)*PI;
}
double obj(double r)
{
	return (4./3.)*(r*r*r)*PI;
}

void dln2(double &r)
{
	r = r*2*PI;
}
void plo2(double &r)
{
	r = (r*r)*PI;
}
void obj2(double &r)
{
	r = (4./3.)*(r*r*r)*PI;
}