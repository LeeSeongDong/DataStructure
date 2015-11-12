#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include "Expression.h"
#include <iostream>

class IoHandler
{
public :
	IoHandler() {};
	~IoHandler() {};

	void putMsg(string msg)
	{
		cout << msg;
	}
	void putNewLine()
	{
		cout << endl;
	}

	string inputMsg(string msg);
	void printExp(Expression const &exp);
	void printResult(string msg, int result);
};

#endif
