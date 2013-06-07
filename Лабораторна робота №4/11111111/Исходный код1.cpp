/*# include <iostream>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "rus");
    int array[100][100];
    int i, j, n, m;
    int sum = 0; 
	int raz = 0;
    cout<<"Введите размер массива: "<<endl;
    cin>>n;
    cin>>m;
    cout<<"Введите элементы масива: "<<endl;
    for (i=0; i<n; i++)
        for(j=0; j<m; j++)
    cin>>array[i][j];
for (i=0; i<n; i++)
        for(j=0; j<m; j++)
            sum += array[i][j];
    cout<<"Сума элементов массива: "<< sum <<endl;
   	 
/////////
	 for (i=0; i<n; i++)
        for(j=0; j<m; j++)
    cin>>array[i][j];
for (i=0; i<n; i++)
        for(j=0; j<m; j++)
            raz -= array[i][j];
    cout<<"Разность элементов массива: "<< raz <<endl;
//////////////

    return 0;
	cin.get(); cin.get(); 
}
*/