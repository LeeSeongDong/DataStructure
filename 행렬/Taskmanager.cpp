#include "Taskmanager.h"

void Taskmanager::setMatrix(Matrix &mtr, int rowSize, int colSize, string msg)
{
	IoHandler ioh;

	ioh.putMsg(msg + " �迭�� ");
	ioh.putInt(rowSize * colSize);
	ioh.putMsg("�� ���� �Է��ϼ���. : ");

	mtr.setMatrixSize(rowSize, colSize);

	for (int i = 0; i < (rowSize * colSize); ++i)
	{
		int value = ioh.inputNumber();

		if (value != 0)
		{
			mtr.newTerm(i, value);			//0�� �ƴ� �׸� ����
		}
	}
}

void Taskmanager::inputMatrixSize(Matrix &mtr1, Matrix &mtr2, string msg)
{
	IoHandler ioh;

	int m;
	int n;
	int p;

	while (true)
	{
		ioh.putMsg(msg);
		m = ioh.inputNumber();
		n = ioh.inputNumber();
		p = ioh.inputNumber();

		if (m != 0 && n != 0 && p != 0)
		{
			break;
		}
		else
		{
			ioh.putMsg("����� ũ��� 0�� �� �� �����ϴ�.");
			ioh.putNewline();
		}
	}

	setMatrix(mtr1, m, n, "ù��°");
	setMatrix(mtr2, n, p, "�ι�°");
}


void Taskmanager::transposeMatrix(Matrix &mtr, Matrix &result)
{
	result.clearMatrix();

	result.setMatrixSize(mtr.getColSize(), mtr.getRowSize());
	result.setTerms(mtr.getTerms());

	if (mtr.getTerms() > 0)
	{
		int *transposedRow = new int[mtr.getColSize()];		//��ġ�� ���� ���� ũ�� = ��ġ�Ǳ� ���� ���� ũ��

		for (int i = 0; i < mtr.getColSize(); ++i)		// transposedRow�� ���� 0���� �ʱ�ȭ
		{
			transposedRow[i] = 0;
		}

		for (int i = 0; i < mtr.getTerms(); ++i)		// transposedRow�� index�࿡ ���ԵǴ� ���� ����
		{
			++transposedRow[mtr.getTermByIndex(i).col];
		}


		int temp1;
		int temp2 = transposedRow[0];

		for (int i = 1; i < mtr.getColSize(); ++i)		//����������(index���� �������� ���� ������ �����Ѱ��� ����)
		{
			temp1 = transposedRow[i];
			transposedRow[i] = temp2;
			temp2 = temp1 + transposedRow[i];
		}
		transposedRow[0] = 0;
		
		for (int i = 0; i < mtr.getTerms(); ++i)
		{
			int j = transposedRow[mtr.getTermByIndex(i).col];		// j : ��ġ�� ����� ��, transposedRow[j] : ��ġ������� j���� ���۵Ǵ� ������

			Term term;
			term.col = mtr.getTermByIndex(i).row;
			term.row = mtr.getTermByIndex(i).col;
			term.val = mtr.getTermByIndex(i).val;
			result.setTerm(j, term);

			++transposedRow[mtr.getTermByIndex(i).col];				//�ش� ���� �������� 1�� �ø���.
		}

		delete[]transposedRow;
	}
}

void Taskmanager::multMatrix(Matrix &mtr1, Matrix &mtr2, Matrix &result)
{
	result.clearMatrix();
	result.setMatrixSize(mtr1.getRowSize(), mtr2.getColSize());

	transposeMatrix(mtr2, temp);

	for (int i = 0; i < mtr1.getRowSize(); ++i)
	{
		for (int j = 0; j < temp.getRowSize(); ++j)
		{
			int val = 0;

			for (int k = 0; k < mtr1.getColSize(); ++k)
			{
				int order1 = i * mtr1.getColSize() + k;
				int order2 = j * temp.getColSize() + k;


				val += mtr1.getTermByOrder(order1).val * temp.getTermByOrder(order2).val;
			}

			int order = i * result.getColSize() + j;

			if (val != 0)
			{
				result.newTerm(order, val);
			}
		}
	}
}

void Taskmanager::printMatrix(string msg, Matrix &result)
{
	IoHandler ioh;

	result.setTableSize();

	ioh.putMsg(msg);
	ioh.putNewline();

	ioh.printMatrix(result);
}