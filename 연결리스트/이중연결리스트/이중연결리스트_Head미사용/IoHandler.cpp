#include "IoHandler.h"

void IoHandler::loadStdList(Chain &stdList, string stdFile)
{
	ifstream input;
	input.open(stdFile);

	if (input.fail())
	{
		cout << "�л� ������ ã�� ���߽��ϴ�.";
		return;
	}

	string loadStdNum;
	string loadStdName;
	int stdNum;

	while (!input.eof())
	{
		input >> loadStdNum >> loadStdName;

		stdNum = atoi(loadStdNum.c_str());

		Student std(stdNum, loadStdName);

		stdList.insertNode(std);
	}

	input.close();
}


void IoHandler::putMsg(string msg)
{
	cout << msg;
}

void IoHandler::putNewLine()
{
	cout << endl;
}


string IoHandler::inputMsg(string msg)
{
	string inputMsg;

	cout << msg;
	cin >> inputMsg;

	return inputMsg;
}

int IoHandler::inputFunction()
{
	cout << "== == == == == == == == == == == == == == == == == == == == ==" << endl;
	cout << "(1) �� �л� �Է�" << endl;
	cout << "(2) �л� ����" << endl;
	cout << "(3) �й� ������ ��ü ���" << endl;
	cout << "(4) �й� �������� ��ü ���" << endl;
	cout << "(5) Ư�� �й����� ��ü ���" << endl;
	cout << "(6) Ư�� �й����� ù�л����� ���� ���" << endl;
	cout << "(7) ����" << endl;
	cout << "== == == == == == == == == == == == == == == == == == == == ==" << endl;

	cout << "���ϴ� ����� �����ϼ��� : ";

	int num;

	cin >> num;

	return num;
}

int IoHandler::inputNum(string msg)
{
	int num;
	cout << msg;
	cin >> num;
	return num;
}

Student IoHandler::inputStd(string msg)
{
	int stdNum;
	string stdName;

	cout << msg;
	cin >> stdNum;
	cin >> stdName;

	Student std(stdNum, stdName);
	return std;
}

void IoHandler::printStd(Student &std)
{
	cout << std.getStdNum() << " " << std.getStdName() << endl;
}