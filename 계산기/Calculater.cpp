#include "Calculater.h"

//연산식 계산
int Calculater::calculateExp(Expression const &exp)
{
	Stack temp;		//숫자를 임시 저장

	for (int i = 0; i < exp.getNumOfTerms(); ++i)
	{
		if (exp.getExp(i).type == NUMBER)
		{
			temp.push(exp.getExp(i));
		}
		else
		{
			int tempResult;

			if (exp.checkOrderOpr(exp.getExp(i).token.opr) == UNARY_ORDER)	//단항연산자
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

//이항연산자
int Calculater::calculateOpr(int a, int b, char opr)
{
	string divideError = "[오류] 나누기의 두번째 피연산자가 0";

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
			string error = "[오류] 지수가 음수";
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
		string error = "[오류] 알수없는 연산자";
		throw error;
	}
	}

}

//단항연산자
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
		string error = "[오류] 알수없는 연산자";
		throw error;
	}
	}
}

void Calculater::printExp(Expression const &exp)
{
	IoHandler ioh;

	ioh.putMsg("--- 후위 계산식은 : ");
	ioh.printExp(exp);
	ioh.putNewLine();
}