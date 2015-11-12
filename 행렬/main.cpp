#include "Taskmanager.h"

int main()
{
	Taskmanager tm;
	IoHandler ioh;

	Matrix a;
	Matrix b;
	Matrix result;

	tm.inputMatrixSize(a, b, "곱할 배열이 m x n 와 n x p 크기일 때, m과 n과 p의 값을 순서대로 입력하세요 : ");

	tm.printMatrix("첫번째 배열 : ", a);
	tm.printMatrix("두번째 배열 : ", b);

	tm.multMatrix(a, b, result);

	tm.printMatrix("곱셈 결과는", result);

	return 0;
}