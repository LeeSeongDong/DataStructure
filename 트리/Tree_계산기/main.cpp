#include "Calculator.h"

int main()
{
	Expression exp;
	Calculator cal;
	Tree < Term > expTree;
	IoHandler ioh;

	int result;

	while (true)
	{
		string inputData = ioh.inputMsg("������ �Է��ϼ��� (����� quit) : ");

		if (inputData == "quit")
		{
			ioh.putMsg("****�����մϴ�****");
			break;
		}

		try
		{
			exp.setExp(inputData);
			exp.changePostfix();
			exp.setExpressionTree(expTree);

			cal.printExp(exp);

			result = cal.calculateExp(expTree);
			cal.printExpTree(expTree);

			ioh.printResult("---- ����� ", result);	
			ioh.putNewLine();
		}

		catch (string er)
		{
			ioh.putMsg(er);
			ioh.putNewLine();
		}

		ioh.putNewLine();
	}

	return 0;
}