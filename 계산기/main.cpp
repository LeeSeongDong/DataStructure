#include "Calculater.h"

int main()
{
	Expression exp;
	Calculater cal;
	IoHandler ioh;

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
			exp.setExp(inputData);			//throw 잘못된 입력, 괄호
			exp.changePostfix();			//throw 이해할 수 없는 수식

			cal.printExp(exp);

			ioh.printResult("---- 결과는 ", cal.calculateExp(exp));		//throw 나눗샘 피연산자가 0, 제곱의 지수가 음수
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