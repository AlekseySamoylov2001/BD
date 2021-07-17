#pragma once
#include "Entry.h"

typedef Obj* E;

class Vec
{
	E* v;
	int size;

public:

	Vec();
	Vec(int sz);
	~Vec();

	E* begin();
	E* end();
	int get_size();
	void resize(int n);

	E& item(int i);
};

