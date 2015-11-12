#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :
	void insertStd(Chain &stdList, Student &std);
	void deleteStd(Chain &stdList, int stdNum);

	ChainNode* findStd(Chain &stdList, int stdNum);							//�й��� ��ġ�ϴ� �л������� �ּ� ��ȯ

	void printStdList(Chain &stdList);						//��ü ���
	void printStdListReverse(Chain &stdList);				//��ü ���� ���
	void printStdList(Chain &stdList, int stdNum);			//Ư���л����� ��ü ���
	void printStdListReverse(Chain &stdList, int stdNum);	//Ư���л����� ó������ ���

public :
	Taskmanager() {};
	~Taskmanager() {};

	void loadStdList(Chain &stdList, string stdFile);
	void printMenu(Chain &stdList);
};

#endif
