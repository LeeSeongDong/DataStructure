#include "Taskmanager.h"

void Taskmanager::addPolynomial(Polynomial &a, Polynomial &b, Polynomial &result)
{
	result.clearPolynomial();

	if (b.getTerms() == 1 && b.getTermArr(0).coef == 0)				//곱셈 계산시 계수가 0인항을 더할때
	{
		result.copyPolynomial(a);
		return;
	}

	int aPos = 0;
	int bPos = 0;

	while ((aPos < a.getTerms() ) && (bPos < b.getTerms() ) )
	{
		if (a.getTermArr(aPos).exp == b.getTermArr(bPos).exp)		//a와 b의 지수가 같은 항의 계산
		{

			float coef = a.getTermArr(aPos).coef + b.getTermArr(bPos).coef;

			if (coef != 0)
			{
				result.newTerm(coef, a.getTermArr(aPos).exp);
			}

			++aPos;
			++bPos;
		}
		else if (a.getTermArr(aPos).exp < b.getTermArr(bPos).exp)	//a와 b의 지수가 다른 항의 계산(b의 지수가 클 때)
		{
			result.newTerm(b.getTermArr(bPos).coef, b.getTermArr(bPos).exp);
			++bPos;
		}
		else												//								(a의 지수가 클 때)
		{
			result.newTerm(a.getTermArr(aPos).coef, a.getTermArr(aPos).exp);
			++aPos;
		}
	}

	for (; aPos < a.getTerms(); ++aPos)							//a의 남은 항을 더한다
	{
		result.newTerm(a.getTermArr(aPos).coef, a.getTermArr(aPos).exp);
	}

	for (; bPos < b.getTerms(); ++bPos)							//b의 남은 항을 더한다.
	{
		result.newTerm(b.getTermArr(bPos).coef, b.getTermArr(bPos).exp);
	}
}

void Taskmanager::multPolynomial(Polynomial &a, Polynomial &b, Polynomial &result)
{
	Term newTerm;
	result.clearPolynomial();

	for (int i = 0; i < a.getTerms(); ++i)
	{
		temp2.clearPolynomial();

		for (int j = 0; j < b.getTerms(); ++j)
		{
			newTerm.coef = a.getTermArr(i).coef * b.getTermArr(j).coef;
			newTerm.exp = a.getTermArr(i).exp + b.getTermArr(j).exp;

			temp2.newTerm(newTerm.coef, newTerm.exp);
		}

		temp1.copyPolynomial(result);

		addPolynomial(temp1, temp2, result);
	}
}

void Taskmanager::addTerm(Polynomial &a, Term term)
{
	Term temp;

	if (a.getTerms() == 0)
	{
		a.newTerm(term.coef, term.exp);
	}
	else
	{
		for (int i = 0; i < a.getTerms(); ++i)
		{
			float newCoef = a.getTermArr(i).coef + term.coef;

			temp.coef = newCoef;
			temp.exp = term.exp;

			if (a.getTermArr(i).exp == term.exp)
			{
				a.setTerm(temp, i);
			}
			else
			{
				a.newTerm(temp.coef, temp.exp);
			}
		}
	}
}


void Taskmanager::setPolynomial(string msg, Polynomial &p)
{
	IoHandler ioh;
	ioh.putMsg(msg);
	ioh.putNewLine();

	while (true)
	{
		float coef = ioh.inputCoef();
		int exp = ioh.inputExp();
		
		if (coef != 0)
		{
			p.newTerm(coef, exp);
		}

		if (exp == 0)
		{
			break;
		}
	}
}

void Taskmanager::printResult(string msg, Polynomial &result)
{
	IoHandler ioh;
	ioh.putMsg(msg);

	ioh.printPolynomial(result);
}