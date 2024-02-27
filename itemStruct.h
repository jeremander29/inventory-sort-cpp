//Jeremiah Ibarra
//inventorySort
#include <iostream>
using namespace std;

#ifndef itemStruct
#define itemStruct

struct item
{
	

	string name;
	double price;
	int stock;
	int maxLevel;


	bool operator== (item);
	bool operator< (const item& i);
	bool operator<= (const item& i);
	void operator= (const item& i);

};

istream& operator>> (istream&, item&);
ostream& operator<< (ostream&, item);



#endif
