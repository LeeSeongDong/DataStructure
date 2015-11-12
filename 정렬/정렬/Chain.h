#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "Node.h"

template <class T>
class Chain
{
private:
	Node<T>* head;
	int numOfData;

	Node<T>* curPtr;

	void deleteChain();

public:
	Chain()
	{
		head = new Node<T>();
		numOfData = 0;
	};
	~Chain()
	{
		deleteChain();
	};

	Node<T>* getHead()
	{
		return head;
	}
	int getNumOfData()
	{
		return numOfData;
	}

	void setCurFirst()
	{
		curPtr = head->link;
	}
	void setCurNext()
	{
		if (!curPtr)
		{
			return;
		}
		else
		{
			curPtr = curPtr->link;
		}
	}

	T getCurData()
	{
		return curPtr->data;
	}

	void insertNode(T e);
	//void deleteNode(T& e);
	void insertionSort();
};

template <class T>
void Chain<T>::insertNode(T e)
{
	Node<T>* newNode = new Node<T>(e);

	newNode->link = head->link;
	head->link = newNode;

	++numOfData;
}

template <class T>
void Chain<T>::insertionSort()
{
	Node<T>* currentPtr = head->link;
	head->link = NULL;

	while (currentPtr)
	{
		Node<T>* nextPtr = currentPtr->link;
		Node<T>* preComparePtr = head;

		while (preComparePtr)
		{
			if (!preComparePtr->link)
			{
				preComparePtr->link = currentPtr;
				currentPtr->link = NULL;
				break;
			}
			else if (currentPtr->data < preComparePtr->link->data)
			{
				currentPtr->link = preComparePtr->link;
				preComparePtr->link = currentPtr;
				break;
			}
			else
			{
				preComparePtr = preComparePtr->link;
			}
		}

		currentPtr = nextPtr;
	}
}

template <class T>
void Chain<T>::deleteChain()
{
	while (true)
	{
		if (!head->link)
		{
			break;
		}

		Node<T>* currentPtr = head->link;

		head->link = currentPtr->link;
		currentPtr->link = NULL;
		delete currentPtr;
	}

	delete head;
}

#endif
