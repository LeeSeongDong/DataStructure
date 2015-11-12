#include "IoHandler.h"

//연산식 입력
string IoHandler::inputMsg(string msg)
{
	cout << msg;

	string data;
	cin >> data;;

	return data;
}

int IoHandler::inputNum(string msg)
{
	cout << msg;

	int inputNum;
	cin >> inputNum;

	return inputNum;
}

void IoHandler::printBranch()
{
	cout << " --- ";
}

void IoHandler::printTab(int depth, int nodeSize)
{
	cout << endl;

	for (int j = 0; j < nodeSize; ++j)
	{
		cout << " ";
	}

	for (int i = 0; i < depth-1; ++i)
	{
		for (int j = 0; j < nodeSize; ++j)
		{
			cout << " ";
		}
		cout << "     ";
	}
}