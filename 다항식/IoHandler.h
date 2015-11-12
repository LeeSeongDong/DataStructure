#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <iostream>
#include <string>

#include "Polynomial.h"

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

	float inputCoef()
	{
		float coef;
		cin >> coef;

		return coef;
	}
	int inputExp()
	{
		int exp;
		cin >> exp;

		return exp;
	}

	void printPolynomial(Polynomial &p);
};

#endif