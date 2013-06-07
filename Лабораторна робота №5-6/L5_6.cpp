/*
Общие данные:    
	Порядковый номер[1-1000]
	состояние [хорошее, удовлетворительное, плохое, неопределенное] 
	есть ли в продаже[да/нет]
Объект:
	Объект (название, цена, категория[А-F])
*/

#include <iostream>
using namespace std;

enum state {good, udovl, bad, unknown};

// класс для хранения денежных величин
class Amount
{
 private:
 	    long _dollars;
		int _cents;
  public:   		
		Amount(); 
		Amount(long d,int c);
		Amount(const Amount &original);
		~Amount();
		Amount operator++();
        bool operator >(const Amount&)const;
	void Show() const;
};

Amount::Amount() {
		cout << "Amount Constructor #1" << endl;
		_dollars=0;
		_cents=0;
}
Amount::Amount(long _dollars,int _cents) {
		cout << "Amount Constructor #2" << endl;			
		this->_dollars=_dollars;
		this->_cents=_cents;
}
Amount::Amount(const Amount &original) {
		cout << "Amount Copy Constructor" << endl;			
		this->_dollars=original._dollars;
		this->_cents=original._cents;
}
Amount::~Amount()
{
	cout << "Amount Destructor" << endl;
	cin.get();
}
Amount Amount::operator++()
{
	if (this->_cents==99) {
		this->_dollars++;
		this->_cents=0;
	}
	else 
		this->_cents++;
	return *this;
}
bool Amount::operator > (const Amount & amt) const
{
  return (_dollars > amt._dollars) ||
  	      (_dollars == amt._dollars && _cents  > amt._cents);
}

void Amount::Show() const
{
		cout << _dollars << "\t" << _cents << endl;
}


// Объявление класса
class CommonData
{
private:
	// данные класса	
	Amount _price;
	short _id;	// номер
	state _sost;
	bool _prodaga;
public:
	// методы доступа
	short getId() const {return _id;}
	void  setId(short id) {_id=id;}
	//...
	// Конструкторы
	CommonData();
	CommonData(short id, state sost, bool prodaga, Amount p);
	CommonData(short);
	~CommonData();
	// методы для консоли
	void Show() const;
	void Show(short) const;
};

// Реализация класса
// конструкторы
CommonData::CommonData()
{
	cout << "CommonData Constructor #1" << endl;
	_id=100;
	_sost=state::bad;
	_prodaga=true;
}

CommonData::CommonData(short id, state sost, bool prodaga, Amount p)
{
	 cout << "CommonData Constructor #2" << endl;
	_id=id;
	_sost=sost;
	_prodaga=prodaga;
	_price=p;
}
CommonData::CommonData(short)
{
	cout << "CommonData Constructor #3" << endl;
	//...
}

CommonData::~CommonData() 
{	
	cout << "Common DataDestructor" << endl; 
	cin.get();
}
// методы для консоли
void CommonData::Show() const
{
	cout << _id << endl << _sost << endl << _prodaga << endl;
	_price.Show();

}

void CommonData::Show(short) const
{
}

class MyObject
{
private:
	CommonData *pdata;
	char *pname;
	char _mark;	
public:
	
	MyObject();
	MyObject(char *, char, CommonData *);
	~MyObject();
	void Show() const;
};

MyObject::MyObject()
{
	cout << "MyObject Constructor #1" << endl;
	pname=new char[20];
	strcpy(pname,"abcdef");
	_mark='A';
	pdata=new CommonData();
}

MyObject::MyObject(char *pn, char m, CommonData *cd)
{
	cout << "MyObject Constructor #2" << endl;
	pname=new char[20];
	strcpy(pname,pn);
	_mark=m;
	pdata=new CommonData();
	pdata=cd;
}

MyObject::~MyObject()
{
	cout << "MyObject Destructor" << endl;
	delete pname;
	delete pdata;
	cin.get();
}
void MyObject::Show() const
{
	cout << pname << endl << _mark << endl;
	pdata->Show();
}
	

int main()
{
	
	MyObject obj1;
	obj1.Show();
	cin.get();
	Amount am(100, 98);

	MyObject obj2("ABCDEF",'B', new CommonData(100, unknown, true,am));
	obj2.Show();
/*
	Amount am1, am2(100, 98), am3(am2);
	CommonData cd1, cd2(1000, good, true, am2), cd3(2000,bad,true,Amount(1000,59));
	cd1.Show();cd2.Show();cd3.Show();

	Amount *p1=new Amount(1,99);
	//if()...
	p1->operator++();


	delete p1;
	p1=0;

	cout << am1._dollars << "gr." << am1._cents << "kop." << endl;
	cout << am2._dollars << "gr." << am2._cents << "kop." << endl;
	cout << am3._dollars << "gr." << am3._cents << "kop." << endl;
	am2++;
	cout << am2._dollars << "gr." << am2._cents << "kop." << endl;	
	am2++;
	cout << am2._dollars << "gr." << am2._cents << "kop." << endl;	
	am2++;
	cout << am2._dollars << "gr." << am2._cents << "kop." << endl;	
	if (am2 > am3)
		cout << "am2>am3" << endl;
	else
		cout << "am2<=am3" << endl;
	cin.get();
*/
	/*
	MyObject obj1;
	obj1._data.Show();
	cout << obj1._name << endl << obj1._mark << endl 
		 << obj1._price._dollars << endl << obj1._price._cents << endl;
		 */

	cin.get();cin.get();
	return 0;
}
