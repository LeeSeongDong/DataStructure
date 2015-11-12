#include "Chain.h"

//학번순 삽입
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);
	bool flag = false;	//사이에 끼워넣을때 true, 마지막에 삽입될때 false

	if (!first)
	{
		first = node;
	}
	else
	{
		currentSetFirst();

		while (currentPtr)
		{		
			if (currentPtr->data.getStdNum() > node->data.getStdNum())
			{
				flag = true;
				break;
			}
			currentSetNext();
		}

		if (!flag)
		{
			prePtr->link = node;
		}
		else
		{
			node->link = currentPtr;

			if (currentPtr == first)
			{
				first = node;
			}
			else
			{
				prePtr->link = node;
			}
		}
	}
}

//stdNum과 일치하는 학생정보 삭제
//없을시 예외처리
void Chain::deleteNode(int stdNum)
{
	bool flag = false;		//일치하는 학생찾으면 true
	string error = "일치하는 학생정보가 없습니다.";

	if (!first)
	{
		throw error;
	}
	else
	{
		currentSetFirst();

		while (currentPtr)
		{
			if (stdNum == currentPtr->data.getStdNum())
			{
				flag = true;
				break;
			}

			currentSetNext();
		}

		if (flag)
		{
			if (currentPtr == first)
			{
				first = currentPtr->link;
			}
			else
			{
				prePtr->link = currentPtr->link;
			}

			delete currentPtr;
		}
		else
		{
			throw error;
		}
	}
}

//current를 first로
void Chain::currentSetFirst()
{
	currentPtr = first;
}

//current를 current->link로
void Chain::currentSetNext()
{
	prePtr = currentPtr;
	currentPtr = currentPtr->link;
}

//체인의 메모리 해제
//소멸자에서 호출
void Chain::deleteChain()
{
	while (first)
	{
		currentSetFirst();

		first = first->link;
		delete currentPtr;
	}
}

ChainNode* Chain::getCurrentLink() const
{
	return currentPtr->link;
}

Student Chain::getCurrentData() const
{
	return currentPtr->data;
}