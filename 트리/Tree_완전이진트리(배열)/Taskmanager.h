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

	void printTree(Tree<T> &tree)
	{
		IoHandler ioh;

		tree.printTree(ROOT, 1);
		ioh.putNewline();
	}
};

#endif