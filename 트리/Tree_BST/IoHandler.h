#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include "Tree.h"

class IoHandler
{
public:
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
	int inputNum(string msg);

	void printBranch();
	void printTab(int depth, int nodeSize);

	template <class T>
	void printNode(T data, int nodeSize)
	{
		cout << setw(nodeSize) << data;
	}
};

#endif
