#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "IoHandler.h"

class Calculator
{
private :

public :
	Calculator() {};
	~Calculator() {};

	int calculateExp(Tree<Term> &tree);					//��������� ���
	int calculateOpr(Node<Term>* node, Tree<Term> &tree);
	int calculateOpr(int a, int b, Node<Term>* node);	//������ ���
	void printExp(Expression const &exp);				//��������� ���
	void printExpTree(Tree<Term> &tree);
};

#endif
