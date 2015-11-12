#include "Taskmanager.h"

void Taskmanager::makeTree(Tree<string> &tree)
{
	IoHandler ioh;
	string inputData;

	ioh.putMsg("���ڿ����� �Է��ϼ��� (�������� 0) : ");
	while (true)
	{
		inputData = ioh.inputMsg("");

		if (inputData == "0")
		{
			break;
		}

		if (tree.getSize() < inputData.size())
		{
			tree.setSize(inputData.length());
		}
		
		if (!tree.addNode(inputData))
		{
			ioh.putMsg("�ߺ��� �������Է�!");
			return;
		}
	}
}

void Taskmanager::runProgram(Tree<string> &tree)
{
	IoHandler ioh;

	while (true)
	{
		int menu = ioh.inputNum("����� �����ϼ��� [1.Ʈ�������, 2.����, 3.����, 0.����] : ");

		switch (menu)
		{
		case 1:	//tree���θ����
			tree.deleteTree(tree.getHead());
			makeTree(tree);
			break;
		case 2: //����
			addNode(tree);
			break;
		case 3: //����
			deleteNode(tree);
			break;
		case 0: //����
			return;

		default:
			ioh.putMsg("�߸��� �Է�");
			break;
		}
		
		printTree(tree);
		ioh.putNewLine();
	}
}

void Taskmanager::addNode(Tree<string> &tree)
{
	IoHandler ioh;

	string inputData = ioh.inputMsg("�߰��� ���ڿ��� �Է��ϼ��� : ");
	if (tree.getSize() < inputData.size())
	{
		tree.setSize(inputData.length());
	}

	if (!tree.addNode(inputData))
	{
		ioh.putMsg("�ߺ��� �������Է�!");
	}
}

void Taskmanager::deleteNode(Tree<string> &tree)
{
	IoHandler ioh;

	string inputData = ioh.inputMsg("������ ���ڿ��� �Է��ϼ��� : ");

	if (!tree.deleteNode(inputData))
	{
		ioh.putMsg("���� ���ڿ��Դϴ�");
	}
}

void Taskmanager::printTree(Tree<string> &tree)
{
	tree.printTree(tree.getRoot(), 1);
}