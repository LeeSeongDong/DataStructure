#include "Calculator.h"

//연산식 계산
int Calculator::calculateExp(Tree<Term> &tree)
{
	return calculateOpr(tree.getRoot(), tree);
}

int Calculator::calculateOpr(Node<Term>* node, Tree<Term> &tree)
{
	Expression ex;

	if (node->data.type == NUMBER)
	{
		return node->data.token.num;
	}
	else
	{
		int a;
		int b;

		a = calculateOpr(node->left, tree);
		if (ex.checkOrderOpr(node->data.token.opr) != UNARY_ORDER)
		{
			b = calculateOpr(node->right, tree);
		}

		int result;
		
		string divideError = "[오류] 나누기의 두번째 피연산자가 0";

		switch (node->data.token.opr)
		{
		case '^':
		{
			if (b == 0)
			{
				result = 1;
			}
			else if (b < 0)
			{
				string error = "[오류] 지수가 음수";
				throw error;
			}
			else
			{
				result = 1;
				for (int i = 0; i < b; ++i)
				{
					result *= a;
				}
			}

			break;
		}
		case '*':
		{
			result = a * b;
			break;
		}
		case '/':
		{
			if (b == 0)
			{
				throw divideError;
			}
			result = a / b;
			break;
		}
		case '%':
		{
			if (b == 0)
			{
				throw divideError;
			}
			result = a % b;
			break;
		}
		case '+':
		{
			result = a + b;
			break;
		}
		case '-':
		{
			result = a - b;
			break;
		}
		case '~':
		{
			result = 0 - a;
			break;
		}
		default:
		{
			string error = "[오류] 알수없는 연산자";
			throw error;
			break;
		}
		}

		string resultStr;
		resultStr = to_string(result);

		node->data.result = node->data.token.opr;
		node->data.result += "(";
		node->data.result += resultStr;
		node->data.result += ")";

		if (tree.getSize() < node->data.result.size())
		{
			tree.setSize(node->data.result.size());
		}

		return result;
	}
}

void Calculator::printExp(Expression const &exp)
{
	IoHandler ioh;

	ioh.putMsg("--- 후위 계산식은 : ");
	ioh.printExp(exp);
	ioh.putNewLine();
	ioh.putNewLine();
}

void Calculator::printExpTree(Tree<Term> &tree)
{
	IoHandler ioh;

	tree.printTree(tree.getRoot(), 1);

	ioh.putNewLine();
}