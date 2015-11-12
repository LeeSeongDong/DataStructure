#include "Taskmanager.h"

int main()
{
	IoHandler ioh;

	Taskmanager<int> tm;
	Tree<int> tree(ioh.inputNum("��� ������ �Է��ϼ��� : "));

	tm.printTree(tree);

	tm.preOrderTraversal(tree);
	tm.inOrderTraversal(tree);
	tm.postOrderTraversal(tree);
	tm.levelOrderTraversal(tree);

	return 0;
}