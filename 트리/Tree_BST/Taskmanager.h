#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :

public :
	Taskmanager() {};
	~Taskmanager() {};

	void makeTree(Tree<string> &tree);		//트리만들기
	void runProgram(Tree<string> &tree);	
	void addNode(Tree<string> &tree);		//노드 추가
	void deleteNode(Tree<string> &tree);	//노드 삭제
	void printTree(Tree<string> &tree);		//트리 출력

};

#endif