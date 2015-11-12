#include "Chain.h"

//학번순 삽입
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);
	bool flag = false;			//list를 한바퀴 돌았을때 true

	currentSetFirst();

	if (!first)
	{
		first = node;
		node->right = first;
		node->left = first;
	}
	else
	{
		while (!flag)
		{
			//current의 왼쪽에 삽입
			if (currentPtr->data.getStdNum() > node->data.getStdNum())
			{
				break;
			}

			//currentPtr이 링크를 한바퀴 돌았을때
			if (currentPtr->right == first)
			{
				flag = true;
			}

			currentSetRight();
		}

		//flag = true : first 왼쪽에 삽입, false : current 왼쪽에 삽입

		node->left = currentPtr->left;
		node->right = currentPtr;
		currentPtr->left = node;
		node->left->right = node;

		if (!flag && currentPtr == first)
		{
			first = node;
		}
	}
}

//stdNum과 일치하는 학생정보 삭제
//없을시 예외처리
void Chain::deleteNode(int stdNum)
{
	bool flag = false;			//list를 한바퀴 돌았을때 true
	bool findFlag = false;		//일치하는 학생찾으면 true
	string error = "일치하는 학생정보가 없습니다.";

	currentSetFirst();

	if (!first)
	{
		throw error;
	}
	else
	{
		while (!flag)
		{
			if (stdNum == currentPtr->data.getStdNum())
			{
				findFlag = true;
				break;
			}

			if (currentPtr->right == first)
			{
				flag = true;
			}

			currentSetRight();
		}

		if (findFlag)
		{
			currentPtr->left->right = currentPtr->right;
			currentPtr->right->left = currentPtr->left;

			//first가 삭제될경우
			if (currentPtr == first)
			{
				//모든 노드가 삭제될 경우
				if (first->right == first)
				{
					first = NULL;
				}
				else
				{
					first = currentPtr->right;
				}
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

//current를 current->right로
void Chain::currentSetRight()
{
	if (first == NULL)
	{
		string error = "학생정보가 없습니다.";
		throw error;
	}
	else
	{
		currentPtr = currentPtr->right;
	}
}

//current를 current->left로
void Chain::currentSetLeft()
{
	if (first == NULL)
	{
		string error = "학생정보가 없습니다.";
		throw error;
	}
	else
	{
		currentPtr = currentPtr->left;
	}
}

//체인의 메모리 해제
//소멸자에서 호출
void Chain::deleteChain()
{

	while (first && first->right != first)
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
	if (first == NULL)
	{
		string error = "학생정보가 없습니다.";
		throw error;
	}
	else
	{
		return currentPtr->data;
	}
}