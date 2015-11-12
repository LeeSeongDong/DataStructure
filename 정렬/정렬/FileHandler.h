#ifndef __FILEHANDLER_H__
#define __FILEHANDLER_H__

#include "Rectangle.h"
#include "Chain.h"

void saveTimeArr(double* timeArr, int numOfTimeArr, string arrType, string fileName)
{
	ofstream outputFile;

	outputFile.open(fileName);

	if (outputFile.fail())
	{
		cout << "파일을 찾을수 없습니다.";
		return;
	}

	outputFile << arrType << endl;

	for (int i = 0; i < numOfTimeArr; i += 2)
	{
		outputFile << timeArr[i] << " " << timeArr[i+1] << endl;
	}

	outputFile.close();
}

void saveTimeArr(double* timeArr, string* funcArr, string arrType, string fileName)
{
	ofstream outputFile;

	outputFile.open(fileName);

	if (outputFile.fail())
	{
		cout << "파일을 찾을수 없습니다.";
		return;
	}

	outputFile << arrType << endl;

	for (int i = 0; i < 12; ++i)
	{
		outputFile << funcArr[i] << " " << timeArr[i] << endl;
	}

	outputFile.close();
}

template <class T>
void fileOut(T* a, int numOfData, string fileName)
{
	ofstream outputFile;

	outputFile.open(fileName);

	if (outputFile.fail())
	{
		cout << "파일을 찾을수 없습니다.";
		return;
	}

	for (int i = 0; i < numOfData; ++i)
	{
		outputFile << a[i];
		if (i != numOfData - 1)
		{
			outputFile << endl;
		}
	}

	outputFile.close();
}

template <class T>
void fileOut(Chain<T>& c, int numOfData, string fileName)
{
	ofstream outputFile;

	outputFile.open(fileName);

	if (outputFile.fail())
	{
		cout << "파일을 찾을수 없습니다.";
		return;
	}

	T a;
	c.setCurFirst();

	for (int i = 0; i < numOfData; ++i)
	{
		a = c.getCurData();
		outputFile << a;
		if (i != numOfData - 1)
		{
			outputFile << endl;
		}
		c.setCurNext();
	}

	outputFile.close();
}

#endif
