#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "ChainNode.h"

class Chain
{
private :
	ChainNode* first;

	ChainNode* currentPtr;

	void deleteChain();

public :
	Chain()
	{
		first = NULL;
	};
	~Chain()
	{
		deleteChain();
	};

	void insertNode(Student &std);
	void deleteNode(int stdNum);

	void currentSetFirst();
	void currentSetRight();
	void currentSetLeft();

	ChainNode* getFirst() const
	{
		return first;
	}
	ChainNode* getCurrent() const
	{
		return currentPtr;
	}
	Student getCurrentData() const;


};

#endif
