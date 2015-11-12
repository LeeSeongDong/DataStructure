#include "IoHandler.h"

//연산식 입력
string IoHandler::inputMsg(string msg)
{
	cout << msg;
	
	string data;
	getline(cin, data, '\n');

	return data;
}

//연산식 출력
void IoHandler::printExp(Expression const &exp)
{
	for (int i = 0; i < exp.getNumOfTerms(); ++i)
	{
		if (exp.getExp(i).type == NUMBER)		//숫자일때
		{
			cout << exp.getExp(i).token.num << " ";
		}
		else
		{
			cout << exp.getExp(i).token.opr << " ";
		}
	}
}

//계산한 결과 출력
void IoHandler::printResult(string msg, int result)
{
	cout << msg << result << endl;
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