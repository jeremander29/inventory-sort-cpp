//Jeremiah Ibarra
//inventorySort

//----- List.h -----
#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include "itemStruct.h"
using namespace std;

typedef item ElementType;
class List
{
private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
		
		Node()
			: next(0)
			{ }
		
		Node(ElementType dataValue)
			: data(dataValue), next(0)
			{ }


	}; //--- end of Node class



	typedef Node * NodePointer;

public:
	//------ List OPERATIONS
	List();    //default constructor, creates an empty list
	List(const List & origList);  //copy constructor
	~List();  //destructor
	const List & operator=(const List & rightSide);  //overloaded assignment operator
	bool empty();
	void insert(ElementType dataVal, int index);
	void erase(int index);
	void display(ostream & out) const;
	int search(ElementType value);
	item getFirst(ElementType i);
	item getNext(ElementType i);
	void selectionSort();
	void reverse();
	ElementType update(ElementType i, string s);

	

private:
	//------ DATA MEMBERS
	NodePointer first ;
	int mySize;
}; //--- end of List class

ostream & operator<<(ostream & out, const List & aList);
//istream & operator>>(istream & in, List & aList);



#endif
