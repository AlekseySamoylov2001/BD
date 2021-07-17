#pragma once
#include "Obj.h"

class InOut : public Obj
{

public:
	virtual int input(FILE* fp) = 0;
	virtual int input() = 0;
	virtual int output(FILE* f) = 0;
	virtual int output() = 0;
};

