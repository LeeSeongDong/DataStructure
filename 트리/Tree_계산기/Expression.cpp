#include "Expression.h"

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
			while (inputData.at(i) >= '0' && inputData.at(i) <= '9' || inputData.at(i) ==' ')
			{
				if (inputData.at(i) == ' ')
				{
					++i;
					if (i == inputData.size())
					{
						break;
					}
					else
					{
						continue;
					}
				}
				else
				{
					strNum += inputData.at(i);
					++i;
					if (i == inputData.size())
					{
						break;
					}
				}
			}
			
			term.token.num = atoi(strNum.c_str());
			term.type = NUMBER;
			strNum = "";

			++numCount;
			--i;
		}

		else //������
		{
			if (inputData.at(i) == ' ')
			{
				continue;
			}
			if (inputData.at(i) == '-')	//���׿��� üũ
			{
				//������ - || ������ū�� ')'�� �ƴ� �������϶�
				if (i == 0 || (exp[numOfTerms-1].type == OPER && exp[numOfTerms-1].token.opr != ')' ))
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
	stack<Term> tempStack;							//�����ڸ� �ӽ÷� �����صδ� stack
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
				while (tempStack.top().token.opr != '(')			//���°�ȣ�� ���������� pop
				{
					tempExp[tempExpIndex] = tempStack.top();
					tempStack.pop();
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

			if (tempStack.size() != 0)
				{
					//stack�� ������ ������ ������(���׿����� ����)
					while (checkOrderOpr(exp[i].token.opr) >= checkOrderOpr(tempStack.top().token.opr) && checkOrderOpr(exp[i].token.opr) != UNARY_ORDER)
					{
						tempExp[tempExpIndex] = tempStack.top();
						tempStack.pop();
						++tempExpIndex;
						
						if (tempStack.size() == 0)
						{
							break;
						}
					}
				}
				tempStack.push(exp[i]);
			}
		}
	}

	//stack���ִ� ������ �����ڵ� ����
	while (tempStack.size() != 0)
	{
		if (tempStack.top().token.opr == '(')
		{
			tempStack.pop();
		}
		tempExp[tempExpIndex] = tempStack.top();
		tempStack.pop();
		++tempExpIndex;
	}

	delete[]exp;
	exp = tempExp;
	numOfTerms = tempExpIndex;
}

void Expression::setExpressionTree(Tree<Term> &tree)
{
	stack<Node<Term>*> s;
	tree.deleteTree(tree.getHead());

	for (int i = 0; i < numOfTerms; ++i)
	{
		Node<Term>* node = new Node<Term>(exp[i]);
		Node<Term>* newNode;

		if (exp[i].type == NUMBER)	//����
		{
			s.push(node);
		}
		else						//������
		{
			if (checkOrderOpr(exp[i].token.opr) == UNARY_ORDER)	//���׿�����
			{
				newNode = tree.makeTemrsToNode(s.top(), node);
				s.pop();
			}
			else
			{
				Node<Term>* right = s.top();
				s.pop();

				Node<Term>* left = s.top();
				s.pop();

				newNode = tree.makeTermsToNode(left, right, node);
			}

			s.push(newNode);
		}
	}
}

int Expression::getNumOfTerms() const
{
	return numOfTerms;
}

Term Expression::getExp(int index) const
{
	return exp[index];
}