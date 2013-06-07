//Задание №7
#include <iostream>
using namespace std; 
#include <conio.h>

class Employee
{
public:
	Employee() {itsAge=23;itsYears=4;itsZarplata=10000;}
	~Employee(){}
   int GetAge() const {return itsAge;}
   void SetAge(int age)  {itsAge=age;}
    int GetYears() const {return itsYears;}
   void SetYears( int years)  {itsYears=years;}
    int GetZarplata() const {return itsZarplata;}
   void SetZarplata(int zarplata)  {itsZarplata=zarplata;}
private:
	int itsAge;
	int itsYears;
	int itsZarplata;
   
};

void main()
{
   Employee *pVasya=new Employee ;  // создание объекта в свободной памяти
   if (pVasya==NULL)                //  проверка выделения памяти
   {
   	cout << "Error! No memory for Vasya!!!\n";
	Employee *pLoh=new Employee;
	 if (pLoh==NULL)                //  проверка выделения памяти
   {
   	cout << "Error! No memory for Loh!!!\n";
      return;
   }

// Обработка объекта
   //cout << "Frisky is " << pVasya.GetAge() << " years old\n";
   cout << "Vasya is " << (*pVasya).GetAge() << " years old\n";
   cout << "Vasya is " << pVasya->GetAge() << " years old\n";
	pVasya->SetAge(23);
   cout << "Vasya is " << pVasya->GetAge() << " years old\n";

   cout << "Vasya is " << (*pVasya).GetYears() << " years\n";
   cout << "Vasya is " << pVasya->GetYears() << " years\n";
	pVasya->SetYears(4);
   cout << "Vasya is " << pVasya->GetYears() << " years\n";

   cout << "Vasya is " << (*pVasya).GetZarplata() << " dollars\n";
   cout << "Vasya is " << pVasya->GetZarplata() << " dollars\n";
	pVasya->SetZarplata(10000);
   cout << "Vasya is " << pVasya->GetZarplata() << " dollars\n";
   

   cout << "Loh is " << (*pLoh).GetAge() << " years old\n";
   cout << "Loh is " << pLoh->GetAge() << " years old\n";
	pLoh->SetAge(23);
   cout << "Loh is " << pLoh->GetAge() << " years old\n";

   cout << "Loh is " << (*pLoh).GetYears() << " years\n";
   cout << "Loh is " << pLoh->GetYears() << " years\n";
	pLoh->SetYears(4);
   cout << "Loh is " << pLoh->GetYears() << " years\n";

   cout << "Vasya is " << (*pLoh).GetZarplata() << " dollars\n";
   cout << "Loh is " << pLoh->GetZarplata() << " dollars\n";
	pLoh->SetZarplata(10000);
   cout << "Loh is " << pLoh->GetZarplata() << " dollars\n";
   
// удаление объекта из свободной памяти
   
   delete pVasya; // свободная память больше не принадлежит программе!!!
   delete pLoh;
   
   system("pause");
  	
   }
}