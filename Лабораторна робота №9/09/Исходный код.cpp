#include <iostream>
using namespace std;

class cat

{
public:
	int age;

	cat()
	{
		age = 10;
	}
};

cat* f();

void main()
{
	cat *pCat = f();
	
	// Проверка.....  
	pCat->age = 20;
	cout << pCat->age << endl;

	system("pause");
}

cat* f()
{
	return new cat;
}