#include "IoHandler.h"

void IoHandler::printMatrix(Matrix &mtr)
{
	int order = 0;

	for (int i = 0; i < mtr.getRowSize(); ++i)
	{
		cout << "[ ";

		for (int j = 0; j < mtr.getColSize(); ++j)
		{
			order = i * mtr.getColSize() + j;

			cout << setw(mtr.getTableSize() + 2) << mtr.getTermByOrder(order).val;
		}

		cout << " ]" << endl;
	}
}