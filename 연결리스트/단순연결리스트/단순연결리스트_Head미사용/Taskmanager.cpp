#include "Taskmanager.h"

//���� �ҷ�����
void Taskmanager::loadStdList(Chain &stdList, string stdFile)
{
	IoHandler ioh;

	ioh.loadStdList(stdList, stdFile);
}

//stdList�� std����
void Taskmanager::insertStd(Chain &stdList, Student &std)
{
	stdList.insertNode(std);
}

//stdList���� stdNum�� ��ġ�ϴ� std ����
void Taskmanager::deleteStd(Chain &stdList, int stdNum)
{
	stdList.deleteNode(stdNum);
}

//stdList�� �л����� ��� ���
void Taskmanager::printStdList(Chain &stdList)
{
	IoHandler ioh;
	
	stdList.currentSetFirst();
	
	if (!stdList.getCurrent())
	{
		ioh.putMsg("�л������� �����ϴ�.");
		ioh.putNewLine();
		return;
	}

	while (stdList.getCurrent())
	{
		ioh.printStd(stdList.getCurrentData());
		stdList.currentSetNext();
	}

	ioh.putNewLine();
}

//����������Ͽ� �� ��� ����
void Taskmanager::printMenu(Chain &stdList)
{
	IoHandler ioh;
	int menu;

	while (true)
	{
		try
		{
			menu = ioh.inputFunction();

			switch (menu)
			{
			case INSERT:
			{
				insertStd(stdList, ioh.inputStd("�й��� �̸��� �Է��ϼ��� : "));
				break;
			}
			case DELETE:
			{
				deleteStd(stdList, ioh.inputNum("�й��� �Է��ϼ��� : "));
				break;
			}
			case PRINT:
			{
				printStdList(stdList);
				break;
			}
			case EXIT:
			{
				return;
			}
			default:
			{
				ioh.putMsg("�߸��� ����Դϴ�.");
				break;
			}
			}
		}
		catch (string error)
		{
			ioh.putMsg(error);
		}

		ioh.putNewLine();
	}
}