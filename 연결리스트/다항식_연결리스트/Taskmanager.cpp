#include "Taskmanager.h"

void Taskmanager::addPolynomial(PolynomialChain &a, PolynomialChain &b, PolynomialChain &result)
{
	result.deleteChain();
	a.currentSetFirst();
	b.currentSetFirst();

	//a, b�� �ϳ��� ����Ʈ�� �������� ���� break
	while (!a.getCurrent() && !b.getCurrent())
	{
		if (a.getCurrentData().exp == b.getCurrentData().exp)		//a�� b�� ������ ���� ���� ���
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
		else if (a.getCurrentData().exp < b.getCurrentData().exp)	//a�� b�� ������ �ٸ� ���� ���(b�� ������ Ŭ ��)
		{
			result.insertNode(b.getCurrentData());
			b.currentSetNext();
		}
		else														//								(a�� ������ Ŭ ��)
		{
			result.insertNode(a.getCurrentData());
			a.currentSetNext();
		}
	}

	while (a.getCurrent())							//a�� ���� ���� ���Ѵ�
	{
		result.insertNode(a.getCurrentData());
		a.currentSetNext();
	}

	while (b.getCurrent())							//b�� ���� ���� ���Ѵ�.
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

		//b�� ������׽��� 0�� �ƴҶ��� ����
		if (b.getFirstLink())
		{
			temp1.copyChain(result);

			//temp1 : ������ result��, temp2 : a���װ� b��ü�� ������ ����� ���׽�
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