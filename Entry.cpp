#define _CRT_SECURE_NO_WARNINGS
#include "Entry.h"

using namespace std;

Entry::Entry()
{
	c = new client();
	r = new room();
}

Entry::Entry(Entry* r) :c(r->c), r(r->r), date(r->date)
{
}

Entry::Entry(client* cl, room* rm, MyDate d) : c(cl), r(rm), date(d)
{
}

Entry::~Entry()
{
}

void Entry::dispose()
{
	c->dispose();
	r->dispose();
	date.dispose();
}

int Entry::equal(const Entry& t)const // функци€ проверки на совпадение записей
{
	return (c->equal(*t.c)) &&
		(r->equal(*t.r)) && 
		(date.equal(t.date));
}

int Entry::cmp(const Entry& t)const // функци€ сравнени€ записей по 3 пол€м: паспорту клиената, номеру комнаты, ее типу
{
	int cm;

	cm = c->cmp(*t.c);
	if (cm != 0)
		return cm;

	cm = r->cmp(*t.r);
	if (cm != 0)
		return cm;

	cm = date.cmp(t.date);
	if (cm != 0)
		return cm;

	return 0;
}

int Entry::equal(const Obj& t) const
{
	return equal((const Entry&)t);
}

int Entry::cmp(const Obj& t)const
{
	return cmp((const Entry&)t);
}

MyString* Entry::ToMyString()
{
	char s[6] = "Entry";
	return new MyString(s);
}

Obj* Entry::copy()
{
	return new Entry(*this);
}

int Entry::input()
{
	c->input();
	r->input();

	cout << "¬ведите дату выезда: ";
	cin >> date;

	return 1;
}

int Entry::input(Obj* a, Obj* b)
{
	c = (client*)a;
	r = (room*)b;

	cout << "¬ведите дату выезда: ";
	cin >> date;

	return 1;
}

int Entry::input(Obj* a, Obj* b, FILE* f)
{
	c = (client*)a;
	r = (room*)b;
	bool h = (f == NULL);

	f >> date;

	return 0;
}

int Entry::output()
{
	cout.setf(ios::left);

	c->output();

	r->output();

	cout.width(35);
	cout << date;
	cout << "|" << endl;

	return 0;
}

int Entry::input(FILE* f)
{
	c->input(f);

	r->input(f);

	date.input(f);

	fclose(f);

	return 0;
}

int Entry::output(FILE* f)
{
	c->output(f);

	r->output(f);

	date.output(f);

	fclose(f); // закрываем файл

	return 0;
}