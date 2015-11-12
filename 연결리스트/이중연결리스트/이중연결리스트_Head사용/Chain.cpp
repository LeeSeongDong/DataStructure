#include "Chain.h"

//�й��� ����
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);

	currentSetFirst();
	currentSetRight();

	while (currentPtr != first)
	{
		//current�� ���ʿ� ����
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

//stdNum�� ��ġ�ϴ� �л����� ����
//������ ����ó��
void Chain::deleteNode(int stdNum)
{
	bool findFlag = false;		//��ġ�ϴ� �л�ã���� true
	string error = "��ġ�ϴ� �л������� �����ϴ�.";

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

//current�� first��
void Chain::currentSetFirst()
{
	currentPtr = first;
}

//current�� current->right��
void Chain::currentSetRight()
{
	currentPtr = currentPtr->right;
}

//current�� current->left��
void Chain::currentSetLeft()
{
	currentPtr = currentPtr->left;
}

//ü���� �޸� ����
//�Ҹ��ڿ��� ȣ��
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
		string error = "�л������� �����ϴ�.";
		throw error;
	}
	else
	{
		return currentPtr->data;
	}
}