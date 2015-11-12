#include "Taskmanager.h"

void Taskmanager::addPolynomial(PolynomialChain &a, PolynomialChain &b, PolynomialChain &result)
{
	result.deleteChain();
	a.currentSetFirst();
	b.currentSetFirst();

	//a, b중 하나의 리스트의 마지막에 오면 break
	while (!a.getCurrent() && !b.getCurrent())
	{
		if (a.getCurrentData().exp == b.getCurrentData().exp)		//a와 b의 지수가 같은 항의 계산
		{
			float coef = a.getCurrentData().coef + b.getCurrentData().coef;

			if (coef != 0)
			{
				Term newTerm;
				newTerm.coef = coef;
				newTerm.exp = a.getCurrentData().exp;

				result.insertNode(newTerm);
			}

			a.currentSetNext();
			b.currentSetNext();
		}
		else if (a.getCurrentData().exp < b.getCurrentData().exp)	//a와 b의 지수가 다른 항의 계산(b의 지수가 클 때)
		{
			result.insertNode(b.getCurrentData());
			b.currentSetNext();
		}
		else														//								(a의 지수가 클 때)
		{
			result.insertNode(a.getCurrentData());
			a.currentSetNext();
		}
	}

	while (a.getCurrent())							//a의 남은 항을 더한다
	{
		result.insertNode(a.getCurrentData());
		a.currentSetNext();
	}

	while (b.getCurrent())							//b의 남은 항을 더한다.
	{
		result.insertNode(b.getCurrentData());
		b.currentSetNext();
	}
}

void Taskmanager::multPolynomial(PolynomialChain &a, PolynomialChain &b, PolynomialChain &result)
{
	Term newTerm;
	result.deleteChain();

	a.currentSetFirst();

	while (a.getCurrent())
	{
		temp2.deleteChain();

		b.currentSetFirst();
		while (b.getCurrent())
		{
			newTerm.coef = a.getCurrentData().coef * b.getCurrentData().coef;
			newTerm.exp = a.getCurrentData().exp + b.getCurrentData().exp;

			temp2.insertNode(newTerm);

			b.currentSetNext();
		}

		//b의 결과다항식이 0이 아닐때만 더함
		if (b.getFirstLink())
		{
			temp1.copyChain(result);

			//temp1 : 기존의 result값, temp2 : a한항과 b전체를 곱셈한 결과의 다항식
			addPolynomial(temp1, temp2, result);
		}
		a.currentSetNext();
	}
}


void Taskmanager::setPolynomial(string msg, PolynomialChain &p)
{
	IoHandler ioh;

	ioh.putMsg(msg);
	ioh.putNewLine();

	Term newTerm;

	while (true)
	{
		float coef = ioh.inputCoef();
		int exp = ioh.inputExp();
		
		newTerm.coef = coef;
		newTerm.exp = exp;

		if (coef != 0)
		{
			p.insertNode(newTerm);
		}

		if (exp == 0)
		{
			break;
		}
	}
}

void Taskmanager::printResult(string msg, PolynomialChain &result)
{
	IoHandler ioh;
	ioh.putMsg(msg);

	ioh.printPolynomial(result);
}