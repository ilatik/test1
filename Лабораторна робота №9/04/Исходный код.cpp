#include <iostream>
using namespace std;

// 1
double kvr(double);
double cub(double);
double obr(double);

// 2
void kvr2(double&);
void cub2(double&);
void obr2(double&);

void main()
{
	cout << kvr(10.0) << endl;
	cout << cub(10.0) << endl;
	cout << obr(10.0) << "\n\n";

	double numb = 2.0;

	kvr2(numb);
	cout << numb << endl;

	cub2(numb);
	cout << numb << endl;

	obr2(numb);
	cout << numb << endl;

	system("pause");
}

double kvr(double r)
{
	return r*r;
}
double cub(double r)
{
	return r*r*r;
}
double obr(double r)
{
	return -r;
}

void kvr2(double &r)
{
	r*=r;
}
void cub2(double &r)
{
	r*=(r*r);
}
void obr2(double &r)
{
	r=-r;
}