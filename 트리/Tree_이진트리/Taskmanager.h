#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "Tree.h"

template <class T>
class Taskmanager
{
private :

public :
	Taskmanager() {};
	~Taskmanager() {};

	void preOrderTraversal(Tree<T> &tree)
	{
		tree.preOrder();
	}
	void inOrderTraversal(Tree<T> &tree)
	{
		tree.inOrder();
	}
	void postOrderTraversal(Tree<T> &tree)
	{
		tree.postOrder();
	}
	void levelOrderTraversal(Tree<T> &tree)
	{
		tree.levelOrder();
	}

	void makeTree(Tree<T> &tree)
	{
		IoHandler ioh;

		int numOfNode = ioh.inputNum("노드 개수를 입력하세요 : ");

		for (int i = 1; i <= numOfNode; ++i)
		{
			tree.addNode(i);
		}
	}

	void printTree(Tree<T> &tree)
	{
		IoHandler ioh;

		tree.printTree(tree.getRoot(), 1);
		ioh.putNewline();
	}
};

#endif