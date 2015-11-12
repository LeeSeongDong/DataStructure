#include "Polynomial.h"

void Polynomial::newTerm(const float theCoef, const int theExp)		//항을 추가할 때
{
	if (terms == capacity)
	{
		int beforeCapacity = capacity;
		capacity *= 2;

		Term *temp = new Term[capacity];
		for (int i = 0; i < beforeCapacity; ++i)
		{
			temp[i] = termArr[i];
		}

		delete[]termArr;

		termArr = temp;
	}

	termArr[terms].coef = theCoef;
	termArr[terms].exp = theExp;

	++terms;
}

void Polynomial::clearPolynomial()
{
	Term *temp = new Term[capacity];

	delete[]termArr;

	termArr = temp;

	terms = 0;
}

void Polynomial::copyPolynomial(Polynomial &a)
{
	capacity = a.getCapacity();
	terms = a.getTerms();

	Term *temp = new Term[capacity];


	for (int i = 0; i < a.getTerms(); ++i)
	{
		temp[i] = a.getTermArr(i);
	}

	delete[]termArr;

	termArr = temp;

}