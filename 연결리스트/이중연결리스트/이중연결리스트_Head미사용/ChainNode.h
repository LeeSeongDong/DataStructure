#ifndef __CHAINNODE_H__
#define __CHAINNODE_H__

#include "Student.h"

class ChainNode
{
	friend class Chain;

private:
	Student data;
	ChainNode* left;
	ChainNode* right;

	ChainNode()
	{
		left = NULL;
		right = NULL;
	};
	ChainNode(Student &std)
	{
		data = std;
		left = NULL;
		right = NULL;
	};
	~ChainNode() {};
};

#endif
