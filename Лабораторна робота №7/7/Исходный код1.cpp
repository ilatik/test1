#include <iostream>
#include <conio.h>
using namespace std;

// ���������� ������� ������ ��� ������ � ��������� ��������
class String {
  public:
    // ������������
    String();
    String(const char * const);
    String(const String &);
    ~String();
    // ������������� ��������� ����������
    char & operator [] (int offset);
    char operator [] (int offset) const;

    String operator + (const String &);
    void operator += (const String &);
    String & operator = (const String &);
    int GetLen() const {return itsLen;}
    const char * GetString() const {return itsString;}
  private:
    String(int); //��������� �����������
    char * itsString;
    int itsLen;
};

// ����������� �� ���������
String::String()
{
   itsString=new char[1];
   itsString[0]='\0';
   itsLen=0;
   //cout << "\tDefault String constructor\n";
}

// ���������(���������������) �����������, ������������ ������ �������� ������
String::String(int len)
{
   itsString=new char[len+1];
   for (int i=0; i <= len; i++)
     itsString[i]='\0';
   itsLen=len;
   //cout << "\tPrivate String(int) constructor\n";
}

// �����������, ������������� ������ �������� � String
String::String(const char * const cString)
{
   itsLen=strlen(cString);
   itsString=new char[itsLen+1];
   for (int i=0; i < itsLen; i++)
     itsString[i]=cString[i];
   itsString[itsLen]='\0';
   //cout << "\tC-array String(char*) constructor\n";
}

// ����������� �����������
String::String(const String & rhs)
{
   itsLen=rhs.GetLen();
   itsString=new char[itsLen+1];
   for (int i=0; i < itsLen; i++)
     itsString[i]=rhs[i];
   itsString[itsLen]='\0';
   //cout << "\tCopy String(String&) constructor\n";
}

// ����������, ����������� ���������� ������
String::~String()
{
   delete [] itsString;
   itsLen=0;
   //cout << "\tString destructor\n";
}

// �������� = , ����������� ������ ������������ ������, ������� ����� �������
// ������� � �������� � ��� ������ ������
String & String::operator = (const String & rhs)
{
   if (this==&rhs)
     return *this;
   delete [] itsString;
   itsLen=rhs.GetLen();
   itsString=new char[itsLen+1];
   for (int i=0; i < itsLen; i++)
     itsString[i]=rhs[i];
   itsString[itsLen]='\0';
   //cout << "\tString operator = \n";
   return *this;
}

// ������������� �������� �������� - �������� �������� ������� � ������
char & String::operator [] (int offset)
{
   if (offset > itsLen)
     return itsString[itsLen-1];
   else
     return itsString[offset];
}

// ����������� �������� �������� - ������� �������� ������� � ������
char String::operator [] (int offset) const
{
   if (offset > itsLen)
     return itsString[itsLen-1];
   else
     return itsString[offset];
}

// �������� + , ������� ����� ������ ����� ������������ ���� �����
String  String::operator + (const String & rhs)
{
   int i,j;
   int totalLen=itsLen+rhs.GetLen();
   String temp(totalLen+1);
   for (i=0; i < itsLen; i++)
     temp[i]=itsString[i];
   for (j=0; j < rhs.GetLen(); j++,i++)
     temp[i]=rhs[j];
   temp[totalLen]='\0';
   //cout << "\tString operator + \n";
   return temp;
}

// �������� += , �������� ������� ������ ����� �� ������������ � ������
void String::operator += (const String & rhs)
{
   int i,j;
   int rhsLen=rhs.GetLen();
   int totalLen=itsLen+rhsLen;
   String temp(totalLen);
   for (i=0; i < itsLen; i++)
     temp[i]=itsString[i];
   for (j=0; j < rhs.GetLen(); j++,i++)
     temp[i]=rhs[j];
   temp[totalLen]='\0';
   //cout << "\tString operator += \n";
   *this=temp;
}

void main()
{
   // ������ ������� ������
	String s1("Banana");  // �������� ������ ��� ������� ���� String

   //cout << "s1\t" << s1 << endl;
   cout << "s1\t" << s1.GetString() << endl;
   cout << "Razmer masiva\t"  << endl;
 
   char s2[6];      //  �������������������� ������ � �������
	s2[0]='\0';       //  ������ ��� ��� ������ ������
   for (int n=0; n<20; n++)   //���� ��������� ��������
	cout << "Here's the s2: " << s2 << sizeof(s2) << endl;
 /*  char temp[]="Hello world"; // �������� ������ �-�����
   s1=temp; // ���������, �.�. �������� = � ������ String ����������
   cout << "s1\t" << s1.GetString() << endl;

   char tempTwo[20]; // �-�����
   strcpy(tempTwo,"; nice to be here!"); // ��������� �����. ��������� tepmTwo

   s1+=tempTwo; // ���������, �.�. �������� += ����������
   cout << "tempTwo\t" << tempTwo << endl;
   cout << "s1\t" << s1.GetString() << endl;

   cout << "s1[4]\t" << s1[4] << endl;  // ����� ������ �� ������
	s1[4]='x';  // ��������� ������ � ������
   cout << "s1\t" << s1.GetString() << endl;

   cout << "s1[999]\t" << s1[999] << endl;  // ����� ���� ���������
   getch();
   */

  /* String s2(" Another string");
   String s3;
   s3=s1+s2;// � ������ ���� �������� +
   cout << "s3\t" << s3.GetString() << endl;

   String s4;
   s4="Why does this work?";
   cout << "s4\t" << s4.GetString() << endl;

   String FIO,Fam("������"),Im("����"),Ot("��������");
   //cout << "������� Fam,Im,Ot ����� ������ :";
   //cin >> Fam >> Im >> Ot; // � ���� ������ ��������� >> � <<  �� �����������
   //cout << Fam << "\t" << Im << "\t" << Ot << endl;
   FIO=Fam+" "+Im+" "+Ot;
   cout << FIO.GetString() << endl;

   //FIO=Fam+" "+Im[0]+"."+Ot[0]+".";
   cout << FIO.GetString() << endl;
   */
  	getch();
}

