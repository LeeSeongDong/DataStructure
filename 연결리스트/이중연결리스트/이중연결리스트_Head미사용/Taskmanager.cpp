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

//stdNum�� ��ġ�ϴ� �л������� �ּ� ��ȯ
ChainNode* Taskmanager::findStd(Chain &stdList, int stdNum)
{
	stdList.currentSetFirst();

	while (true)
	{
		if (stdList.getCurrentData().getStdNum() == stdNum)
		{
			return stdList.getCurrent();
		}

		stdList.currentSetRight();

		if (stdList.getCurrent() == stdList.getFirst())
		{
			string error = "��ġ�ϴ� �л������� �����ϴ�.";
			throw error;
		}
	}
}

//stdList�� �л����� ��ü ���
void Taskmanager::printStdList(Chain &stdList)
{
	IoHandler ioh;

	bool flag = false; //list�� �ѹ��� ������ �� true
	
	stdList.currentSetFirst();

	while (!flag)
	{
		ioh.printStd(stdList.getCurrentData());
		stdList.currentSetRight();

		if (stdList.getCurrent() == stdList.getFirst())
		{
			flag = true;
		}
	}
}

//stdList�� �л����� ��ü ���� ���
void Taskmanager::printStdListReverse(Chain &stdList)				
{
	IoHandler ioh;

	bool flag = false; //list�� �ѹ��� ������ �� true

	stdList.currentSetFirst();

	while (!flag)
	{
		stdList.currentSetLeft();
		ioh.printStd(stdList.getCurrentData());

		if (stdList.getCurrent() == stdList.getFirst())
		{
			flag = true;
		}
	}
}

//stdList�� Ư���л����� ��ü ���
void Taskmanager::printStdList(Chain &stdList, int stdNum)			
{
	IoHandler ioh;

	bool flag = false; //list�� �ѹ��� ������ �� true

	ChainNode* start = findStd(stdList, stdNum);

	while (!flag)
	{
		ioh.printStd(stdList.getCurrentData());
		stdList.currentSetRight();

		if (stdList.getCurrent() == start)
		{
			flag = true;
		}
	}
}

//stdList�� Ư���л����� ó������ ���
void Taskmanager::printStdListReverse(Chain &stdList, int stdNum)	
{
	IoHandler ioh;

	bool flag = false; //list�� �ѹ��� ������ �� true

	findStd(stdList, stdNum);
	stdList.currentSetRight();

	while (!flag)
	{
		stdList.currentSetLeft();
		ioh.printStd(stdList.getCurrentData());

		if (stdList.getCurrent() == stdList.getFirst())
		{
			flag = true;
		}
	}
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
			case PRINT_REVERSE:
			{
				printStdListReverse(stdList);
				break;
			}
			case PRINT_START_SPECIFIC_PART:
			{
				printStdList(stdList, ioh.inputNum("�й��� �Է��ϼ��� : "));
				break;
			}
			case PRINT_START_SPECIFIC_PART_REVERSE:
			{
				printStdListReverse(stdList, ioh.inputNum("�й��� �Է��ϼ��� : "));
				break;
			}
			case EXIT:
			{
				return;
			}
			default:
			{
				ioh.putMsg("�߸��� ����Դϴ�.");
				ioh.putNewLine();
				break;
			}
			}
		}
		catch (string error)
		{
			ioh.putMsg(error);
			ioh.putNewLine();
		}

		ioh.putNewLine();
	}
}