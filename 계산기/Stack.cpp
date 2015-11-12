#include "Stack.h"

bool Stack::isFull() const
{
	if (top == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::doubleCapacity()
{
	Term *temp;

	temp = new Term[capacity * 2];

	for (int i = 0; i < capacity; ++i)
	{
		temp[i] = val[i];
	}

	delete[]val;

	val = temp;

	capacity *= 2;
}

Term Stack::pop()
{
	--top;
	return val[top];
}

void Stack::push(Term inputVal)
{
	if (isFull())
	{
		doubleCapacity();
	}

	val[top] = inputVal;
	++top;

}