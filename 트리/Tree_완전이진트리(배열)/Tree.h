#ifndef __TREE_H__
#define __TREE_H__

#include "IoHandler.h"
#include "Header.h"
#include <queue>
#include <stack>

template <class T>
//완전이진트리
class Tree
{
private :
	T *root;
	int numOfNode;

	void makeTree()
	{
		for (int i = 1; i <= numOfNode; ++i)
		{
			root[i] = i;
		}
	}

public :
	Tree(int numOfNode)
	{
		this->numOfNode = numOfNode;
		root = new T[numOfNode + 1];

		makeTree();
	};
	~Tree()
	{
		delete[]root;
	};

	void visit(T data)
	{
		IoHandler ioh;

		ioh.printNode(data);
	}

	void preOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Preorder    : ");
		preOrder(ROOT);
		ioh.putNewline();
	}
	void preOrder(int index)
	{
		if (index <= numOfNode)
		{
			visit(root[index]);
			preOrder(index*2);
			preOrder((index*2) +1);
		}
	}

	void inOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Inorder     : ");
		inOrder(ROOT);
		ioh.putNewline();
	}
	void inOrder(int index)
	{
		if (index <= numOfNode)
		{
			inOrder(index*2);
			visit(root[index]);
			inOrder((index*2) +1);
		}
	}

	void postOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Postorder   : ");
		postOrder(ROOT);
		ioh.putNewline();
	}
	void postOrder(int index)
	{
		if (index <= numOfNode)
		{
			postOrder(index*2);
			postOrder((index*2) +1);
			visit(root[index]);
		}
	}

	void levelOrder()
	{
		IoHandler ioh;

		ioh.putMsg("Level order : ");

		for (int i = 1; i <= numOfNode; ++i)
		{
			visit(root[i]);
		}

		ioh.putNewline();
	}

	void printTree(int index, int depth)
	{
		IoHandler ioh;

		if (index <= numOfNode)
		{
			if (depth != 1)
			{
				ioh.printBranch();
			}

			ioh.printNode(root[index]);

			if ( (index*2) <= numOfNode)
			{
				printTree(index*2, depth + 1);
			}

			if ( ((index*2)+1) <= numOfNode)
			{
				ioh.printTab(depth);
				printTree( (index*2)+1, depth + 1);
			}
		}
	}
};

#endif