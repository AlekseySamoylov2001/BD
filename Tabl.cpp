#define _CRT_SECURE_NO_WARNINGS
#include "Tabl.h"

using namespace std;

Tabl::Tabl()
{
	cur = begin();
}

Tabl::~Tabl()
{
}

E* Tabl::begin()
{
	return Vec::begin();
}

E* Tabl::end()
{
	return cur;
}

int Tabl::lenght()
{
	return end() - begin();
}

E* Tabl::insert(const E& item)
{
	int len = lenght();
	if (len >= get_size())
	{
		resize(len + 10);
		cur = begin() + len;
	}

	*cur = item;
	cur = begin() + len + 1;

	return cur;
}

void Tabl::clear()
{
	for (int j = 0; j < lenght(); j++)
		item(j)->dispose(); // очищаем выделенную память

	cur = begin(); // указатель перемещается в начало вектора
}

int Tabl::remove(E item)
{
	int j = 0;
	int n = 0;

	for (int i = 0; i < lenght(); i++) // удаляем все вхождения записей, соответствующих аргументу
	{
		if (Vec::item(i)->equal(*item) == 0)
			Vec::item(j++) = Vec::item(i);
		else
			n++;
	}

	cur = &Vec::item(n); // смещаем указать на число удаленных записей

	return n;
}

int Tabl::removeAt(int pos)
{
	for (int j = pos; j < lenght() - 1; j++) // удаляем запись, стоящую на определенной позиции в векторе
		Vec::item(j) = Vec::item(j + 1);

	cur = &Vec::item(lenght() - 1); // смещаем указать на 1 позицию

	return 1;
}

int Tabl::find(E& item)
{
	E* i;

	for (i = begin(); i < end(); i++) // ищем первое вхождение записи, соответствующей аргументу
		if (item->equal(**i))
			return i - begin();

	return -1;
}

int Tabl::replace(E& Old, E& New)
{
	E* i;
	int count = 0;

	for (i = begin(); i < end(); i++) // заменяем все вхождения записей, соответствующих искомой, на новые
	{
		if (Old->equal(**i))
		{
			*i = New;
			count++;
		}
	}

	return count;
}

void Tabl::sort()  // стандартная сортировка
{
	for (int i = 0; i < lenght() - 1; i++)
	{
		for (int j = 0; j < lenght() - 1; j++)
		{
			if (Vec::item(i)->cmp(*Vec::item(i + 1)) < 0)
			{
				E temp = Vec::item(i);
				Vec::item(i) = Vec::item(i + 1);
				Vec::item(i + 1) = temp;
			}
		}
	}
}

void Tabl::Output()
{
	cout << "+–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––+";
	cout.setf(ios::left);
	/*
	cout << "|";
	cout.width(3);
	cout << "№";

	cout << "|";
	cout.width(15);
	cout << "Паспорт" << "|";

	cout.width(6);
	cout << "Номер" << "|";

	cout.width(15);
	cout << "Тип" << "|";

	cout.width(8);
	cout << "Цена" << "|";

	cout << "Дата выезда                        |" << endl;
	cout << "|–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|" << endl;*/

	int len = lenght();
	for (int j = 0; j < len; j++)
	{
		cout << endl;
		cout << "|";
		cout.width(3);
		cout << j;
		cout << " | ";
		((InOut*)Vec::item(j))->output();
	}

	cout << endl << "+–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––+" << endl;
}

void Tabl::Output(FILE* HEAD)
{
	for (int i = 0; i < lenght(); i++)
	{
		char s[50];
		sprintf(s, "%d", i);
		
		MyString* ss = new MyString((char*)s);
		MyString* sss = new MyString(*item(0)->ToMyString());

		char ssss[50];
		sprintf(ssss, "%s%s", ss->ToPchar(), sss->ToPchar());

		fputs(ssss, HEAD);
		fputc('\n', HEAD);

		FILE* f = fopen(ssss, "w");

		((InOut*)Vec::item(i))->output(f);

		fclose(f);
	}
}

//void Tabl::Output(DataGridView^ d)
//{
//	for (int i = 0; i < lenght(); i++)
//		Vec::item(i)->output(d, i);
//}

E& Tabl::item(int i)
{
		return Vec::item(i);
}

