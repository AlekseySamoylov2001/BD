#define _CRT_SECURE_NO_WARNINGS
#include "room.h"

using namespace std;

room::room():type()
{
	number = 0;
	price = 0;
}

room::room(const room& r)
{
	number = r.number;
	type = r.type;
	price = r.price;
}

room::room(int n, MyString t, double p)
{
	number = n;
	type = t;
	price = p;
}

int room::input()
{
	cout << "¬ведите номер комнаты: ";
	cin >> number;
	cout << "¬ведите тип комнаты: ";
	cin >> type;
	cout << "¬ведите цену за 1 день: ";
	cin >> price;

	return 1;
}

int room::output()
{
	cout.setf(ios::left);
	cout.width(6);
	cout << number << "|";
	cout.width(10);
	cout << type << "|";
	cout.width(10);
	cout << price;

	return 1;
}

int room::input(FILE* f)
{
	char* buf = new char[200];
	number = stoi(fgets(buf, 12, f));
	delete[] buf;

	f >> type;

	buf = new char[200];
	price = stod(fgets(buf, 18, f));
	delete[] buf;

	return 0;
}

int room::output(FILE* f)
{
	char s1[200];

	sprintf(s1, "%d", number); // заносим число в строку
	fputs(s1, f);
	fputc('\n', f);
	
	f << type;

	char s2[200];

	sprintf(s2, "%f", price); // заносим число в строку
	fputs(s2, f);
	fputc('\n', f);

	return 0;
}

void room::outputN()
{
	cout.width(6);
	cout << number << "|";
}

int room::equal(const room& r)const
{
	return
		((r.type.length() != 0) ? type == r.type : 1) &&
		((r.price != 0) ? r.price == price : 1) &&
		((r.number != 0) ? r.number == number : 1);
}

int room::cmp(const room& r)const
{
	int cond;
	MyString s(r.type);

	if (s.length() != 0 && (cond = type.cmp(r.type)))
		return cond;
	else
		return  number - r.number;
}

int room::equal(const Obj& t)const
{
	return equal((const room&)t);
}

int room::cmp(const Obj& t)const
{
	return cmp((const room&)t);
}

MyString* room::ToMyString()
{
	char s[5] = "room";
	return new MyString(s);
}

Obj* room::copy()
{
	return new room(*this);
}

void room::dispose()
{
	type.dispose();
}

room::~room() {}