#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <windows.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class MyConvert
{
public:

	static int copyto(int* i, char buf[])
	{
		*i = atoi(buf);

		return 1;
	}

	static int copyto(double* i, char buf[])
	{
		*i = atof(buf);

		return 1;
	}

	static int copyto(char* s, int i)
	{
		return _itoa(i, s, 10) ? 1 : 0;
	}

	static int ToChar(char* out, wchar_t* in)
	{
		return WideCharToMultiByte(CP_ACP, 0, in, 1, out, 1, NULL, NULL);
	}
};