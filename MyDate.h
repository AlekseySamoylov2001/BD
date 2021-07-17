#include "MyString.h"

class MyDate : public InOut
{
	int day, month, year;

	static int daytab[2][13];

	static char* MonthName[13];
	static char* DayNames[7];

public:

	int get_day()const { return day; }
	int get_month()const { return month; }
	int get_year()const { return year; }
	int validate();

	int DayOfWeek()const;

	void set_day(int d)
	{
		int tmp = day;

		day = d;

		if (validate())
			day = tmp;
	}
	void set_month(int m) 
	{
		int tmp = month;

		month = m;

		if (validate())
			month = tmp;
	}
	void set_year(int y)
	{
		int tmp = year;

		year = y;

		if (validate())
			year = tmp;
	}

	bool vis()const
	{
		return (year % 4 == 0);
	}

	MyDate();
	MyDate(int d, int m, int y);
	MyDate(const MyDate&);
	~MyDate();

	void dispose();
	MyString* ToMyDate();
	MyString* ToMyString();

	void assign(const MyDate& t);
	Obj* copy();

	int equal(const MyDate& t)const;
	int cmp(const MyDate& t)const;

	int equal(const Obj& t)const;
	int cmp(const Obj& t)const;

	int input();
	int output();
	int input(FILE* f);
	int output(FILE* f);
	void in(int& temp, FILE* f);
	void out(int& temp, FILE* f);

	MyDate& operator=(const MyDate& t);
	MyDate& operator+=(int t);
	MyDate& operator-=(int t);

	friend std::istream& operator>>(std::istream& i, MyDate& d);
	friend std::ostream& operator<<(std::ostream& o, MyDate d);
	friend FILE* operator>>(FILE* f, MyDate& d);
	friend FILE* operator<<(FILE* f, const MyDate& d);
	friend MyDate operator+(const MyDate& left, const int right);
	friend MyDate operator-(const MyDate& left, const int right);
	friend int operator-(const MyDate& left, const MyDate& right);
	friend int operator==(const MyDate& left, const MyDate& right);

};
