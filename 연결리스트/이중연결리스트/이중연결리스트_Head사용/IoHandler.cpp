#include "IoHandler.h"

void IoHandler::loadStdList(Chain &stdList, string stdFile)
{
	ifstream input;
	input.open(stdFile);

	if (input.fail())
	{
		cout << "학생 파일을 찾지 못했습니다.";
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
	cout << "(1) 새 학생 입력" << endl;
	cout << "(2) 학생 삭제" << endl;
	cout << "(3) 학번 순으로 전체 출력" << endl;
	cout << "(4) 학번 역순으로 전체 출력" << endl;
	cout << "(5) 특정 학번부터 전체 출력" << endl;
	cout << "(6) 특정 학번부터 첫학생까지 역순 출력" << endl;
	cout << "(7) 종료" << endl;
	cout << "== == == == == == == == == == == == == == == == == == == == ==" << endl;

	cout << "원하는 기능을 선택하세요 : ";

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