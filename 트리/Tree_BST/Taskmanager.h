#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :

public :
	Taskmanager() {};
	~Taskmanager() {};

	void makeTree(Tree<string> &tree);		//Ʈ�������
	void runProgram(Tree<string> &tree);	
	void addNode(Tree<string> &tree);		//��� �߰�
	void deleteNode(Tree<string> &tree);	//��� ����
	void printTree(Tree<string> &tree);		//Ʈ�� ���

};

#endif