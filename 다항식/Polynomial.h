#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "Term.h"

using namespace std;

class Polynomial
{
private :
	Term *termArr;			//����� 0�� �ƴ� ���� �迭
	int capacity;
	int terms;				//����� 0�� �ƴ� ���� ����

public :
	Polynomial()
	{
		capacity = 4;
		terms = 0;
		termArr = new Term[capacity];
	};
	~Polynomial()
	{
		delete[]termArr;
	};

	int getTerms()
	{
		return terms;
	}
	int getCapacity()
	{
		return capacity;
	}

	Term getTermArr(int i)
	{
		return termArr[i];
	}

	void setTerm(Term term, int i)
	{
		termArr[i] = term;
	}

	void newTerm(const float theCoef, const int theExp);

	void clearPolynomial();

	void copyPolynomial(Polynomial &a);

};

#endif