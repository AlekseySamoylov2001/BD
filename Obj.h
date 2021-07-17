#pragma once
#include "MyConvert.h"

class MyString;
class Obj 
{
public:
	virtual ~Obj() {}
	virtual MyString* ToMyString() = 0;
	virtual Obj* copy() = 0;
	virtual void dispose() = 0;
	virtual int equal(const Obj&)const = 0;
	virtual int cmp(const Obj&)const = 0;
};
