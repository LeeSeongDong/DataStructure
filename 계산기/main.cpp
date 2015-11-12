#include "Calculater.h"

int main()
{
	Expression exp;
	Calculater cal;
	IoHandler ioh;

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
			exp.setExp(inputData);			//throw �߸��� �Է�, ��ȣ
			exp.changePostfix();			//throw ������ �� ���� ����

			cal.printExp(exp);

			ioh.printResult("---- ����� ", cal.calculateExp(exp));		//throw ������ �ǿ����ڰ� 0, ������ ������ ����
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