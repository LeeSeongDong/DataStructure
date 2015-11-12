#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <stack>
#include "Term.h"
#include "Tree.h"

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

	int checkOrderOpr(char opr) const;				//연산자 우선순위확인
	void setExp(string inputData);					//입력받은 string에서 연산자, 피연산자 구분(setExp)
	void changePostfix();							//후위연산으로 표기 Stack opr(연산자만 넣는) 이용
	void setExpressionTree(Tree<Term> &tree);		//후위표기된 수식으로 트리 만들기

	int getNumOfTerms() const;
	Term getExp(int index) const;
};

#endif
