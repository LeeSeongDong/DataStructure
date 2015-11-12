#include "Chain.h"

//�й��� ����
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);
	bool flag = false;	//���̿� ���������� true, �������� ���Եɶ� false

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

//stdNum�� ��ġ�ϴ� �л����� ����
//������ ����ó��
void Chain::deleteNode(int stdNum)
{
	bool flag = false;		//��ġ�ϴ� �л�ã���� true
	string error = "��ġ�ϴ� �л������� �����ϴ�.";

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

//current�� first��
void Chain::currentSetFirst()
{
	currentPtr = first;
}

//current�� current->link��
void Chain::currentSetNext()
{
	prePtr = currentPtr;
	currentPtr = currentPtr->link;
}

//ü���� �޸� ����
//�Ҹ��ڿ��� ȣ��
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