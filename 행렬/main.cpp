#include "Taskmanager.h"

int main()
{
	Taskmanager tm;
	IoHandler ioh;

	Matrix a;
	Matrix b;
	Matrix result;

	tm.inputMatrixSize(a, b, "���� �迭�� m x n �� n x p ũ���� ��, m�� n�� p�� ���� ������� �Է��ϼ��� : ");

	tm.printMatrix("ù��° �迭 : ", a);
	tm.printMatrix("�ι�° �迭 : ", b);

	tm.multMatrix(a, b, result);

	tm.printMatrix("���� �����", result);

	return 0;
}