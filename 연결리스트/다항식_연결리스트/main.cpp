#include "Taskmanager.h"

void main()
{
	Taskmanager tm;

	PolynomialChain a;
	PolynomialChain b;
	PolynomialChain result;

	tm.setPolynomial("첫번째 다항식을 계수 - 지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)", a);
	tm.setPolynomial("두번째 다항식을 계수 - 지수 쌍으로 입력하세요.(지수가 0으로 입력되면 종료)", b);

	tm.multPolynomial(a, b, result);

	tm.printResult("두 다항식의 곱은 : ", result);

	return ;
}