#include <iostream>
#include <conio.h>
using namespace std;

// ќбъ€вление личного класса дл€ работы с объектами строками
class String {
  public:
    // конструкторы
    String();
    String(const char * const);
    String(const String &);
    ~String();
    // перегруженные операторы индексации
    char & operator [] (int offset);
    char operator [] (int offset) const;

    String operator + (const String &);
    void operator += (const String &);
    String & operator = (const String &);
    int GetLen() const {return itsLen;}
    const char * GetString() const {return itsString;}
  private:
    String(int); //приватный конструктор
    char * itsString;
    int itsLen;
};

// конструктор по умолчанию
String::String()
{
   itsString=new char[1];
   itsString[0]='\0';
   itsLen=0;
   //cout << "\tDefault String constructor\n";
}

// приватный(вспомогательный) конструктор, используемый только методами класса
String::String(int len)
{
   itsString=new char[len+1];
   for (int i=0; i <= len; i++)
     itsString[i]='\0';
   itsLen=len;
   //cout << "\tPrivate String(int) constructor\n";
}

// конструктор, преобразующий строку символов в String
String::String(const char * const cString)
{
   itsLen=strlen(cString);
   itsString=new char[itsLen+1];
   for (int i=0; i < itsLen; i++)
     itsString[i]=cString[i];
   itsString[itsLen]='\0';
   //cout << "\tC-array String(char*) constructor\n";
}

// конструктор копировани€
String::String(const String & rhs)
{
   itsLen=rhs.GetLen();
   itsString=new char[itsLen+1];
   for (int i=0; i < itsLen; i++)
     itsString[i]=rhs[i];
   itsString[itsLen]='\0';
   //cout << "\tCopy String(String&) constructor\n";
}

// деструктор, освобождает выделенную пам€ть
String::~String()
{
   delete [] itsString;
   itsLen=0;
   //cout << "\tString destructor\n";
}

// оператор = , освобождает пам€ть существующей строки, создает новую нужного
// размера и копирует в нее другую строку
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

// неконстантный оператор смещени€ - измен€ет значение символа в строке
char & String::operator [] (int offset)
{
   if (offset > itsLen)
     return itsString[itsLen-1];
   else
     return itsString[offset];
}

// константный оператор смещени€ - достает значение символа в строке
char String::operator [] (int offset) const
{
   if (offset > itsLen)
     return itsString[itsLen-1];
   else
     return itsString[offset];
}

// оператор + , создает новую строку путем конкатенации двух строк
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

// оператор += , измен€ет текущую строку путем ее конкатенации с другой
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
   // —троки личного класса
	String s1("Banana");  // создание строки как объекта типа String

   //cout << "s1\t" << s1 << endl;
   cout << "s1\t" << s1.GetString() << endl;
   cout << "Razmer masiva\t"  << endl;
 
   char s2[6];      //  неинициализированна€ строка с мусором
	s2[0]='\0';       //  сейчас это уже пуста€ строка
   for (int n=0; n<20; n++)   //цикл пересылки символов
	cout << "Here's the s2: " << s2 << sizeof(s2) << endl;
 /*  char temp[]="Hello world"; // создание строки —-стил€
   s1=temp; // правильно, т.к. оператор = в классе String реализован
   cout << "s1\t" << s1.GetString() << endl;

   char tempTwo[20]; // —-стиль
   strcpy(tempTwo,"; nice to be here!"); // присвоить текст. константу tepmTwo

   s1+=tempTwo; // правильно, т.к. оператор += реализован
   cout << "tempTwo\t" << tempTwo << endl;
   cout << "s1\t" << s1.GetString() << endl;

   cout << "s1[4]\t" << s1[4] << endl;  // вз€ть символ из строки
	s1[4]='x';  // поместить символ в строку
   cout << "s1\t" << s1.GetString() << endl;

   cout << "s1[999]\t" << s1[999] << endl;  // будет вз€т последний
   getch();
   */

  /* String s2(" Another string");
   String s3;
   s3=s1+s2;// в классе есть оператор +
   cout << "s3\t" << s3.GetString() << endl;

   String s4;
   s4="Why does this work?";
   cout << "s4\t" << s4.GetString() << endl;

   String FIO,Fam("»ванов"),Im("»ван"),Ot("»ванович");
   //cout << "¬ведите Fam,Im,Ot через пробел :";
   //cin >> Fam >> Im >> Ot; // ¬ этом классе операторы >> и <<  не реализованы
   //cout << Fam << "\t" << Im << "\t" << Ot << endl;
   FIO=Fam+" "+Im+" "+Ot;
   cout << FIO.GetString() << endl;

   //FIO=Fam+" "+Im[0]+"."+Ot[0]+".";
   cout << FIO.GetString() << endl;
   */
  	getch();
}

