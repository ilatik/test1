/* Задание №2,№3,№4 */
#include <iostream>
using namespace std;
#include <conio.h>
typedef unsigned short int USHORT;
void main()
{
USHORT yourAge;
USHORT *pAge=0;
yourAge=50;
 cout << "\nyourAge: " << yourAge << "\n";
  pAge=&yourAge;    // занесение адреса переменной myAge в переменнную-указатель pAge

   cout << "*pAge: " << *pAge << "\n"; // разыменование указателя (взятие значения
   												// по адресу хранящемуся в указателе)
 getch();
 return ;

}
