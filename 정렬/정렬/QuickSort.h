#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "Header.h"

template <class T>
void quickSort(T* a, const int numOfData)
{
	quickSort(a, 0, numOfData - 1);
}

template <class T>
void medianOfThreeQuickSort(T *a, const int numOfData)
{
	medianOfThreeQuickSort(a, 0, numOfData - 1);
}

template <class T>
void quickSort(T *a, const int left, const int right)
{
	if (left < right)
	{
		int i = left;
		int j = right + 1;
		T pivot = a[left];

		do 
		{
			do i++; while (a[i] < pivot && i < right);
			do j--; while (a[j] > pivot && j > left);
			if (i < j) swap(a[i], a[j]);
		}while (i < j);

		swap(a[left], a[j]);

		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

template <class T>
void medianOfThreeQuickSort(T *a, const int left, const int right)
{
	if (left < right)
	{
		int i = left;
		int j = right + 1;
		int pivotIndex = left;

		if (a[left] > a[right])
			pivotIndex = right;

		if (a[pivotIndex] > a[(right + left) / 2])
			pivotIndex = (right + left) / 2;

		swap(a[left], a[pivotIndex]);

		T pivot = a[left];

		do
		{
			do i++; while (a[i] < pivot && i < right);
			do j--; while (a[j] > pivot && j > left);
			if (i < j) swap(a[i], a[j]);
		} while (i < j);

		swap(a[left], a[j]);

		medianOfThreeQuickSort(a, left, j - 1);
		medianOfThreeQuickSort(a, j + 1, right);
	}
}

template <class T>
void iterativeMedianOfThreeQuickSort(T *a, const int numOfData)
{
	stack<int> s;

	int left = 0;
	int right = numOfData - 1;

	s.push(left); s.push(right);

	while (!s.empty())
	{
		right = s.top(); s.pop();
		left = s.top(); s.pop();

		if (left < right)
		{
			int i = left;
			int j = right + 1;
			int pivotIndex = left;

			if (a[left] > a[right])
				pivotIndex = right;

			if (a[pivotIndex] > a[(right + left) / 2])
				pivotIndex = (right + left) / 2;

			swap(a[left], a[pivotIndex]);

			T pivot = a[left];

			do {

				do i++;
				while (a[i] < pivot);

				do j--;
				while (a[j] > pivot);

				if (i < j) swap(a[i], a[j]);

			} while (i<j);

			swap(a[left], a[j]);

			s.push(j + 1); s.push(right);
			s.push(left); s.push(j - 1);

		}
	}
}

#endif
