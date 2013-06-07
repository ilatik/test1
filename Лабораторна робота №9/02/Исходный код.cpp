#include <iostream>
using namespace std;

class cat
{
public:
	int age;
	int id;
};


void main()
{
	cat murka;
	cat &murochka = murka;
	cat *pMurka  = &murka;

	murochka.age = 10;
	pMurka->age  = 20;

	cout << murka.age;
	system("pause");
}