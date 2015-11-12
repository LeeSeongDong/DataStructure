#include "Matrix.h"

Term Matrix::getTermByOrder(int inputOrder)
{
	for (int i = 0; i < terms; ++i)
	{
		int order = termArr[i].row * colSize + termArr[i].col;

		if (inputOrder == order)
		{
			return termArr[i];
		}
	}

	Term term;

	term.col = inputOrder % colSize;
	term.row = inputOrder / colSize;
	term.val = 0;

	return term;
}


void Matrix::setTableSize()							//배열 출력할때 간격
{
	int maximum = 0;

	for (int i = 0; i < terms; ++i)
	{
		if (termArr[i].val > maximum)
		{
			maximum = termArr[i].val;
		}
	}

	int count = 0;

	while (maximum / 10 > 0)
	{
		++count;
		maximum /= 10;
	}

	tableSize = count;
}

void Matrix::newTerm(int order, int value)		//항을 추가할 때
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

	termArr[terms].col = order % colSize;
	termArr[terms].row = order / colSize;
	termArr[terms].val = value;

	++terms;
}

void Matrix::setTerm(int index, Term term)
{
	termArr[index] = term;
}

void Matrix::setTerms(int inputTerms)
{
	terms = inputTerms;

	if (capacity <= terms)
	{
		int beforeCapacity = capacity;
		capacity = terms;

		Term *temp = new Term[capacity];
		for (int i = 0; i < beforeCapacity; ++i)
		{
			temp[i] = termArr[i];
		}

		delete[]termArr;

		termArr = temp;
	}
}

void Matrix::clearMatrix()
{
	terms = 0;
	capacity = 4;

	Term *temp = new Term[capacity];

	delete[]termArr;

	termArr = temp;
}

