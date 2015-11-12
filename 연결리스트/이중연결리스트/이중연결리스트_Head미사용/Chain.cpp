#include "Chain.h"

//�й��� ����
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);
	bool flag = false;			//list�� �ѹ��� �������� true

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
			//current�� ���ʿ� ����
			if (currentPtr->data.getStdNum() > node->data.getStdNum())
			{
				break;
			}

			//currentPtr�� ��ũ�� �ѹ��� ��������
			if (currentPtr->right == first)
			{
				flag = true;
			}

			currentSetRight();
		}

		//flag = true : first ���ʿ� ����, false : current ���ʿ� ����

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

//stdNum�� ��ġ�ϴ� �л����� ����
//������ ����ó��
void Chain::deleteNode(int stdNum)
{
	bool flag = false;			//list�� �ѹ��� �������� true
	bool findFlag = false;		//��ġ�ϴ� �л�ã���� true
	string error = "��ġ�ϴ� �л������� �����ϴ�.";

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

			//first�� �����ɰ��
			if (currentPtr == first)
			{
				//��� ��尡 ������ ���
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

//current�� first��
void Chain::currentSetFirst()
{
	currentPtr = first;
}

//current�� current->right��
void Chain::currentSetRight()
{
	if (first == NULL)
	{
		string error = "�л������� �����ϴ�.";
		throw error;
	}
	else
	{
		currentPtr = currentPtr->right;
	}
}

//current�� current->left��
void Chain::currentSetLeft()
{
	if (first == NULL)
	{
		string error = "�л������� �����ϴ�.";
		throw error;
	}
	else
	{
		currentPtr = currentPtr->left;
	}
}

//ü���� �޸� ����
//�Ҹ��ڿ��� ȣ��
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
		string error = "�л������� �����ϴ�.";
		throw error;
	}
	else
	{
		return currentPtr->data;
	}
}