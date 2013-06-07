/*Задание  №6 */
#include <iostream>
using namespace std;
#include <conio.h>
void main()
{
int SomeVariable =5;
int *pVar=&SomeVariable;
pVar=9;
cout << "SomeVariable: " << *pVar;//Предупреждение	1	warning C4700: использована неинициализированная локальная переменная "pInt"

cin.get();cin.get();
return;
}