#ifndef __POLYNOMIALCHAIN_H__
#define __POLINOMIALCHAIN_H__

#include "ChainNode.h"

class PolynomialChain
{
private :
	ChainNode* first;

	ChainNode* prePtr;
	ChainNode* currentPtr;


public :
	PolynomialChain()
	{
		first = new ChainNode;
	};
	~PolynomialChain()
	{
		deleteChain();
		delete first;
	};

	void insertNode(Term &term);
	void deleteCurrentNode();
	void deleteChain();

	void copyChain(PolynomialChain &chain);

	void currentSetFirst();
	ChainNode* getCurrent()
	{
		return currentPtr;
	}
	void currentSetNext();

	ChainNode* getFirstLink() const;
	ChainNode* getCurrentLink() const;
	Term getCurrentData() const;


};

#endif
