#include <iostream>
using namespace std;

void main()
{
	int   INT   = 0;
	float FLOAT = 0.0; 

	int res = scanf("%i %e", &INT, &FLOAT); 

	if(res == 2)	
		printf("\nint   = %i;\nfloat = %.5f;\n", INT, FLOAT);


	system("pause");
}