#include <iostream>
using namespace std;

void main()
{
	int obj = 5;
	int &lObj = obj;
	int *pObj = &obj;

	lObj  = 6;
	*pObj = 7;

	cout << obj;

	system("pause");
}