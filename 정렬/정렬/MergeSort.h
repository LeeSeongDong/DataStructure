#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#pragma warning(disable:4996)

#include "Header.h"

int min(int a, int b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <class T>
void merge(T* a, T* mergedList, const int left, const int mid, const int right)
{
	int i, j, k;
	i = left;
	k = left;
	j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
		{
			mergedList[k] = a[i];
			k++;
			i++;
		}
		else
		{
			mergedList[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		mergedList[k] = a[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		mergedList[k] = a[j];
		k++;
		j++;
	}

	for (i = left; i < k; i++)
	{
		a[i] = mergedList[i];
	}
}

template <class T>
void recursiveMergeSort(T *a, const int n)
{
	T* mergedList = new T[n];

	recursiveMergeSort(a, mergedList, 0, n - 1);

	delete[]mergedList;
}

template <class T>
void recursiveMergeSort(T *a, T* mergedList, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		recursiveMergeSort(a, mergedList, left, mid);
		recursiveMergeSort(a, mergedList, mid + 1, right);
		merge(a, mergedList, left, mid, right);
	}

	return;
}

template <class T>
void iterativeMergeSort(T* a, const int n)
{
	T* mergedList = new T[n];

	int i, j;
	int left, mid, right;
	
	for (i = 1; i <= n; i *= 2)
	{
		for (j = 0; j + i < n; j += (2 * i))
		{
			left = j;
			mid = j + i - 1;
			right = min(j + 2*i - 1, n-1);
			merge(a, mergedList, left, mid, right);
		}
	}

	if (n % (i / 2) != 0)
	{
		merge(a, mergedList, 0, ((n - 1) - (n % (i / 2))), n - 1);
	}

	delete[]mergedList;
}

template <class T>
void naturalMergeSort(T* a, const int n)
{
	queue<int> listLength;

	int length = 1;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			listLength.push(length);
			length = 0;
		}

		length++;

		if (i == n - 2)
		{
			listLength.push(length);
		}
	}

	T* mergedList = new T[n];
	int index = 0;

	while (listLength.size() != 1)
	{
		int j = listLength.front();
		listLength.pop();

		if (index + j == n)
		{
			listLength.push(j);
			index = 0;
			continue;
		}

		int k = listLength.front();
		listLength.pop();

		merge(a, mergedList, index, index + j - 1, index + j + k - 1);

		index = index + j + k;

		listLength.push(j + k);

		if (index == n)
		{
			index = 0;
		}
	}
	delete[] mergedList;
}

#endif
