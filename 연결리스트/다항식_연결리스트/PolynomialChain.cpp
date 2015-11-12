#include "PolynomialChain.h"

//���� ��������
void PolynomialChain::insertNode(Term &term)
{
	ChainNode* node = new ChainNode(term);
	bool flag = false;	//���̿� ���������� true, �������� ���Եɶ� false

	currentSetFirst();

	while (currentPtr)
	{
		if (currentPtr->data.exp < node->data.exp)
		{
			flag = true;
			break;
		}
		//������ ������
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

//current������
void PolynomialChain::deleteCurrentNode()
{
	prePtr->link = currentPtr->link;
		
	delete currentPtr;
}

//current�� head��
void PolynomialChain::currentSetFirst()
{
	prePtr = first;
	currentPtr = first->link;
}

//current�� current->link��
void PolynomialChain::currentSetNext()
{
	prePtr = currentPtr;
	currentPtr = currentPtr->link;
}

//ü���� �޸� ����
//�Ҹ��ڿ��� ȣ��
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

//this�� chain�� �� ����
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