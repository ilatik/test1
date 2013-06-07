#include "matrix.h"
 
#include "array"
 
#include <iostream>
using std::cout; // ������������ ���� std ��� cout
using std::cin; // ������������ ���� std ��� cin
 
#include <iomanip> // ��� ������������ setw
using std::setw;   // ������������ ���� std ��� setw
 
#include <cstdlib>
 
Matrix::Matrix() // ����������� �� ���������
{
    size = 10; // �� ��������� ������ ������� = 10 �������� ���� Array
    ptr = new Array [size]; // �������� ����� � ������ ��� �������
    for (int ix = 0; ix < size; ix++) // �������� �������
        for (int jx = 0; jx < 10; jx++)
            ptr[ix][jx] = 0;
}
 
Matrix::Matrix(int matrixSize, int arraySize) // ����������� � �����������
{
    size = (matrixSize > 0 ? matrixSize : 10); // ���������� �����
 
    ptr = new Array [size]; // �������� ����� � ������ ��� �������
 
    for (int ix = 0; ix < size; ix++) // ���������������� ���������� ������
        ptr[ix].setSize(arraySize > 0 ? arraySize : 10); // ���������� ��������
 
    for (int ix = 0; ix < size; ix++) // �������� �������
        for (int jx = 0; jx < ptr->getSize(); jx++)
            ptr[ix][jx] = 0;
}
 
Matrix::Matrix(  Matrix &matrixToCopy ) // ����������� �����
    :size(matrixToCopy.size)              // ������������� ������� �������
{
    ptr = new Array [size]; // �������� ����� � ������ ��� �������
 
    for (int ix = 0; ix < size; ix++) // ���������������� ���������� ������
        ptr[ix].setSize(size); // ���������� ��������
 
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            ptr[ix][jx] = matrixToCopy[ix][jx];// ��������� ������� ���������� ������� matrixToCopy
}
 
Matrix::~Matrix() // ����������� ������ Matrix
{
   delete  [] ptr; // ���������� ������, ������ �������
}
 
int Matrix::getSize() const // ���������� ���������� ��������� �������
{
    return size;
}
 
Array *Matrix::getPtr() const
{
    return ptr;
}
 
// ������������� �������� ������ ��� ������ Array (����� ��������� ������� �� �����)
ostream &operator<< (ostream &output, const Matrix &obj)
{
    for (int ix = 0; ix < obj.size; ix++)
    {
        for (int jx = 0; jx < obj.ptr->getSize(); jx++)
        {
            output << setw(5) // ��� ������ ����� ���������� 5 �������
                   << obj.ptr[ix][jx];
        }
        cout << std::endl;
    }
 
    output << std::endl; // ������� ������� �� ����� ������
 
    return output; // ��������� ������������� �����, ���� cout << x << y << z << ...
}
 
// ������������� �������� �����, ��� ���������� ������� � ����������
istream &operator>> (istream & input, Matrix &obj)
{
    for (int ix = 0; ix < obj.size; ix++)
        for (int jx = 0; jx < obj.ptr->getSize(); jx++)
            input >> obj.ptr[ix][jx]; // ��������� �������
 
    return input; // ��������� ������������� ����, ���� cin >> x >> y >> z >> ...
}
 
// ������������� �������� ������ �������
Array &Matrix::operator[] (int subscript)
{
    if(subscript < 0 || subscript >= size)
    {
        std::cerr << "\n ������ �������: " << subscript << std::endl;
        exit(1); // ��������� ������ ���������, ������������ ������
    }
    return ptr[subscript]; // ������� ������ �� ������� �������
}
 
void Matrix::setMatrix() // ���������� �������
{
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            cin >> ptr[ix][jx]; // ���� ��������� ������� � ����������
}
 
void Matrix::getMatrix() // ����� �������
{
    for (int ix = 0; ix < size; ix++)
    {
        for (int jx = 0; jx < ptr->getSize(); jx++)
            cout << setw(5) << ptr[ix][jx]; // ����� ��������� ������� �� �����
        cout << std::endl;
    }
 
    cout << std::endl; // ����� ������
}
 
int *Matrix::search(const int key) const // ����� �� �����
{
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            if ( key == ptr[ix][jx] ) // ����� �� �����
                return (&ptr[ix][jx]);             // ������� �������� ��������
 
    return NULL;
}
 
Matrix Matrix::operator+ (const Matrix &right)
{
    if (size != right.size || ptr->getSize() != right.getPtr()->getSize())
    {
        cout << "������� ������� �������!\n";
        exit(1); // ��������� ������ ���������
    }
 
    Matrix result(size, ptr->getSize());
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            result.ptr[ix][jx] = ptr[ix][jx] + right.ptr[ix][jx];
 
    return result; // ������� �����
}
 
Matrix Matrix::operator+= (const Matrix &right)
{
    if (size != right.size || ptr->getSize() != right.getPtr()->getSize())
    {
        cout << "������� ������� �������!\n";
        exit(1); // ��������� ������ ���������
    }
 
//    Matrix result(size, ptr->getSize());
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            ptr[ix][jx] = ptr[ix][jx] + right.ptr[ix][jx];
 
    return *this; // ������� �����
}
 
Matrix Matrix::operator- (const Matrix &right)
{
    if (size != right.size || ptr->getSize() != right.getPtr()->getSize())
    {
        cout << "������� ������� �������!\n";
        exit(1); // ��������� ������ ���������
    }
 
    Matrix result(size, ptr->getSize());
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            result.ptr[ix][jx] = ptr[ix][jx] - right.ptr[ix][jx];
 
    return result; // ������� �����
}
 
const Matrix &Matrix::operator= (const Matrix &right) // �������� ������������
{
    if (&right != this) // ����� �� ����������� ����������������
    {
        if (size != right.size || ptr->getSize() != right.getPtr()->getSize())
        {
            delete [] ptr; // ���������� ������������
            size = right.size; // ���������� ������ ������ �������
            ptr = new Array [size]; // �������� ������ ��� ���������� ������
 
            for (int ix = 0; ix < size; ix++) // ���������������� ���������� ������
                ptr[ix].setSize(right.getPtr()->getSize()); // ���������� ��������
        }
 
        for (int ix = 0; ix < size; ix++)
            for (int jx = 0; jx < ptr->getSize(); jx++)
                ptr[ix][jx] = right.ptr[ix][jx]; // ����������� ������
    }
 
    return *this; // ��������� ������������� ������������, �������� x = t = e
}
 
bool Matrix::operator== (const Matrix &right) const// �������� ���������
{
    if (size != right.size || ptr->getSize() != right.getPtr()->getSize())
        return false; // ������� � ������ ����������� ���������
 
    for (int ix = 0; ix < size; ix++)
        for (int jx = 0; jx < ptr->getSize(); jx++)
            if (ptr[ix][jx] != right.ptr[ix][jx])
                return false; // ������� �� �����
 
    return true; // ������� �����
}



#include <iostream>
using namespace std;
 
#include "matrix.h"
 
#include <cstdlib>
 
int main()
{
    srand(time(NULL));
    Matrix myMatrix1(5,5); // ����������� � �����������
 
    // ���������� �������
    for (int ix = 0; ix < myMatrix1.getSize(); ix++)
        for (int jx = 0; jx < myMatrix1.getPtr()->getSize(); jx++)
            myMatrix1[ix][jx] = rand() % 100;
 
    cout << myMatrix1;  // ������������� �������� ������
 
    Matrix myMatrix2(myMatrix1); // ����������� �����
 
    myMatrix2.getMatrix(); // ����� ������� � ������� ������ ������ Matrix
 
    //myMatrix2.setMatrix(); // ���������� ������� � ������� ������ ������ Matrix
 
    int * adr = myMatrix2.search(99);
 
    if (adr == NULL)
        cout << "�������� " << 99 << " � ������� ���!\n";
    else
        cout << "�������� " << 99 << " ��������� � ������ �� ������: " << adr << endl;
 
    cout << (myMatrix1 + myMatrix2); // ������������� �������� ��������
 
    cout << "��� ������, myMatrix1 �������� ��� ���������!\n";
    cout << myMatrix1;
 
    myMatrix1 += myMatrix2; // ������������� �������� ��������-����������
 
    cout << "myMatrix1 �������� �������� ,���������� ���: myMatrix1 += myMatrix2; !\n";
    cout << myMatrix1;
 
    cout << (myMatrix1 - myMatrix1); // ������������� �������� ���������
 
    Matrix myMatrix3 = myMatrix2; // ������������� �������� ������������
 
    cout << myMatrix3;
 
    if (myMatrix3 == myMatrix2)
        cout << "������� myMatrix3 � myMatrix2 �����!\n";
 
    return 0;
}