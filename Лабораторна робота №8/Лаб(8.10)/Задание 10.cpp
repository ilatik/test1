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

	student * pStudent = new student;

	pStudent->age       = 20;
	pStudent->lastName  = "Vasya";
	pStudent->stupendia = 1400;

	cout << "Student: " << pStudent->lastName  << endl
		 << "Age:     " << pStudent->age       << endl
		 << "Stupend: " << pStudent->stupendia << endl;
	
	delete pStudent;    // јдрес указател€ остаетс€, но содержимое удал€етс€
	pStudent = nullptr; // ”дал€ем вис€чий указатель

	system("pause");
}