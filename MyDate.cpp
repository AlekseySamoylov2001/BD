#define _CRT_SECURE_NO_WARNINGS
#include "MyDate.h" 

using namespace std;

MyDate::MyDate()
{
	day = 1;
	month = 1;
	year = 1;
}

MyDate::MyDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;

	if (!validate())
	{
		cout << "Error";
		day = month = year = 0;
	}
}

MyDate::MyDate(const MyDate& k)
{
	day = k.day;
	month = k.month;
	year = k.year;
}

MyDate::~MyDate()
{
}

void MyDate::dispose()
{
}

MyString* MyDate::ToMyDate()
{
	char str[10];

	sprintf(str, "%d.%d.%d", day, month, year);

	return new MyString(str);
}

MyString* MyDate::ToMyString()
{
	char s[7] = "MyDate";
	return new MyString(s);
}

int MyDate::daytab[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31} };

char f[13][10] = { "null","January","February","March","April","May","June","July","August","September","October","November","December" };
char g[7][10] = { "Saturday", "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };

char* MyDate::MonthName[13] = { f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11], f[12] };
char* MyDate::DayNames[7] = { g[0], g[1], g[2], g[3], g[4], g[5], g[6] };

int MyDate::validate() // проверка на правильность ввода
{
	return (year > 0 && month > 0 && month <= 12 && day > 0 && day <= daytab[vis()][month]);
}

int MyDate::DayOfWeek()const
{
	int month_code = 0;
	int year_code = (6 - year / 100 % 4 * 2 + year % 100 + year % 100 / 4) % 7; // формула кода года

	if (month == 1 || month == 10) // код дл€ мес€ца
		month_code = 1;
	else if (month == 5)
		month_code = 2;
	else if (month == 8)
		month_code = 3;
	else if (month == 2 || month == 3 || month == 11)
		month_code = 4;
	else if (month == 6)
		month_code = 5;
	else if (month == 9 || month == 12)
		month_code = 6;
	else if (month == 4 || month == 7)
		month_code = 0;

	int code = day + month_code + year_code; // общий код по которому вычисл€етс€ день недели

	if (vis() && (month == 1 || month == 2)) // если год високосный нужно сместить день на 1 дл€ €нвар€ и феврал€
		code -= 1;

	return code % 7; // код дн€ недели
}

void MyDate::assign(const MyDate& t)
{
	day = t.day;
	month = t.month;
	year = t.year;
}

Obj* MyDate::copy()
{
	return new MyDate(*this);
}

int MyDate::equal(const MyDate& t)const
{
	return day == t.day && month == t.month && year == t.year;
}

int MyDate::cmp(const MyDate& t)const
{
	if (year != t.year)
		return year - t.year;
	else  if (month != t.month)
		return month - t.month;
	else return day - t.day;
}

int MyDate::equal(const Obj& t)const
{
	return equal((const MyDate&)t);
}

int MyDate::cmp(const Obj& t)const
{
	return cmp((const MyDate&)t);
}

int MyDate::input()
{
	scanf("%d.%d.%d", &day, &month, &year);
	if (!validate())
	{
		cout << "Error Data" << endl;
		day = month = year = 0;
	}
	return 1;
}

int MyDate::output()
{
	char* s = MonthName[month], * ss = DayNames[DayOfWeek()], sss[200];

	sprintf(sss, "%d%s%s%s%s%s%d%s%d", day, " (", ss, ") ", s, " (", month, ") ", year);

	cout << sss;

	return 1;
}

int MyDate::input(FILE* f)
{
	in(year, f);
	in(month, f);
	in(day, f);

	return 0;
}

int MyDate::output(FILE* f)
{
	out(year, f);
	out(month, f);
	out(day, f);

	return 0;
}

void MyDate::in(int& temp, FILE* f)
{
	char* buf = new char[200];
	temp = std::stoi(fgets(buf, 12, f)); // берем строку из файла и конвертируем в целочисленный тип
	delete[] buf;
}

void MyDate::out(int& temp, FILE* f)
{
	char s[200];

	sprintf(s, "%d", temp); // конвертируем число в строку

	fputs(s, f); // заносим ее в файл
	fputc('\n', f); // переход на следующую строку в файле
}

MyDate& MyDate::operator=(const MyDate& t)
{
	if (this == &t)
		return *this;

	this->assign(t);

	return *this;
}

MyDate& MyDate::operator+=(int t)
{
	while (day + t > daytab[0][month])
	{
		t -= daytab[0][month];

		if (vis() && month == 2)
			t--;

		if (month == 12)
		{
			month = 1;
			year++;
		}
		else
			month++;
	}

	day += t;

	if (day == 0)
	{
		day = 29;
		month = 2;
	}

	return *this;
}

MyDate& MyDate::operator-=(int t)
{
	while (day - t <= 0)
	{
		if (vis() && month == 3)
			day++;

		if (month == 1)
		{
			month = 12;
			year--;
		}
		else
			month--;

			t -= daytab[0][month];
	}

	day -= t;

	return *this;
}

std::istream& operator>>(std::istream& i, MyDate& s)
{
	s.input();

	return i;
}

std::ostream& operator<<(std::ostream& o, MyDate s)
{
	s.output();

	return o;
}

std::FILE* operator>>(FILE* f, MyDate& d)
{
	d.in(d.year, f);
	d.in(d.month, f);
	d.in(d.day, f);

	return f;
}

std::FILE* operator<<(std::FILE* f, const MyDate& d)
{
	MyDate dd = d;
	
	dd.out(dd.year, f);
	dd.out(dd.month, f);
	dd.out(dd.day, f);

	return f;
}

MyDate operator+(const MyDate& left, const int right)
{
	MyDate t = left;

	t += right;

	return t;
}

MyDate operator-(const MyDate& left, const int right)
{
	MyDate t = left;

	t -= right;

	return t;
}

int operator-(const MyDate& left, const MyDate& right)
{
	int l = left.year * 365 + left.year / 4 + left.day;

	for (int i = 0; i < left.month; i++)
		l += left.daytab[0][i];

	int r = right.year * 365 + right.year / 4 + right.day;

	for (int i = 0; i < right.month; i++)
		r += right.daytab[0][i];

	return l - r;
}

int operator==(const MyDate& left, const MyDate& right)
{
	return left.equal(right);
}