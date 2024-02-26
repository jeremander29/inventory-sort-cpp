//Jeremiah Ibarra
//CS132
//Mr. MacKay
//Project 2
//11.07.2023
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
