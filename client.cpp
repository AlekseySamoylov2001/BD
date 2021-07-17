#define _CRT_SECURE_NO_WARNINGS
#include "client.h"

client::client() :name(), pasport()
{
	phone = 0;
}

client::client(const client& c)
{
	name = c.name;
	phone = c.phone;
	pasport = c.pasport;
}

client::client(MyString n, int ph, MyString pa)
{
	name = n;
	phone = ph;
	pasport = pa;
}

int client::input()
{
	cout << "¬ведите им€: ";
	cin >> name;
	cout << "¬ведите номер телефона: ";
	cin >> phone;
	cout << "¬ведите паспортные данные: ";
	cin >> pasport;

	return 1;
}

int client::output()
{
	cout.setf(ios::left);
	cout.width(20);
	cout << name << "|";
	cout.width(13);
	cout << phone<< "|";
	cout.width(13);
	cout << pasport;

	return 1;
}

int client::input(FILE* f)
{
	f >> name;

	char* buf = new char[200];
	phone = stoi(fgets(buf, 12, f));
	delete[] buf;

	f >> pasport;

	return 0;
}

int client::output(FILE* f)
{
	f << name;
	char s[200];

	sprintf(s, "%d", phone); // заносим число в строку
	fputs(s, f);
	fputc('\n', f);

	f << pasport;

	return 0;
}

void client::outputP()
{
	cout.width(13);
	cout << pasport << "|";
}

int client::equal(const client& r)const
{
	return
		((r.name.length() != 0) ? name == r.name : 1) &&
		((r.phone != 0) ? r.phone == phone : 1) &&
		((r.pasport.length() != 0) ? r.pasport == pasport : 1);
}

int client::cmp(const client& r)const
{
	int cond;
	MyString s(r.name);

	if (s.length() != 0 && (cond = name.cmp(r.name)))
		return cond;
	else
		return pasport.cmp(r.pasport);
}

int client::equal(const Obj& t)const
{
	return equal((const client&)t);
}

int client::cmp(const Obj& t)const
{
	return cmp((const client&)t);
}

MyString* client::ToMyString()
{
	char s[8] = "client";
	return new MyString(s);
}

Obj* client::copy()
{
	return new client(*this);
}

void client::dispose()
{
	name.dispose();
	pasport.dispose();
}

client::~client() {}