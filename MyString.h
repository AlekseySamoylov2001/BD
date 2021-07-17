#pragma once

#include "io.h"

class MyString : public InOut
{
	char* str;
	int len;

public:

	MyString();
	MyString(char* s);
	MyString(const MyString& s);
	~MyString();

	void dispose();
	void assign(const MyString& t);

	Obj* copy();

	int length()const;

	char* ToPchar();
	int ToInt();
	double ToDouble();
	MyString* ToMyString();

	int equal(const MyString& t)const;
	int cmp(const MyString& t)const;

	int equal(const Obj& t)const;
	int cmp(const Obj& t)const;

	int input();
	int output();
	int input(FILE* f);
	int output(FILE* f);

	MyString& operator=(const MyString& t);
	MyString& operator+=(const MyString& t);
	operator char*();
	char& operator[](int i);

	friend std::istream& operator>>(std::istream& i, MyString& s);
	friend std::ostream& operator<<(std::ostream& o, const MyString s);
	friend FILE* operator>>(FILE* f, MyString& s);
	friend FILE* operator<<(FILE* f, const MyString s);
	friend MyString operator+(const MyString& left, const MyString& right);
	friend int operator==(const MyString& left, const MyString& right);
};
