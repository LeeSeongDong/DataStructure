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

//������ �켱����
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
		return -1;	//�����ڰ� �ƴѰ��
	}
}


//�Է¹��� �ϳ��� stringŸ���� inputData�� ���ں��� ���� ������
//�����ϰ�� char���� ��� �ϳ��� int�� ����
//exp[]�� ����
void Expression::setExp(string inputData)
{
	clearExp();

	Term term;
	string strNum = "";
	int bracketCount = 0;			//��ȣ�� ����� �Ǿ�����(��ȣ ���� �ջ�)

	int oprCount = 0;				//������ ����� �Ǿ�����(�����ڿ� �ǿ����� ���� Ȯ��)
	int numCount = 0;				//���׿����ڿ� ��ȣ�� count���� ����


	for (int i = 0; i < inputData.size(); ++i)
	{
		if (inputData.at(i) >= '0' && inputData.at(i) <= '9')	//����
		{
			strNum += inputData.at(i);

			//���� ������ ���� or �����ϰ�� �ϳ��Ǽ��ڷ� �ν�
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
		else //�����ڵ�
		{
			if (inputData.at(i) == ' ')	//����ó��
			{
				continue;
			}
			else if (inputData.at(i) == '-')	//���׿��� üũ
			{
				//������ - || ������ū�� ')'�� �ƴ� �������϶�
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
			else		//������
			{
				if (checkOrderOpr(inputData.at(i)) == -1)	//�߸��� �Է�(�����ڰ� �ƴ�)
				{
					string error = "[����] �߸��� �Է�";
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
		string error = "[����] �ϼ��� ���� �ƴմϴ�.";
		throw error;
	}
	else if (bracketCount != 0)
	{
		string error = "[����] ��ȣ�� �ϼ����� �ʾҽ��ϴ�.";
		throw error;
	}
}

//����ǥ������� �� ���� ����ǥ��� �ٲ۴�
void Expression::changePostfix()
{
	Stack tempStack;							//�����ڸ� �ӽ÷� �����صδ� stack
	Term *tempExp = new Term[numOfTerms];		//������������ �ٲ� ��
	int tempExpIndex = 0;

	for (int i = 0; i < numOfTerms; ++i)
	{
		if (exp[i].type == NUMBER)		//�����϶�
		{
			//�����϶� exp�� ����
			tempExp[tempExpIndex] = exp[i];
			++tempExpIndex;
		}

		else
		{
			//opr�϶� exp�� opr ����
			//������ �켱���� ����
			//stack�� push or pop

			if (exp[i].token.opr == '(')	//stack�� �������� ���� ��������
			{
				tempStack.push(exp[i]);
			}
			else if (exp[i].token.opr == ')')
			{
				while (tempStack.getTop().token.opr != '(')			//���°�ȣ�� ���������� pop
				{
					tempExp[tempExpIndex] = tempStack.pop();
					++tempExpIndex;
				}
				tempStack.pop();			//'('
			}
			else
			{
				//���� token�� ��ȣ�� �ƴ� �������϶� ����
				if (i != 0 && exp[i-1].type == OPER && exp[i-1].token.opr != '(' && exp[i-1].token.opr != ')')
				{
					if (checkOrderOpr(exp[i].token.opr) != UNARY_ORDER)
					{
						string error = "[����] ������ �� ���� ����";
						throw error;
					}
				}

				if (tempStack.getNumOfVal() != 0)
				{
					//stack�� ������ ������ ������(���׿����� ����)
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

	//stack���ִ� ������ �����ڵ� ����
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