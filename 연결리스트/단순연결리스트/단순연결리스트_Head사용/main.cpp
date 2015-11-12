#include "Taskmanager.h"

int main()
{
	Taskmanager tm;
	IoHandler ioh;
	Chain stdList;

	tm.loadStdList(stdList, ioh.inputMsg("학생의 이름과 학번이 저장된 파일을 입력하세요 : "));

	tm.printMenu(stdList);

	return 0;
}