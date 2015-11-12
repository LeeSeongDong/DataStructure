#include "PolynomialChain.h"

//지수 내림차순
void PolynomialChain::insertNode(Term &term)
{
	ChainNode* node = new ChainNode(term);
	bool flag = false;	//사이에 끼워넣을때 true, 마지막에 삽입될때 false

	currentSetFirst();

	while (currentPtr)
	{
		if (currentPtr->data.exp < node->data.exp)
		{
			flag = true;
			break;
		}
		//지수가 같을때
		else if (currentPtr->data.exp == node->data.exp)
		{
			currentPtr->data.coef += node->data.coef;

			if (!currentPtr->data.coef)
			{
				deleteCurrentNode();
			}

			delete node;
			return;
		}
		currentSetNext();
	}

	if (flag)
	{
		node->link = currentPtr;
	}

	prePtr->link = node;
}

//current노드삭제
void PolynomialChain::deleteCurrentNode()
{
	prePtr->link = currentPtr->link;
		
	delete currentPtr;
}

//current를 head로
void PolynomialChain::currentSetFirst()
{
	prePtr = first;
	currentPtr = first->link;
}

//current를 current->link로
void PolynomialChain::currentSetNext()
{
	prePtr = currentPtr;
	currentPtr = currentPtr->link;
}

//체인의 메모리 해제
//소멸자에서 호출
void PolynomialChain::deleteChain()
{
	while (first->link)
	{
		currentSetFirst();

		while (currentPtr->link)
		{
			currentSetNext();
		}

		deleteCurrentNode();
	}
}

//this에 chain의 값 복사
void PolynomialChain::copyChain(PolynomialChain &chain)
{
	deleteChain();

	currentSetFirst();
	chain.currentSetFirst();

	while (chain.getCurrent())
	{
		insertNode(chain.getCurrentData());
		chain.currentSetNext();
	}
}

ChainNode* PolynomialChain::getFirstLink() const
{
	return first->link;
}

ChainNode* PolynomialChain::getCurrentLink() const
{
	return currentPtr->link;
}

Term PolynomialChain::getCurrentData() const
{
	return currentPtr->data;
}