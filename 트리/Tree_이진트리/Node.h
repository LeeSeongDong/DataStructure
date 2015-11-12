#ifndef __NODE_H__
#define __NODE_H__

#include "Header.h"

template <class T>
class Node
{
template<class T>
friend class Tree;

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