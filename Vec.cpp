#include "Vec.h"

Vec::Vec()
{
	size = 5;
	v = new E[size];
}

Vec::Vec(int sz)
{
	size = sz;
	v = new E[size];
}

Vec::~Vec()
{
	delete[] v;
}

E* Vec::begin()
{
	return v;
}

E* Vec::end()
{
	return v + size;
}

int Vec::get_size()
{
	return size;
}

void Vec::resize(int n)
{
	E* w = v;
	E* p = new E[n]; // выделяем новое место в памяти
	int len = size;
	for (E* cur = p; cur != &p[size]; cur++)
		*cur = *w++;

	delete[] v; // очищаем память, выделенную под старый вектор

	size = n;
	v = p; // изменяем указатель
}

E& Vec::item(int n) // возвращаем определенную запись для ее последующего изменения
{
	if (n >= 0 && n < size)
		return v[n];

	std::cout << "Incorrect index" << std::endl;
	exit(0);
}