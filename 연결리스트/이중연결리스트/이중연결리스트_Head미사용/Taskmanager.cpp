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

//stdNum와 일치하는 학생정보의 주소 반환
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
			string error = "일치하는 학생정보가 없습니다.";
			throw error;
		}
	}
}

//stdList의 학생정보 전체 출력
void Taskmanager::printStdList(Chain &stdList)
{
	IoHandler ioh;

	bool flag = false; //list를 한바퀴 돌았을 때 true
	
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

//stdList의 학생정보 전체 역순 출력
void Taskmanager::printStdListReverse(Chain &stdList)				
{
	IoHandler ioh;

	bool flag = false; //list를 한바퀴 돌았을 때 true

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

//stdList의 특정학생부터 전체 출력
void Taskmanager::printStdList(Chain &stdList, int stdNum)			
{
	IoHandler ioh;

	bool flag = false; //list를 한바퀴 돌았을 때 true

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

//stdList의 특정학생부터 처음까지 출력
void Taskmanager::printStdListReverse(Chain &stdList, int stdNum)	
{
	IoHandler ioh;

	bool flag = false; //list를 한바퀴 돌았을 때 true

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
			case PRINT_REVERSE:
			{
				printStdListReverse(stdList);
				break;
			}
			case PRINT_START_SPECIFIC_PART:
			{
				printStdList(stdList, ioh.inputNum("학번을 입력하세요 : "));
				break;
			}
			case PRINT_START_SPECIFIC_PART_REVERSE:
			{
				printStdListReverse(stdList, ioh.inputNum("학번을 입력하세요 : "));
				break;
			}
			case EXIT:
			{
				return;
			}
			default:
			{
				ioh.putMsg("잘못된 기능입니다.");
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