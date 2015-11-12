#ifndef __STACK_H__
#define __STACK_H__

#include "Term.h"

class Stack
{
private :
	int top;
	int capacity;
	Term *val;

public :
	Stack()
	{
		top = 0;
		capacity = 4;
		val = new Term[capacity];
	};
	~Stack()
	{
		delete[]val;
	}

	bool isFull() const;
	void doubleCapacity();

	Term pop();
	void push(Term inputVal);

	int getNumOfVal() const
	{
		return top;
	}
	Term getTop() const
	{
		return val[top - 1];
	}
};

#endif
