/* ������� �2,�3,�4 */
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
  pAge=&yourAge;    // ��������� ������ ���������� myAge � �����������-��������� pAge

   cout << "*pAge: " << *pAge << "\n"; // ������������� ��������� (������ ��������
   												// �� ������ ����������� � ���������)
 getch();
 return ;

}
