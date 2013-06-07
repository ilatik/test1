#include <iostream>
using namespace std;

class student
{
public:
	int age;
	int stupendia;
	string lastName;
	
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

	student * p = new student[100]; // Создается 100 обьектов типа "student", конструктором по умолчанию в ячейки записываются данные
	
	delete []p;  // Исправление ошибки
	//p = nullptr;

	p = new student; // Выделяется память для 1 обьекта типа "student", но на предвидущих 100 указатель теряется (утечка памяти)
	
	delete p;

	system("pause");
}
