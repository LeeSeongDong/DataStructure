#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :
	void insertStd(Chain &stdList, Student &std);
	void deleteStd(Chain &stdList, int stdNum);

	ChainNode* findStd(Chain &stdList, int stdNum);							//학번과 일치하는 학생정보의 주소 반환

	void printStdList(Chain &stdList);						//전체 출력
	void printStdListReverse(Chain &stdList);				//전체 역순 출력
	void printStdList(Chain &stdList, int stdNum);			//특정학생부터 전체 출력
	void printStdListReverse(Chain &stdList, int stdNum);	//특정학생부터 처음까지 출력

public :
	Taskmanager() {};
	~Taskmanager() {};

	void loadStdList(Chain &stdList, string stdFile);
	void printMenu(Chain &stdList);
};

#endif
