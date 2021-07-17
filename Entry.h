#include "MyDate.h"
#include "client.h"
#include "room.h"

class Entry : public InOut
{
	client* c;
	room* r;
	/*int number;
	MyString type;
	double price;
	MyString pasport;*/
	MyDate date;

public:
	Entry();
	Entry(Entry* r);
	Entry(client* cl, room* rm, MyDate d);
	~Entry();

	int input();
	int output();
	int input(Obj* a, Obj* b);
	int input(Obj* a, Obj* b, FILE* f);
	int input(FILE* f);
	int output(FILE* f);
	//int input(DataGridView^ d, const int i);
	//int output(DataGridView^ d, const int i);

	int equal(const Entry& t)const;
	int cmp(const Entry& t)const;

	int equal(const Obj& t)const;
	int cmp(const Obj& t)const;

	MyString* ToMyString();

	Obj* copy();

	void dispose();
	//friend std::istream& operator>>(std::istream& i, Entry& s);
	//friend std::ostream& operator<<(std::ostream& o, const Entry& s);
	//friend FILE* operator>>(FILE* f, Entry& s);
	//friend FILE* operator<<(FILE* f, const Entry& s);
};