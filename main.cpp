#include <iostream>

using namespace std;

class String
{
private:
	int year, month, day;
	const char * value;
public:
	String (int date_year, int date_month, int date_day) {
		year = date_year;
		month = date_month;
		day = date_day;
	}
	~String () {
		cout<< "Деструктор"<<endl;
	}
	String(const String& s) {
		cout << "Конструктор копирования сработал" << endl;
	}
	void get () {
		cout<< "Год "<< year <<" Месяц "<< month << " День "<< day <<endl;
	}
	  String(const char * x): value(x){
		 cout <<"Конструктор инициализации " <<endl;
    }
     friend ostream& operator<< (ostream &out, const String &string);
	
};
ostream& operator<< (ostream &out, const String &string){
	 out << string.value;
	 return out;
}
int main()
{
	String My_Birthday(2000,9,9); // работа конструктора по умолчанию
	My_Birthday.get();
	
	String SixSevenNine (2006, 7, 9); // работа конструктора копирования
	String Copy(SixSevenNine);
	SixSevenNine.get();
	
	String  string1("Hello"); // работа конструктора инициализации 
	cout << string1 <<endl;   // с перегруженным оператором
	
	
}
