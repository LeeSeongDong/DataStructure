#include "Taskmanager.h"

void main()
{
	Taskmanager tm;

	Polynomial a;
	Polynomial b;
	Polynomial result;

	tm.setPolynomial("ù��° ���׽��� ��� - ���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)", a);
	tm.setPolynomial("�ι�° ���׽��� ��� - ���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)", b);

	tm.multPolynomial(a, b, result);

	tm.printResult("�� ���׽��� ���� : ", result);

	return ;
}