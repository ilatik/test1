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

	student * p = new student[100]; // ��������� 100 �������� ���� "student", ������������� �� ��������� � ������ ������������ ������
	
	delete []p;  // ����������� ������
	//p = nullptr;

	p = new student; // ���������� ������ ��� 1 ������� ���� "student", �� �� ����������� 100 ��������� �������� (������ ������)
	
	delete p;

	system("pause");
}
