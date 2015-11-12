#include "IoHandler.h"

void IoHandler::putMsg(string msg)
{
	cout << msg;
}

void IoHandler::putNum(int num)
{
	cout << num;
}

void IoHandler::putNewline()
{
	cout << endl;
}

int IoHandler::inputNum(string msg)
{
	int num;
	cout << msg;
	cin >> num;

	return num;
}