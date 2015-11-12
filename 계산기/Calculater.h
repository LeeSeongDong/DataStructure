#ifndef __CALCULATER_H__
#define __CALCULATER_H__

#include "IoHandler.h"

class Calculater
{
private :

public :
	Calculater() {};
	~Calculater() {};

	int calculateExp(Expression const &exp);		//��������� ���
	int calculateOpr(int a, int b, char opr);		//������ ���
	int calculateOpr(int a, char opr);				//���׿����� ���
	void printExp(Expression const &exp);			//��������� ���
};

#endif
