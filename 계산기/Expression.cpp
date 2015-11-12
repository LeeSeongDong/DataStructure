#include "Expression.h"
#include <iostream>

bool Expression::isFull() const
{
	if (numOfTerms == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Expression::doubleCapacity()
{
	Term *temp;

	temp = new Term[capacity * 2];

	for (int i = 0; i < capacity; ++i)
	{
		temp[i] = exp[i];
	}

	delete[]exp;

	exp = temp;

	capacity *= 2;
}

void Expression::insert(Term term)
{
	if (isFull())
	{
		doubleCapacity();
	}

	exp[numOfTerms] = term;

	++numOfTerms;
}

void Expression::clearExp()
{
	capacity = 4;
	numOfTerms = 0;
	Term *temp = new Term[capacity];

	delete[]exp;

	exp = temp;	
}

//연산자 우선순위
int Expression::checkOrderOpr(char opr) const
{
	if (opr == ')')
	{
		return 0;
	}
	else if (opr == '~')
	{
		return 1;
	}
	else if (opr == '^')
	{
		return 2;
	}
	else if (opr == '*' || opr == '/' || opr == '%')
	{
		return 3;
	}
	else if (opr == '+' || opr == '-')
	{
		return 4;
	}
	else if (opr == '(')
	{
		return 5;
	}
	else
	{
		return -1;	//연산자가 아닌경우
	}
}


//입력받은 하나의 string타입의 inputData를 문자별로 각각 나눈다
//숫자일경우 char들을 모아 하나의 int로 만듬
//exp[]에 저장
void Expression::setExp(string inputData)
{
	clearExp();

	Term term;
	string strNum = "";
	int bracketCount = 0;			//괄호가 제대로 되었는지(괄호 개수 합산)

	int oprCount = 0;				//연산이 제대로 되었는지(연산자와 피연산자 개수 확인)
	int numCount = 0;				//단항연산자와 괄호는 count에서 제외


	for (int i = 0; i < inputData.size(); ++i)
	{
		if (inputData.at(i) >= '0' && inputData.at(i) <= '9')	//숫자
		{
			strNum += inputData.at(i);

			//숫자 다음에 숫자 or 공백일경우 하나의숫자로 인식
			if (i < inputData.size()-1 && (inputData.at(i + 1) >= '0' && inputData.at(i + 1) <= '9' || inputData.at(i+1) == ' '))
			{
				continue;
			}
			else
			{
				term.token.num = atoi(strNum.c_str());
				term.type = NUMBER;
				strNum = "";

				++numCount;
			}
			
		}
		else //연산자들
		{
			if (inputData.at(i) == ' ')	//공백처리
			{
				continue;
			}
			else if (inputData.at(i) == '-')	//단항연산 체크
			{
				//시작이 - || 이전토큰이 ')'가 아닌 연산자일때
				if (i == 0 || ( !(inputData.at(i - 1) >= '0' && inputData.at(i - 1) <= '9') && inputData.at(i-1) != ')') )
				{
					term.token.opr = '~';
					--oprCount;
				}
				else
				{
					term.token.opr = inputData.at(i);
				}
			}
			else		//연산자
			{
				if (checkOrderOpr(inputData.at(i)) == -1)	//잘못된 입력(연산자가 아님)
				{
					string error = "[오류] 잘못된 입력";
					throw error;
				}

				term.token.opr = inputData.at(i);

				if (term.token.opr == '(')
				{
					++bracketCount;
					--oprCount;
				}
				else if (term.token.opr == ')')
				{
					--bracketCount;
					--oprCount;
				}
			}

			term.type = OPER;
			++oprCount;
		}

		insert(term);
	}

	if ( (numCount - oprCount) != 1)
	{
		string error = "[오류] 완성된 식이 아닙니다.";
		throw error;
	}
	else if (bracketCount != 0)
	{
		string error = "[오류] 괄호가 완성되지 않았습니다.";
		throw error;
	}
}

//중위표기식으로 된 식을 후위표기로 바꾼다
void Expression::changePostfix()
{
	Stack tempStack;							//연산자만 임시로 저장해두는 stack
	Term *tempExp = new Term[numOfTerms];		//후위연산으로 바꾼 식
	int tempExpIndex = 0;

	for (int i = 0; i < numOfTerms; ++i)
	{
		if (exp[i].type == NUMBER)		//숫자일때
		{
			//숫자일때 exp에 저장
			tempExp[tempExpIndex] = exp[i];
			++tempExpIndex;
		}

		else
		{
			//opr일때 exp에 opr 저장
			//연산자 우선순위 적용
			//stack에 push or pop

			if (exp[i].token.opr == '(')	//stack에 넣을때는 가장 높은순위
			{
				tempStack.push(exp[i]);
			}
			else if (exp[i].token.opr == ')')
			{
				while (tempStack.getTop().token.opr != '(')			//여는괄호를 만날때까지 pop
				{
					tempExp[tempExpIndex] = tempStack.pop();
					++tempExpIndex;
				}
				tempStack.pop();			//'('
			}
			else
			{
				//이전 token이 괄호가 아닌 연산자일때 오류
				if (i != 0 && exp[i-1].type == OPER && exp[i-1].token.opr != '(' && exp[i-1].token.opr != ')')
				{
					if (checkOrderOpr(exp[i].token.opr) != UNARY_ORDER)
					{
						string error = "[오류] 이해할 수 없는 수식";
						throw error;
					}
				}

				if (tempStack.getNumOfVal() != 0)
				{
					//stack의 연산자 순위가 빠를때(단항연산자 제외)
					while (checkOrderOpr(exp[i].token.opr) >= checkOrderOpr(tempStack.getTop().token.opr) && checkOrderOpr(exp[i].token.opr) != UNARY_ORDER)
					{
						if (tempStack.getNumOfVal() == 0)
						{
							break;
						}
						tempExp[tempExpIndex] = tempStack.pop();
						++tempExpIndex;
					}
				}
				tempStack.push(exp[i]);
			}
		}
	}

	//stack에있는 나머지 연산자들 저장
	while (tempStack.getNumOfVal() != 0)
	{
		if (tempStack.getTop().token.opr == '(')
		{
			tempStack.pop();
		}
		tempExp[tempExpIndex] = tempStack.pop();
		++tempExpIndex;
	}

	delete[]exp;
	exp = tempExp;
	numOfTerms = tempExpIndex;
}

int Expression::getNumOfTerms() const
{
	return numOfTerms;
}

Term Expression::getExp(int index) const
{
	return exp[index];
}