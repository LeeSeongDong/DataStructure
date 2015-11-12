#include "Taskmanager.h"

void Taskmanager::makeTree(Tree<string> &tree)
{
	IoHandler ioh;
	string inputData;

	ioh.putMsg("문자열들을 입력하세요 (마지막은 0) : ");
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
			ioh.putMsg("중복된 데이터입력!");
			return;
		}
	}
}

void Taskmanager::runProgram(Tree<string> &tree)
{
	IoHandler ioh;

	while (true)
	{
		int menu = ioh.inputNum("기능을 선택하세요 [1.트리만들기, 2.삽입, 3.삭제, 0.종료] : ");

		switch (menu)
		{
		case 1:	//tree새로만들기
			tree.deleteTree(tree.getHead());
			makeTree(tree);
			break;
		case 2: //삽입
			addNode(tree);
			break;
		case 3: //삭제
			deleteNode(tree);
			break;
		case 0: //종료
			return;

		default:
			ioh.putMsg("잘못된 입력");
			break;
		}
		
		printTree(tree);
		ioh.putNewLine();
	}
}

void Taskmanager::addNode(Tree<string> &tree)
{
	IoHandler ioh;

	string inputData = ioh.inputMsg("추가할 문자열을 입력하세요 : ");
	if (tree.getSize() < inputData.size())
	{
		tree.setSize(inputData.length());
	}

	if (!tree.addNode(inputData))
	{
		ioh.putMsg("중복된 데이터입력!");
	}
}

void Taskmanager::deleteNode(Tree<string> &tree)
{
	IoHandler ioh;

	string inputData = ioh.inputMsg("삭제할 문자열을 입력하세요 : ");

	if (!tree.deleteNode(inputData))
	{
		ioh.putMsg("없는 문자열입니다");
	}
}

void Taskmanager::printTree(Tree<string> &tree)
{
	tree.printTree(tree.getRoot(), 1);
}