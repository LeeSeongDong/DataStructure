#ifndef __CHAINNODE_H__
#define __CHAINNODE_H__

#include "Term.h"

class ChainNode
{
	friend class PolynomialChain;

private:
	Term data;
	ChainNode* link;

	ChainNode()
	{
		link = NULL;
	};
	ChainNode(Term &term)
	{
		data = term;
		link = NULL;
	};
	~ChainNode() {};
};

#endif
