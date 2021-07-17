#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

MyString::MyString(char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

MyString::MyString(const MyString& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::dispose()
{
	delete[] str;
}

void MyString::assign(const MyString& s) //функци€ суть Ц присвоение
{
	len = s.len;
	char* buf = new char[len + 1];
	strcpy(buf, s.str);

	dispose();

	str = buf;
}

Obj* MyString::copy() // вернуть копию существующей строки
{
	return new MyString(*this);
}

int MyString::length()const
{
	return len;
}

char* MyString::ToPchar()
{
	char* s = new char[len + 1];
	strcpy(s, str);

	return s;
}

int MyString::ToInt()
{
	return atoi(str);
}

double MyString::ToDouble()
{
	return atof(str);
}

MyString* MyString::ToMyString()
{
	char s[9] = "MyString";
	return new MyString(s);
}

int MyString::cmp(const MyString& s)const
{
	return strcmp(s.str, str);
}

int MyString::equal(const MyString& s)const
{
	return strcmp(s.str, str) == 0;
}

int MyString::equal(const Obj& t)const
{
	return equal((const MyString&)t);
}
int MyString::cmp(const Obj& t)const
{
	return cmp((const MyString&)t);
}

int MyString::input()
{
	char* buf = new char[255];

	std::cin.ignore();
	std::cin.getline(buf, 255);
	len = strlen(buf);

	str = new char[len + 1];
	strcpy(str, buf);

	delete[] buf;

	return len;
}

int MyString::output()
{
	std::cout << str;
	return 0;
}

int MyString::input(FILE* f)
{
	char b = ' ';
	char* buf = new char[200];
	int i = 0;

	while (true) // посимвольно читаем и запоминаем информацию пока не дойдем до конца строки
	{
		b = fgetc(f);
		if (b == '\n')
		{
			buf[i] = '\0';
			break;
		}
		else
			buf[i] = b;

		i++;
	}

	str = new char[strlen(buf) + 1];
	strcpy(str, buf);
	delete[] buf;

	buf = new char[200];
	len = std::stoi(fgets(buf, 12, f));
	delete[] buf;

	return 0;
}

int MyString::output(FILE* f)
{
	fputs(str, f); // заносим строку в файл
	fputc('\n', f); // переход на следующую строку в файле

	char s[200];

	sprintf(s, "%d", len); // заносим число в строку

	fputs(s, f);
	fputc('\n', f);

	return 0;
}

MyString& MyString::operator=(const MyString& t)
{
	if (this == &t)
		return *this;

	delete[] str;

	char* str_t = new char[t.len + 1];
	strcpy(str, t.str);

	len = t.len;

	return *this;
}

MyString& MyString::operator+=(const MyString& t)
{
	char* p = new char[len + t.len + 1];

	strcpy(p, str);
	strcat(p, t.str);

	dispose();

	str = p;
	len += t.len;

	return *this;
}

MyString::operator char*()
{
	char* t = new char[len + 1];
	strcpy(t, str);
	
	return t;
}

char& MyString::operator[](int i)
{
	return str[i];
}

std::istream& operator>>(std::istream& i, MyString& s)
{
	s.input();

	return i;
}

std::ostream& operator<<(std::ostream& o, const MyString s)
{
	return o << s.str;
}

FILE* operator>>(FILE* f, MyString& s)
{
	char b = ' ';
	char* buf = new char[200];
	int i = 0;

	while (true) // посимвольно читаем и запоминаем информацию пока не дойдем до конца строки
	{
		b = fgetc(f);
		if (b == '\n')
		{
			buf[i] = '\0';
			break;
		}
		else
			buf[i] = b;

		i++;
	}
	
	s.str = new char[strlen(buf) + 1];
	strcpy(s.str, buf);
	delete[] buf;

	buf = new char[200];
	s.len = std::stoi(fgets(buf, 12, f));
	delete[] buf;

	return f;
}

FILE* operator<<(FILE* f, const MyString s)
{
	MyString ss = s;
	fputs(ss.str, f); // заносим строку в файл
	fputc('\n', f); // переход на следующую строку в файле

	char h[200];

	sprintf(h, "%d", ss.len); // заносим число в строку

	fputs(h, f);
	fputc('\n', f);

	return f;
}
MyString operator+(const MyString& left, const MyString& right)
{
	MyString p = left;
	p += right;

	return p;
}

int operator==(const MyString& left, const MyString& right)
{
	return strcmp(left.str, right.str) == 0;
}
