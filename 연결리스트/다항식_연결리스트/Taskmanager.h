#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :
	PolynomialChain temp1;
	PolynomialChain temp2;

public :
	Taskmanager() {};
	~Taskmanager() {};

	void addPolynomial(PolynomialChain &a, PolynomialChain &b, PolynomialChain &result);
	void multPolynomial(PolynomialChain &a, PolynomialChain &b, PolynomialChain &result);

	void setPolynomial(string msg, PolynomialChain &p);
	
	void printResult(string msg, PolynomialChain &result);
};

#endif