//Jeremiah Ibarra
//CS132
//Mr. MacKay
//Project 2
//11.07.2023

//----- List.cpp -----
#include <iostream>
using namespace std;

#include "linkedlist.h"
//-- Definition of the class constructor
List::List()
	: first(0), mySize(0)
{ }

//-- Definition of the copy constructor
List::List(const List & origList)
{
	mySize = origList.mySize;
	first = 0;
	if (mySize == 0) return;
	NodePointer origPtr, lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != 0)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}
//-- Definition of the destructor
inline List::~List()
{
	NodePointer prev = first,
		ptr;
	while (prev != 0)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

// Definition of empty()
bool List::empty()
{
	return mySize == 0;
}
//-- Definition of the assignment operator
const List & List::operator=(const List & rightSide)
{
	mySize = rightSide.mySize;
	first = 0;
	if (mySize == 0) return *this;
	if (this != &rightSide)
	{
		this->~List();
		NodePointer origPtr, lastPtr;
		first = new Node(rightSide.first->data); // copy first node
		lastPtr = first;
		origPtr = rightSide.first->next;
		while (origPtr != 0)
		{
			lastPtr->next = new Node(origPtr->data);
			origPtr = origPtr->next;
			lastPtr = lastPtr->next;
		}
	}
	return *this;
}

//-- Definition of insert()
void List::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}
	mySize++;
	NodePointer newPtr = new Node(dataVal),
		predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}
//-- Definition of erase()
void List::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}
	mySize--;
	NodePointer ptr,
		predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}


//-- Definition of display()
void List::display(ostream & out) const
{
	NodePointer ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

//-- Definition of the output operator
ostream & operator<<(ostream & out, const List & aList)
{
	aList.display(out);
	return out;
}


//-- Definition of the search function
int List::search(ElementType value)
{
	NodePointer position = first;
	int pos = 0;

	while (position != NULL)
	{
		if (position->data.name == value.name)
		{
			return pos;
		}
		pos++;
		position = position->next;
	}
	return -1;
}
//Thought i needed but didnt
item List::getFirst(ElementType i)
{
	item firstItem = first->data;

	return firstItem;

}
//Thought i needed but didnt
item List::getNext(ElementType i)
{
	item nextItem = first->next->data;

	return nextItem;

}

//Alph sort funciton
void List::selectionSort()
{
	ElementType temp;

	NodePointer ptrStart = first;
	NodePointer ptr = ptrStart->next;
	NodePointer ptrMin = ptrStart;

	for (int i = 0; i < mySize -1; i++)
	{
		ptrMin = ptrStart;
		ptr = ptrStart->next;

		for (int j = i+1; j < mySize; j++)
		{

			if (ptrMin->data.name > ptr->data.name)
			{
				ptrMin = ptr;
			}
			ptr = ptr->next;
			
		}

		temp = ptrMin->data;
		ptrMin->data = ptrStart->data;
		
		ptrStart->data = temp;

		ptrStart = ptrStart->next;
	}
	 
	
}

//Update Item function
ElementType List::update(ElementType i, string s)
{
	NodePointer position = first;
	int pos = 0;

	while (position != NULL)
	{
		if (position->data.name == s)
		{
			position->data.name = s;
		}
		pos++;
		position = position->next;
	}
	return i;
}

//Reverse function (test)

void List::reverse()
{

	for (NodePointer i = first; i != nullptr; i = i->next)
	{
		for (NodePointer j = i->next; j != nullptr; j = j->next)
		{
			if (i->data.name < j->data.name)
			{
				item temp = i->data;
				i->data = j->data;
				j->data = temp;

			}
		}
	}
}
