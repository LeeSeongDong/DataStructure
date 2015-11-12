#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "Term.h"

class Matrix
{
private :
	Term *termArr;
	int capacity;

	int terms;			//0�ƴ� ���� ����
	int rowSize;		//��ũ��
	int colSize;		//��ũ��

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

	Term getTermByOrder(int inputOrder);		//order : 0�� ���� ������ ����
	Term getTermByIndex(int inputIndex)			//index : 0�� ���� ������ ����
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