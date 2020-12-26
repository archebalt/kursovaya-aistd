#include "MyList.h"

MyList::MyList()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}
bool MyList::isEmpty() 
{
	if (Size == 0)
		return true;
	return false;
}

int MyList::size() 
{
	return Size;
}

Element* MyList::push(double data_key) 
{
	Element* new_element = new Element;
	new_element->setData(data_key);
	if (isEmpty())
	{
		head = tail = new_element;
	}
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
	return new_element;
}

Element* MyList::push(string data) // to add in the end of the queue the element with key-data
{
	Element* new_element = new Element;
	new_element->setData(data);
	if (isEmpty())
		head = tail = new_element;
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
	return new_element;
}

Element* MyList::push(double number, string data) 
{
	Element* new_element = new Element;
	new_element->setData(number, data);
	if (isEmpty())
		head = tail = new_element;
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
	return new_element;
}

void MyList::push(Element* new_element) 
{
	if (isEmpty())
		head = tail = new_element;
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
}
Element* MyList::popFront()
{
	Element* Delete;
	if (isEmpty())
		throw out_of_range("the queue is empty");
	else if (size() == 1)
	{
		Delete = head;
		head = tail = nullptr;
	}
	else
	{
		Delete = head;
		for (Element* now = tail; now->getNext() != nullptr; now = now->getNext())
			head = now;
		head->next = nullptr;
	}
	Size--;
	return Delete;
}
Element* MyList::pop() 
{
	Element* Delete = tail;
	if (isEmpty())
		throw out_of_range("the queue is empty");
	else if (size() == 1)
	{
		Delete = tail;
		head = tail = nullptr;
		Size--;
	}
	else
	{
		tail = tail->getNext();
		Size--;
	}
	return Delete;
}

MyList::~MyList()
{
	while (isEmpty() == false) pop();
	
}