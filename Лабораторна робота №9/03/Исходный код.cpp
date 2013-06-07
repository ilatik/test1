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
	cat *pCat = new cat;
	cat &murka = *pCat; 
	
	murka.age = 20;
	pCat->age = 30;

	cout << murka.age;
	system("pause");
}