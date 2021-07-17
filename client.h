#pragma once
#include "MyString.h"
#include "io.h"
using namespace std;

class client : public InOut
{
	MyString name;
	int phone;
	MyString pasport;

public:

	client();
	client(const client& c);
	client(MyString n, int ph, MyString pa);

	int input();
	int output();
	int input(FILE* f);
	int output(FILE* f);
	void outputP();

	int equal(const client& r)const;
	int cmp(const client& r)const;

	int equal(const Obj& t)const;
	int cmp(const Obj& t)const;

	MyString* ToMyString();

	Obj* copy();

	void dispose();

	~client();
};