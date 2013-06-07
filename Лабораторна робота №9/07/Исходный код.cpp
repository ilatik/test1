#include <iostream>
using namespace std;

class cat
{
public:
	int age;
	cat()
	{
		age = 5;
	}
};

// 1
cat f1(cat);

// 2
void f2(cat&);

// 3
void f3(cat*);

void main()
{
	cat murka;                 // age = 5

	// 1
	cat vaska = f1(murka);
	cout << vaska.age << endl; // age = 10

	// 2
	f2(murka);
	cout << murka.age << endl; // age = 20

	// 3
	f3(&murka);
	cout << murka.age << endl; // age = 30


	

	system("pause");
}
cat  f1(cat obj)
{
	cat temp;
	temp.age = 10;
	return temp;
}
void f2(cat &obj)
{
	obj.age = 20;
}
void f3(cat *obj)
{
	obj->age = 30;
}