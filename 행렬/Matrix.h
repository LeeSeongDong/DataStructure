#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "Term.h"

class Matrix
{
private :
	Term *termArr;
	int capacity;

	int terms;			//0아닌 항의 개수
	int rowSize;		//행크기
	int colSize;		//열크기

	int tableSize;



public :
	Matrix()
	{
		terms = 0;
		capacity = 4;
		termArr = new Term[capacity];
	};
	~Matrix()
	{
		delete[]termArr;
	};

	int getTerms()
	{
		return terms;
	}
	int getRowSize()
	{
		return rowSize;
	}
	int getColSize()
	{
		return colSize;
	}
	int getTableSize()
	{
		return tableSize;
	}

	Term getTermByOrder(int inputOrder);		//order : 0인 항을 포함한 순서
	Term getTermByIndex(int inputIndex)			//index : 0인 항을 제외한 순서
	{
		return termArr[inputIndex];
	}


	void setMatrixSize(int inputRowSize, int inputColSize)
	{
		rowSize = inputRowSize;
		colSize = inputColSize;
	}
	void setTableSize();

	void newTerm(int order, int value);
	void setTerm(int index, Term term);

	void setTerms(int inputTerms);

	void clearMatrix();
};

#endif