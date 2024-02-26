#include <iostream>
using namespace std;
#include "itemStruct.h"

#ifndef inventoryStruct
#define inventoryStruct

struct inventory
{


	item items;
	


	bool operator== (inventory);
	bool operator< (const inventory& inv);
	bool operator<= (const inventory& i);

};

istream& operator>> (istream&, inventory&);
ostream& operator<< (ostream&, inventory);





#endif
