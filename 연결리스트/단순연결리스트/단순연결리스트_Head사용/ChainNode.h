#ifndef __CHAINNODE_H__
#define __CHAINNODE_H__

#include "Student.h"

class ChainNode
{
	friend class Chain;

private:
	Student data;
	ChainNode* link;

	ChainNode()
	{
		link = NULL;
	};
	ChainNode(Student &std)
	{
		data = std;
		link = NULL;
	};
	~ChainNode() {};
};

#endif
