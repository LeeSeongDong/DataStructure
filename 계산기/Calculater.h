#ifndef __CALCULATER_H__
#define __CALCULATER_H__

#include "IoHandler.h"

class Calculater
{
private :

public :
	Calculater() {};
	~Calculater() {};

	int calculateExp(Expression const &exp);		//후위연산식 계산
	int calculateOpr(int a, int b, char opr);		//연산자 계산
	int calculateOpr(int a, char opr);				//단항연산자 계산
	void printExp(Expression const &exp);			//후위연산식 출력
};

#endif
