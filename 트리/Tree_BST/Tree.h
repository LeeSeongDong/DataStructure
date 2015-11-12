#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"

template <class T>
class Tree
{
private:
	Node<T> *head;
	Node<T> *prePtr;
	Node<T> *currentPtr;
	int nodeSize;
	int numOfNode;
	bool leftOprSimbol;

public:
	Tree()
	{
		head = new Node < T > ;
		currentPtr = head;
		numOfNode = 0;
		nodeSize = 0;
		leftOprSimbol = false;
	};
	~Tree()
	{
		deleteTree(head);
	};

	int getSize()
	{
		return nodeSize;
	}
	void setSize(int size)
	{
		nodeSize = size;
	}

	Node<T>* getRoot()
	{
		return head->right;
	}
	Node<T>* getHead()
	{
		return head;
	}

	bool isExistNode(T data)
	{
		prePtr = head;
		currentPtr = head->right;
		leftOprSimbol = false;

		while (currentPtr)
		{
			if (currentPtr->data > data)
			{
				prePtr = currentPtr;
				currentPtr = currentPtr->left;
				leftOprSimbol = true;
			}
			else if (currentPtr->data < data)
			{
				prePtr = currentPtr;
				currentPtr = currentPtr->right;
				leftOprSimbol = false;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	T findNode(T data)
	{
		return currentPtr->data;
	}

	bool deleteNode(T data)
	{
		if (!isExistNode(data))
		{
			return false;
		}
		else
		{
			if (currentPtr->right && currentPtr->left)		//child가 두개일때 right의 젤 끝 left
			{
				Node<T>* findNodePtr;
				Node<T>* preFindNodePtr = NULL;
				findNodePtr = currentPtr->right;

				while (findNodePtr->left)
				{
					if (!findNodePtr->left->left)
					{
						preFindNodePtr = findNodePtr;
					}
					findNodePtr = findNodePtr->left;
				}

				if (currentPtr->right->left)
				{
					findNodePtr->right = currentPtr->right;
				}

				findNodePtr->left = currentPtr->left;


				if (leftOprSimbol)
				{
					prePtr->left = findNodePtr;
				}
				else
				{
					prePtr->right = findNodePtr;
				}

				if (preFindNodePtr)
				{
					preFindNodePtr->left = NULL;
				}
			}
			else if (currentPtr->right && !currentPtr->left)	//right만 있을때
			{
				if (leftOprSimbol)
				{
					prePtr->left = currentPtr->right;
				}
				else
				{
					prePtr->right = currentPtr->right;
				}
			}
			else if (!currentPtr->right && currentPtr->left)//left만 있을때
			{
				if (leftOprSimbol)
				{
					prePtr->left = currentPtr->left;
				}
				else
				{
					prePtr->right = currentPtr->left;
				}
			}
			else
			{
				if (leftOprSimbol)
				{
					prePtr->left = NULL;
				}
				else
				{
					prePtr->right = NULL;
				}
			}

			delete currentPtr;
			return true;
		}
	}

	bool addNode(T data)
	{
		Node<T>* node = new Node<T>(data);

		if (isExistNode(data))
		{
			return false;
		}
		else
		{
			if (leftOprSimbol)
			{
				prePtr->left = node;
			}
			else
			{
				prePtr->right = node;
			}

			return true;
		}
	}

	void printTree(Node<T> *currentNode, int depth)
	{
		IoHandler ioh;

		if (currentNode)
		{
			if (depth != 1)
			{
				ioh.printBranch();
			}

			ioh.printNode(currentNode->data, nodeSize);

			if (currentNode->left)
			{
				printTree(currentNode->left, depth + 1);
			}

			if (currentNode->right)
			{
				if (!currentNode->left)
				{
					ioh.printBranch();
					ioh.putMsg("0");
				}
				ioh.printTab(depth, nodeSize);
				printTree(currentNode->right, depth + 1);
			}
		}
	}

	void deleteTree(Node<T>* node)
	{
		if (node->left)
		{
			deleteTree(node->left);
			node->left = NULL;
		}
		if (node->right)
		{
			deleteTree(node->right);
			node->right = NULL;
		}

		if (!head->right)
		{
			return;
		}

		currentPtr = head;
		numOfNode = 0;
		nodeSize = 0;
		leftOprSimbol = false;

		delete node;
	}

};

#endif