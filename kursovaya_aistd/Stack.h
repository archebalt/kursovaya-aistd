#pragma once
#include"Element.h"
class Stack
{
private:
	Element* top;
	int Size;
public:
	Stack();
	~Stack();
	bool isEmpty();
	Element* peek();
	Element* pop(); 
	Element* push(double); 
	void push(Element*);
};
