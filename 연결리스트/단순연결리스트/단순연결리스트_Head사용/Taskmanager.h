#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :
	void insertStd(Chain &stdList, Student &std);
	void deleteStd(Chain &stdList, int stdNum);
	void printStdList(Chain &stdList);

public :
	Taskmanager() {};
	~Taskmanager() {};

	void loadStdList(Chain &stdList, string stdFile);
	void printMenu(Chain &stdList);
};

#endif
