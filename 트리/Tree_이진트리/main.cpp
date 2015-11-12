#include "Taskmanager.h"

int main()
{
	Taskmanager<int> tm;
	Tree<int> tree;

	tm.makeTree(tree);

	tree.currentSetRoot();

	tm.printTree(tree);

	tm.preOrderTraversal(tree);
	tm.inOrderTraversal(tree);
	tm.postOrderTraversal(tree);
	tm.levelOrderTraversal(tree);

	return 0;
}