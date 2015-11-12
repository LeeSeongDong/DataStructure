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
		string inputData = ioh.inputMsg("계산식을 입력하세요 (종료는 quit) : ");

		if (inputData == "quit")
		{
			ioh.putMsg("****종료합니다****");
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

			ioh.printResult("---- 결과는 ", result);	
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