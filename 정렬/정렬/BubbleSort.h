#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#include "Header.h"

template <class T>
void bubbleSort(T* a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

#endif
