#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include "Chain.h"

class IoHandler
{
public :
	IoHandler() {};
	~IoHandler() {};

	void loadStdList(Chain &stdList, string stdFile);

	void putMsg(string msg);
	void putNewLine();
	
	string inputMsg(string msg);
	int inputFunction();
	int inputNum(string msg);
	Student inputStd(string msg);

	void printStd(Student &std);
};

#endif
