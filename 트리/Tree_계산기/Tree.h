#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"

template <class T>
class Tree
{
private :
	Node<T> *head;
	Node<T> *currentPtr;
	int nodeSize;
	int numOfNode;

public :
	Tree()
	{
		head = new Node < T >;
		currentPtr = head;
		numOfNode = 0;
		nodeSize = 0;
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

	Node<T>* makeTemrsToNode(Node<T>* left, Node<T>* parent)
	{
		parent->left = left;

		head->right = parent;
		return parent;
	}

	Node<T>* makeTermsToNode(Node<T>* left, Node<T>* right, Node<T>* parent)
	{
		parent->left = left;
		parent->right = right;

		head->right = parent;
		return parent;
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

		delete node;
	}

};

#endif