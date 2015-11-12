#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <iostream>
#include <string>
#include <iomanip>

#include "Matrix.h"

using namespace std;

class IoHandler
{
public :
	IoHandler() {};
	~IoHandler() {};

	int inputNumber()
	{
		int number;

		cin >> number;
		return number;
	}

	void putMsg(string msg)
	{
		cout << msg;
	}
	void putInt(int number)
	{
		cout << number;
	}
	void putNewline()
	{
		cout << endl;
	}

	void printMatrix(Matrix &mtr);
};

#endif