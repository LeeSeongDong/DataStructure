#include "Taskmanager.h"

//파일 불러오기
void Taskmanager::loadStdList(Chain &stdList, string stdFile)
{
	IoHandler ioh;

	ioh.loadStdList(stdList, stdFile);
}

//stdList에 std삽입
void Taskmanager::insertStd(Chain &stdList, Student &std)
{
	stdList.insertNode(std);
}

//stdList에서 stdNum와 일치하는 std 삭제
void Taskmanager::deleteStd(Chain &stdList, int stdNum)
{
	stdList.deleteNode(stdNum);
}

//stdList의 학생정보 모두 출력
void Taskmanager::printStdList(Chain &stdList)
{
	IoHandler ioh;
	
	stdList.currentSetFirst();
	
	if (!stdList.getCurrent())
	{
		ioh.putMsg("학생정보가 없습니다.");
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

//기능을선택하여 그 기능 수행
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
				insertStd(stdList, ioh.inputStd("학번과 이름을 입력하세요 : "));
				break;
			}
			case DELETE:
			{
				deleteStd(stdList, ioh.inputNum("학번을 입력하세요 : "));
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
				ioh.putMsg("잘못된 기능입니다.");
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