#pragma once
#include <stdexcept>
using namespace std;
class Element
{
	Element* next;
	double data;
	string String;
	void setData(string);
	void setNext(Element*);
	void setData(double, string);
	void setData(double);
public:
	Element();
	~Element();
	Element* getNext();
	double getData();
	string getString();
	friend class MyList;
	friend class Stack;
};