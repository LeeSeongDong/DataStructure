#include "Taskmanager.h"

void main()
{
	Taskmanager tm;

	PolynomialChain a;
	PolynomialChain b;
	PolynomialChain result;

	tm.setPolynomial("ù��° ���׽��� ��� - ���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)", a);
	tm.setPolynomial("�ι�° ���׽��� ��� - ���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)", b);

	tm.multPolynomial(a, b, result);

	tm.printResult("�� ���׽��� ���� : ", result);

	return ;
}