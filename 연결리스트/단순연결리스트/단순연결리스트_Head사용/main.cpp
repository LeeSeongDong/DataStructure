#include "Taskmanager.h"

int main()
{
	Taskmanager tm;
	IoHandler ioh;
	Chain stdList;

	tm.loadStdList(stdList, ioh.inputMsg("�л��� �̸��� �й��� ����� ������ �Է��ϼ��� : "));

	tm.printMenu(stdList);

	return 0;
}