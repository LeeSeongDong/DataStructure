#ifndef __NODE_H__
#define __NODE_H__

#include "Header.h"

template <class T>
class Node
{
	template <class T>
	friend class Chain ;
private:
	T data;
	Node<T>* link;

public:
	Node() {};
	Node(T data) 
	{
		this->data = data;
		link = NULL;
	}
	~Node() {};
};

#endif
