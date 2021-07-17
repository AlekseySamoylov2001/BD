#define _CRT_SECURE_NO_WARNINGS

#include "Tabl.h"		

using namespace std;

Tabl** T = new Tabl * [3];
int tabl = 0;

void next()
{
	tabl++;
	if (tabl == 3)
		tabl = 0;
}

void Read()
{
	Obj* r;

	if (tabl == 0)
	{
		r = new client(); 
		((InOut*)r)->input(); // вводим запись
	}
	else if (tabl == 1)
	{
		r = new room();
		((InOut*)r)->input();
	}
	else
	{
		int a, b;
		r = new Entry();
		cout << "Введите индексы: " << endl << "Клиента: ";
		cin >> a;
		cout << "Комнаты: ";
		cin >> b;
		((Entry*)r)->input(T[0]->item(a), T[1]->item(b)); // создаем связь с двумя другими таблицами
	}
		

	T[tabl]->insert(r); // помещаем в конец таблицы
}

void Delete()
{
	Obj* r;

	if (tabl == 0)
		r = new client();
	else if (tabl == 1)
		r = new room();
	else
		r = new Entry();

	((InOut*)r)->input();

	cout << "Удалено: " << T[tabl]->remove(r) << endl;
}

void Change()
{
	cout << "Введите запись которую нужно изменить: " << endl;

	Obj* rOLD;

	if (tabl == 0)
		rOLD = new client();
	else if (tabl == 1)
		rOLD = new room();
	else
		rOLD = new Entry();

	((InOut*)rOLD)->input();

	cin.ignore();
	cout << "Введите запись на которую нужно заменить: " << endl;

	Obj* r;

	if (tabl == 0)
		r = new client();
	else if (tabl == 1)
		r = new room();
	else
		r = new Entry();

	((InOut*)r)->input();

	cout << "Изменено: " << T[tabl]->replace(rOLD, r) << endl;
}

void Sort()
{
	T[tabl]->sort();
}

void Find()
{
	Obj* r;

	if (tabl == 0)
		r = new client();
	else if (tabl == 1)
		r = new room();
	else
		r = new Entry();

	((InOut*)r)->input();

	int i = T[tabl]->find(r);
	cout << "Номер записи: " << i << endl;
}

void Save()
{
	for (int i = 0; i < 3; i++)
	{
		MyString* s = new MyString((char*)"HEAD");

		char* s1 = new char[2];
		sprintf(s1, "%d", i);

		MyString* ss = new MyString((char*)s1);
		MyString* sss = new MyString((char*)".txt");

		FILE* HEAD = fopen((*s + *ss + *sss).ToPchar(), "w");
		int COUNT = T[i]->lenght();
		char s2[200];

		sprintf(s2, "%d", COUNT);
		fprintf(HEAD,"%s", s2);
		fputc('\n', HEAD);

		T[i]->Output(HEAD);

		fclose(HEAD);
	}
}

void ReadMF(char* f)
{
	FILE* FF = fopen(f, "r");

	Obj* r;

	if (tabl == 0)
	{
		r = new client();
		((InOut*)r)->input(FF);
	}
	else if (tabl == 1)
	{
		r = new room();
		((InOut*)r)->input(FF);
	}
	else
	{
		Obj* rc = new client();
		Obj* rr = new room();
		r = new Entry();

		((InOut*)rc)->input(FF); 
		((InOut*)rr)->input(FF);

		((Entry*)r)->input(T[0]->item(T[0]->find(rc)), T[1]->item(T[1]->find(rr)), FF);

		delete rc, rr;
	}

	fclose(FF);
	T[tabl]->insert(r);
}

void ReadF()
{
	for (int i = 0; i < 3; i++)
	{
		FILE* HEAD;
		char buf[200];
		int COUNT;

		T[tabl] = new Tabl();

		MyString* s = new MyString((char*)"HEAD");

		char* s1 = new char[2];
		sprintf(s1, "%d", tabl);

		MyString* ss = new MyString((char*)s1);
		MyString* sss = new MyString((char*)".txt");

		HEAD = fopen((*s + *ss + *sss).ToPchar(), "r");

		if (HEAD == NULL)
			cout << "Отсутствуют файлы" << endl;
		else
		{
			COUNT = stoi(fgets(buf, 200, HEAD));

			for (int j = 0; j < COUNT; j++)
			{
				int k = 0;
				char c;
				char* buf1 = new char[255];

				while ((c = fgetc(HEAD)) != '\n')
					buf1[k++] = c;
				
				buf1[k] = '\0';

				ReadMF(buf1);
			}

			fclose(HEAD);
		}

		next();
	}
}

void Clear()
{
	T[tabl]->clear();
}

void help()
{
	cout << "      список команд:" << endl
		<< "n – ввести новую запись" << endl
		<< "w – показать всю таблицу" << endl
		<< "e – удалить определенную запись" << endl
		<< "a – удалить запись с определенной позиции" << endl
		<< "c – очистить таблицу" << endl
		<< "r – заменить все вхождения записи на новые" << endl
		<< "f – найти запись в таблице" << endl
		<< "g – сохранить таблицу в файл" << endl
		<< "t – взять таблицу из файла" << endl
		<< "s – сортировать записи" << endl
		<< "d – завершить работу" << endl
		<< "h – вывести список команд" << endl;
}

int main()
{
	setlocale(LC_ALL, "");

	for (int i = 0; i < 3; i++)
		T[i] = new Tabl();

	char command;

	help();

	while (true)
	{
		cout << "Введите команду: ";
		cin >> command;

		if (command == 'n')
			Read();

		else if (command == 'x')
		{
			next();
			cout << "Текущая таблица: " << tabl << endl;
		}

		else if (command == 'w')
			T[tabl]->Output();

		else if (command == 'e')
			Delete();

		else if (command == 'a')
		{
			cout << "Введите номер записи: ";
			int a;
			cin >> a;
			T[tabl]->removeAt(a);
		}

		else if (command == 'c')
			Clear();

		else if (command == 'r')
			Change();

		else if (command == 'f')
			Find();

		else if (command == 'g')
			Save();

		else if (command == 't')
			ReadF();

		else if (command == 's')
			Sort();

		else if (command == 'h')
			help();

		else if (command == 'd')
			break;

		else
			cout << "Неверная команда" << endl;
	}
}