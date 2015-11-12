#include "Calculater.h"

//����� ���
int Calculater::calculateExp(Expression const &exp)
{
	Stack temp;		//���ڸ� �ӽ� ����

	for (int i = 0; i < exp.getNumOfTerms(); ++i)
	{
		if (exp.getExp(i).type == NUMBER)
		{
			temp.push(exp.getExp(i));
		}
		else
		{
			int tempResult;

			if (exp.checkOrderOpr(exp.getExp(i).token.opr) == UNARY_ORDER)	//���׿�����
			{
				tempResult = calculateOpr(temp.pop().token.num, exp.getExp(i).token.opr);
			}
			else
			{
				tempResult = calculateOpr(temp.pop().token.num, temp.pop().token.num, exp.getExp(i).token.opr);
			}
			
			Term tempTerm;
			tempTerm.token.num = tempResult;

			temp.push(tempTerm);
		}
	}

	return temp.pop().token.num;
}

//���׿�����
int Calculater::calculateOpr(int a, int b, char opr)
{
	string divideError = "[����] �������� �ι�° �ǿ����ڰ� 0";

	switch (opr)
	{
	case '^' :
	{
		if (b == 0)
		{
			return 1;
		}
		else if (b < 0)
		{
			string error = "[����] ������ ����";
			throw error;
		}
		else
		{
			int result = 1;
			for (int i = 0; i < b; ++i)
			{
				result *= a;
			}

			return result;
		}
	}
	case '*':
	{
		return a * b;
	}
	case '/':
	{
		if (b == 0)
		{
			throw divideError;
		}
		return a / b;				
	}
	case '%':
	{
		if (b == 0)
		{
			throw divideError;
		}
		return a % b;				
	}
	case '+':
	{
		return a + b;
	}
	case '-':
	{
		return a - b;
	}
	default:
	{
		string error = "[����] �˼����� ������";
		throw error;
	}
	}

}

//���׿�����
int Calculater::calculateOpr(int a, char opr)
{
	switch (opr)
	{
	case '~':
	{
		return 0 - a;
	}
	default:
	{
		string error = "[����] �˼����� ������";
		throw error;
	}
	}
}

void Calculater::printExp(Expression const &exp)
{
	IoHandler ioh;

	ioh.putMsg("--- ���� ������ : ");
	ioh.printExp(exp);
	ioh.putNewLine();
}