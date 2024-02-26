//Jeremiah Ibarra
//CS132
//Mr. MacKay
//Project 2
//11.07.2023
#include <iostream>
using namespace std;

#include "itemStruct.h"

istream& operator>> (istream& in, item& it)
{
	in >> it.name >> it.price >> it.stock >> it.maxLevel;
	return in;
}

ostream& operator<< (ostream& out, item it)
{
	out << it.name << ' ' << it.price << ' ' << it.stock << ' ' << it.maxLevel << endl;
	return out;
}

bool item::operator== (item i)
{
	if (name == i.name && price == i.price && stock == i.stock && maxLevel == i.maxLevel)
	{
		return true;
	}
	else

	{
		return false;
	}
}

bool item::operator< (const item& i)
{
	if (name < i.name && price < i.price && stock < i.stock && maxLevel < i.maxLevel)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool item::operator<= (const item& i)
{
	if (name <= i.name && price < i.price && stock <= i.stock && maxLevel <= i.maxLevel)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void item::operator= (const item& i)
{
	name = i.name;
	price = i.price;
	stock = i.stock;
	maxLevel = i.maxLevel;
}






