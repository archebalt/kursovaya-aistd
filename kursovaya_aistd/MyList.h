#pragma once
#include "Element.h"
class MyList
{
private:
	Element* head; 
	Element* tail; 
	int Size = 0;
public:
	MyList();
	~MyList();
	int size(); 
	bool isEmpty(); 
	Element* pop();
	Element* push(double);
	Element* push(string);
	Element* push(double, string);
	void push(Element*);
	Element* popFront();
};
