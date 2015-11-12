#ifndef __TREE_H__
#define __TREE_H__

#include "IoHandler.h"
#include "Node.h"
#include <queue>
#include <stack>

template <class T>
//완전이진트리
class Tree
{
private :
	Node<T> *head;
	Node<T> *currentPtr;
	int numOfNode;

	void deleteNode()
	{
		currentPtr = head;
		stack<int> s;

		int temp = numOfNode;

		while (temp != 0)
		{
			if (temp % 2 == 0)
			{
				s.push(LEFT);
			}
			else
			{
				s.push(RIGHT);
			}

			temp /= 2;
		}

		while (s.size() != 1)
		{
			if (s.top() == LEFT)
			{
				currentPtr = currentPtr->left;
			}
			else
			{
				currentPtr = currentPtr->right;
			}

			s.pop();
		}

		if (s.top() == LEFT)
		{
			delete currentPtr->left;
			currentPtr->left = NULL;

			numOfNode -= 1;
		}
		else
		{
			delete currentPtr->left;
			delete currentPtr->right;

			currentPtr->left = NULL;
			currentPtr->right = NULL;

			numOfNode -= 2;
		}

	}
	void deleteTree()
	{
		while (numOfNode != 1)
		{
			deleteNode();
		}

		delete head->right;
	}

public :
	Tree()
	{
		head = new Node < T > ;
		currentPtr = head;
		numOfNode = 0;
	};
	~Tree()
	{
		deleteTree();
	};

	Node<T>* getRoot()
	{
		return head->right;
	}
	void currentSetRoot()
	{
		currentPtr = head->right;
	}

	void addNode(T data)
	{
		Node<T> *newNode = new Node<T>(data);
		currentPtr = head;

		++numOfNode;
		stack<int> s;

		int temp = numOfNode;

		//add할 위치
		while (temp != 0)
		{
			if (temp % 2 == 0)
			{
				s.push(LEFT);
			}
			else
			{
				s.push(RIGHT);
			}

			temp /= 2;
		}

		while (!s.empty())
		{
			if (s.size() == 1)
			{
				if (s.top() == LEFT)
				{
					currentPtr->left = newNode;
				}
				else
				{
					currentPtr->right = newNode;
				}

				break;
			}

			if (s.top() == LEFT)
			{
				currentPtr = currentPtr->left;
			}
			else
			{
				currentPtr = currentPtr->right;
			}

			s.pop();
		}	
	}

	void visit(Node<T> *currentNode)
	{
		IoHandler ioh;

		ioh.printNode(currentNode->data);
	}

	void preOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Preorder    : ");
		preOrder(head->right);
		ioh.putNewline();
	}
	void preOrder(Node<T> *currentNode)
	{
		if (currentNode)
		{
			visit(currentNode);
			preOrder(currentNode->left);
			preOrder(currentNode->right);
		}
	}

	void inOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Inorder     : ");
		inOrder(head->right);
		ioh.putNewline();
	}
	void inOrder(Node<T> *currentNode)
	{
		if (currentNode)
		{
			inOrder(currentNode->left);
			visit(currentNode);
			inOrder(currentNode->right);
		}
	}

	void postOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Postorder   : ");
		postOrder(head->right);
		ioh.putNewline();
	}
	void postOrder(Node<T> *currentNode)
	{
		if (currentNode)
		{
			postOrder(currentNode->left);
			postOrder(currentNode->right);
			visit(currentNode);
		}
	}

	void levelOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Level order : ");

		queue<Node<T>*> q;

		Node<T> *currentNode = head->right;

		while (currentNode)
		{
			visit(currentNode);
			if (currentNode->left)
			{
				q.push(currentNode->left);
			}
			if (currentNode->right)
			{
				q.push(currentNode->right);
			}
			if (q.empty())
			{
				return;
			}

			currentNode = q.front();
			q.pop();
		}

		ioh.putNewline();
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

			ioh.printNode(currentNode->data);

			if (currentNode->left)
			{
				printTree(currentNode->left, depth + 1);
			}

			if (currentNode->right)
			{
				ioh.printTab(depth);
				printTree(currentNode->right, depth + 1);
			}
		}
	}
};

#endif