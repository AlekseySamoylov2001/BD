#pragma once

#include "MyString.h"

using namespace std;

class room : public InOut
{
	int number;
	MyString type;
	double price;

public:

	room();
	room(const room& r);
	room(int n, MyString t, double p);

	int input();
	int output();
	int input(FILE* f);
	int output(FILE* f);
	void outputN();

	int equal(const room& r)const;
	int cmp(const room& r)const;

	int equal(const Obj& t)const;
	int cmp(const Obj& t)const;	

	MyString* ToMyString();

	Obj* copy();

	void dispose();

	~room();
};