#include "Chain.h"

//학번순 삽입
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);

	currentSetFirst();
	currentSetRight();

	while (currentPtr != first)
	{
		//current의 왼쪽에 삽입
		if (currentPtr->data.getStdNum() > node->data.getStdNum())
		{
			break;
		}

		currentSetRight();
	}

	node->left = currentPtr->left;
	node->right = currentPtr;
	currentPtr->left = node;
	node->left->right = node;
}

//stdNum과 일치하는 학생정보 삭제
//없을시 예외처리
void Chain::deleteNode(int stdNum)
{
	bool findFlag = false;		//일치하는 학생찾으면 true
	string error = "일치하는 학생정보가 없습니다.";

	currentSetFirst();
	currentSetRight();

		while (currentPtr != first)
		{
			if (stdNum == currentPtr->data.getStdNum())
			{
				findFlag = true;
				break;
			}

			currentSetRight();
		}

		if (findFlag)
		{
			currentPtr->left->right = currentPtr->right;
			currentPtr->right->left = currentPtr->left;

			delete currentPtr;
		}
		else
		{
			throw error;
		}
}

//current를 first로
void Chain::currentSetFirst()
{
	currentPtr = first;
}

//current를 current->right로
void Chain::currentSetRight()
{
	currentPtr = currentPtr->right;
}

//current를 current->left로
void Chain::currentSetLeft()
{
	currentPtr = currentPtr->left;
}

//체인의 메모리 해제
//소멸자에서 호출
void Chain::deleteChain()
{
	while (first->right != first)
	{
		currentSetFirst();
		first = currentPtr->right;

		currentPtr->left->right = currentPtr->right;
		currentPtr->right->left = currentPtr->left;
		delete currentPtr;
	}

	delete first;
}

Student Chain::getCurrentData() const
{
	if (first->right == first)
	{
		string error = "학생정보가 없습니다.";
		throw error;
	}
	else
	{
		return currentPtr->data;
	}
}