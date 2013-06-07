#include <iostream>
#include <windows.h>
using namespace std;

class cat
{
private:
	int*  age;
	int*  weigth;
public:
	int getAge()    const { return *age; }
	int getWeigth() const { return *weigth; }
	cat();
   ~cat();
};
cat::cat()
{
	age    = new int(5);
	weigth = new int(3);
}
cat::~cat()
{
	delete age;
	delete weigth;
}
void main()
{
	cat* pCat = new cat;
	cout << pCat->getAge() << endl;	
		
	delete pCat;
	system("pause");
}
