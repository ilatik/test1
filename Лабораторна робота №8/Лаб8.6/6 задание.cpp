/*�������  �6 */
#include <iostream>
using namespace std;
#include <conio.h>
void main()
{
int SomeVariable =5;
int *pVar=&SomeVariable;
pVar=9;
cout << "SomeVariable: " << *pVar;//��������������	1	warning C4700: ������������ �������������������� ��������� ���������� "pInt"

cin.get();cin.get();
return;
}