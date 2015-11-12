#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "ChainNode.h"

class Chain
{
private :
	ChainNode* first;

	ChainNode* prePtr;
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
	ChainNode* getCurrent()
	{
		return currentPtr;
	}
	void currentSetNext();

	ChainNode* getCurrentLink() const;
	Student getCurrentData() const;


};

#endif
