#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include "Node.h"
#include <iomanip>

class IoHandler
{
public :
	IoHandler() {};
	~IoHandler() {};

	void putMsg(string msg);
	void putNum(int num);
	void putNewline();

	int inputNum(string msg);

	template <class T>
	void printNode(T data)
	{
		cout << setw(3) << data;
	}

	void printBranch()
	{
		cout << " ---";
	}

	void printTab(int depth)
	{
		cout << endl << "   " ;

		for (int i = 0; i < depth-1; ++i)
		{
			cout << "       ";
		}
	}

};

#endif