#include <iostream>
using namespace std;

class student
{
public:
	int age;
	int stupendia;
	char *lastName;
	
	student();
	~student();
};
student::student()
{
	age       = 18;
	stupendia = 722;
	lastName  = "Vadym";
};
student::~student()
{};

void main()
{
	setlocale(LC_ALL,"");

	student Vadym;
	student* p = &Vadym;

	p->age       = 20;
	p->lastName  = "Vasya";
	p->stupendia = 1400;

	
	cout << "Student: " << p->lastName  << endl
		 << "Age:     " << p->age       << endl
		 << "Stupend: " << p->stupendia << endl;
	
	Vadym.~student();
	p = nullptr;

	system("pause");
}