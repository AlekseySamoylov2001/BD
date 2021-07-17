#include "Vec.h"

class Tabl:Vec
{
	E* cur;

public:
	Tabl();
	~Tabl();

	E* begin();
	E* end();
	int lenght();

	int remove(E item);
	int removeAt(int pos);
	void clear();

	E* insert(const E& item);
	int find(E& item);
	int replace(E& Old, E& New);
	void sort();

	void Output();
	void Output(FILE* HEAD);
	//void Output(DataGridView^ d);

	E& item(int i);

};

