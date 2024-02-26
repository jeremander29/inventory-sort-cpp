#include <iostream>
using namespace std;

#include "inventoryStruct.h"

istream& operator>> (istream& in, inventory& inv)
{
	in >> inv.items;
	return in;
}

ostream& operator<< (ostream& out, inventory inv)
{
	out << inv.items;
	return out;
}

bool inventory::operator== (inventory inv)
{
	if (items == inv.items)
	{
		return true;
	}
	else

	{
		return false;
	}
}

bool inventory::operator< (const inventory& inv)
{
	if (items < inv.items)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool inventory::operator<= (const inventory& inv)
{
	if (items <= inv.items)
	{
		return true;
	}
	else
	{
		return false;
	}

}