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

cat& f();

void main()
{
	cat &l = f();

	// Проверка..........
	l.age = 10;             
	cout << l.age << endl;  

	system("pause");
}

cat& f()
{
	cat *pCat = new cat;
	return *pCat;
}