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
class worker
{
public:
	int age;
	worker()
	{
		age = 30;
	}
};
class pensil
{
public:
	int price;
	pensil()
	{
		price = 25;
	}
};

void main()
{
	cat    *pCat = new cat;
	worker *pWor = new worker;
	pensil *pPen = new pensil;

	cat    &CAT    = *pCat; 
	worker &WORKER = *pWor;
	pensil &PENSIL = *pPen;

	CAT.age      = 20;
	WORKER.age   = 40;
	PENSIL.price = 10;

	delete pCat, pWor, pPen;

	system("pause");
}
