#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "IoHandler.h"

class Calculator
{
private :

public :
	Calculator() {};
	~Calculator() {};

	int calculateExp(Tree<Term> &tree);					//후위연산식 계산
	int calculateOpr(Node<Term>* node, Tree<Term> &tree);
	int calculateOpr(int a, int b, Node<Term>* node);	//연산자 계산
	void printExp(Expression const &exp);				//후위연산식 출력
	void printExpTree(Tree<Term> &tree);
};

#endif
