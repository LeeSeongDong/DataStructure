#ifndef __ADJLISTNODE_H__
#define __ADJLISTNODE_H__

#include "Header.h"


class AdjListNode
{
private :
	friend class AdjListGraph;
	friend class DirectedAdjListGraph;

	int data;
	AdjListNode* link;

	AdjListNode()
	{
		link = NULL;
	}
	AdjListNode(int data)
	{
		this->data = data;
		link = NULL;
	}
	~AdjListNode() {};
};

#endif
