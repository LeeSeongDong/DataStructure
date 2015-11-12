#include "Chain.h"

//�й��� ����
void Chain::insertNode(Student &std)
{
	ChainNode* node = new ChainNode(std);
	bool flag = false;	//���̿� ���������� true, �������� ���Եɶ� false

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

	if (flag)
	{
		node->link = currentPtr;
	}

	prePtr->link = node;
}

//stdNum�� ��ġ�ϴ� �л����� ����
//������ ����ó��
void Chain::deleteNode(int stdNum)
{
	bool flag = false;		//��ġ�ϴ� �л�ã���� true
	string error = "��ġ�ϴ� �л������� �����ϴ�.";

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
		prePtr->link = currentPtr->link;
		delete currentPtr;
	}
	else
	{
		throw error;
	}

}

//current�� first->link��
void Chain::currentSetFirst()
{
	prePtr = first;
	currentPtr = first->link;
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
	while (first->link)
	{
		currentSetFirst();

		first->link = currentPtr->link;

		delete currentPtr;
	}

	delete first;
}

ChainNode* Chain::getCurrentLink() const
{
	return currentPtr->link;
}

Student Chain::getCurrentData() const
{
	return currentPtr->data;
}