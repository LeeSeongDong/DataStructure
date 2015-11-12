#ifndef __NODE_H__
#define __NODE_H__

#include "Header.h"

template <class T>
class Node
{
	template <class T>
	friend class Tree;
	friend class Expression;
	friend class Calculator;

private:
	Node()
	{
		left = NULL;
		right = NULL;
	};
	Node(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	};
	~Node() {};

	T data;
	Node<T> *left;
	Node<T> *right;

};

#endif