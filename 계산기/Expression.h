#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include "Stack.h"

class Expression
{
private :
	Term *exp;
	int numOfTerms;
	int capacity;

public :
	Expression()
	{
		numOfTerms = 0;
		capacity = 4;
		exp = new Term[capacity];
	};
	~Expression()
	{
		delete[]exp;
	};

	bool isFull() const;
	void doubleCapacity();
	void insert(Term term);
	void clearExp();

	int checkOrderOpr(char opr) const;				//������ �켱����Ȯ��
	void setExp(string inputData);					//�Է¹��� string���� ������, �ǿ����� ����(setExp)
	void changePostfix();							//������������ ǥ�� Stack opr(�����ڸ� �ִ�) �̿�

	int getNumOfTerms() const;
	Term getExp(int index) const;
};

#endif
