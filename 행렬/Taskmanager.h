#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IoHandler.h"

class Taskmanager
{
private :
	Matrix temp;

	void setMatrix(Matrix &mtr, int rowSize, int colSize, string msg);

public :
	Taskmanager() {};
	~Taskmanager() {};


	void inputMatrixSize(Matrix &mtr1, Matrix &mtr2, string msg);

	void transposeMatrix(Matrix &mtr, Matrix &result);						//빠른전치
	void multMatrix(Matrix &mtr1, Matrix &mtr2, Matrix &result);			//곱
	void printMatrix(string msg, Matrix &result);							//결과행렬출력
};

#endif