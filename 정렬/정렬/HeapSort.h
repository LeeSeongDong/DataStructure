#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#include "Header.h"


template <class T>
void adjust(T* a, const int root, const int n)	//maxHeap
{
	T e = a[root];
	int j;

	for (j = 2 * root + 1; j <= n; j = j * 2 + 1)
	{
		if (j < n-1 && a[j] < a[j + 1])
			j++;
		if (e >= a[j])
			break;
		a[(j - 1) / 2] = a[j];
	}

	a[(j - 1) / 2] = e;
}

template <class T>
void heapSort(T* a, const int n)
{
	int i;

	for (i = n / 2 - 1; i >= 0; i--)
		adjust(a, i, n);

	for (i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		adjust(a, 0, i-1);
	}
}

#endif
