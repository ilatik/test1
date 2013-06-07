#ifndef MATRIX_H
#define MATRIX_H
 
#include "array"
 
class Matrix
{
    friend ostream &operator<< (ostream &, const Matrix &); // ������������� �������� ������
    friend istream &operator>> (istream &, Matrix &); // ������������� �������� �����
private:
    Array *ptr; // ��������� �� ������� ���� Array
    int size; // ������ �������
 
public:
    Matrix();// ����������� �� ���������
    Matrix(int, int ); // ����������� � �����������
    Matrix( Matrix &matrixToCopy ); // ����������� �����
    ~Matrix(); // ����������� ������ Matrix
 
    int getSize() const; // ���������� ���������� �������� ���� Array
    Array *getPtr() const; // ������� ��������� �� ������ ���� Array
    Array &operator[] (int ); // ������������� �������� ������ �������
    void setMatrix(); // ���������� �������
    void getMatrix(); // ����� �������
    int *search(const int key) const; // ����� �� �����
    Matrix operator+ (const Matrix &right);
    Matrix operator+= (const Matrix &right);
    Matrix operator- (const Matrix &right);
    const Matrix &operator= (const Matrix &right); // �������� ������������
    bool operator== (const Matrix &right) const;// �������� ���������
};
 
#endif // MATRIX_H