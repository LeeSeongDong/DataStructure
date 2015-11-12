#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :
	Polynomial temp1;
	Polynomial temp2;
public :
	Taskmanager() {};
	~Taskmanager() {};

	void addPolynomial(Polynomial &a, Polynomial &b, Polynomial &result);
	void multPolynomial(Polynomial &a, Polynomial &b, Polynomial &result);
	void addTerm(Polynomial &a, Term term);

	void setPolynomial(string msg, Polynomial &p);
	
	void printResult(string msg, Polynomial &result);
};

#endif