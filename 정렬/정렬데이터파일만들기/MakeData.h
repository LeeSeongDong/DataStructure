#ifndef __MAKEDATA_H__
#define __MAKEDATA_H__

#pragma warning(disable:4996)

#include "Header.h"

void fileOut(int* a, string fileName, int numOfData)
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
		outputFile << a[i] ;
		if (i != numOfData - 1)
		{
			outputFile << endl;
		}
	}

	outputFile.close();
}

void fileOut(double* a, string fileName, int numOfData)
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

void fileOut(string* a, string fileName, int numOfData)
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
		outputFile << a[i].c_str() ;
		if (i != numOfData - 1)
		{
			outputFile << endl;
		}
	}

	outputFile.close();
}

void makeIntRand(int numOfData, string fileName)
{
	int* a = new int[numOfData];

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		a[i] = rand();
	}

	fileOut(a, fileName, numOfData);

	delete[]a;
}

void makeDoubleRand(int numOfData, string fileName)
{
	double* a = new double[numOfData];

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		a[i] = (double)rand()*1000 / rand();
	}

	fileOut(a, fileName, numOfData);

	delete[]a;
}

void makeCharRand(int numOfData, string fileName)
{
	string* a = new string[numOfData];

	const char c[] = {'0','1','2','3','4','5','6','7','8','9'
		,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
		,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		int length = rand()%20;
		for (int j = 0; j < length; ++j)
		{
			a[i] += c[rand() % 62];
		}
	}

	fileOut(a, fileName, numOfData);

	delete[]a;
}

#endif
