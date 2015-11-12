#ifndef __MAKEDATA_H__
#define __MAKEDATA_H__

#pragma warning(disable:4996)

#include "Rectangle.h"

void makeData(int* a, int numOfData)
{
	//a = new int[numOfData];

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		a[i] = rand();
	}
}

void makeData(double* a, int numOfData)
{
	//a = new double[numOfData];

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		a[i] = (double)rand() * 1000 / rand();
	}
}

void makeData(string* a, int numOfData)
{
	//a = new string[numOfData];

	const char c[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
		, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
		, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		int length = rand() % 20;
		for (int j = 0; j < length; ++j)
		{
			a[i] += c[rand() % 62];
		}
	}
}

void makeData(Rectangle* a, int numOfData)
{
	//a = new Rectangle[numOfData];
	double h, w;

	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfData; ++i)
	{
		h = (double)rand() * 1000 / rand();
		w = (double)rand() * 1000 / rand();

		Rectangle r(h, w);
		a[i] = r;
	}
}

#endif
