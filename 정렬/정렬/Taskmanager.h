#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "MakeData.h"
#include "Sort.h"
#include "FileHandler.h"

class Taskmanager
{
private:

public:
	Taskmanager() {};
	~Taskmanager() {};

	template <class T>
	void copy(T* initData, T* copyData, int numOfData);

	template <class T>
	void compareTimeOfNumOfData(int numOfData, int per, int code, string fileName);

	template <class T>
	void compareTimeOfFunction(int numOfData, int code, string fileName);
};

template <class T>
void Taskmanager::copy(T* initData, T* copyData, int numOfData)
{
	for (int i = 0; i < numOfData; ++i)
	{
		copyData[i] = initData[i];
	}
}

template <class T>
void Taskmanager::compareTimeOfNumOfData(int numOfData, int per, int code, string fileName)
{
	++numOfData;

	//�ʱⰪ
	T* initData = new T[numOfData];

	//����������
	makeData(initData, numOfData);
	string arrType = "������";

	if (code == 2) //��������
	{
		sort(initData, initData + numOfData);
		arrType = "��������";
	}
	else if (code == 3) //��������
	{
		sort(initData, initData + numOfData, greater<T>());
		arrType = "��������";
	}

	//������ ������
	T* sortData = new T[numOfData];

	time_t start, end;								//����, ���� �ð�
	double sortTime;								//���Ŀ� �ɸ� �ð�
	int numOfTimeArr = 0;							//timeArr�� ����� �� ����
	int capacity = numOfData / per + 1;
	double* timeArr = new double[capacity * 2];				//<�����Ͱ���, �ɸ��ð�>���� �迭 (per������)

	//����
	for (int i = 1; i <= numOfData; i += per)
	{
		cout << i << "���� �������� ������" << endl;

		//������ ����
		copy(initData, sortData, numOfData);

		/*
		����������Ľ� ������ ü��
		Chain<T> c;
		for (int i = 0; i < numOfData; ++i)
		{
		c.insertNode(initData[i]);
		}
		*/

		start = clock();	//���� ����

		/**************************************************************************/

		//����, ����
		//bubbleSort(sortData, i);
		//selectionSort(sortData, i);

		//����
		//binaryInsertionSort(sortData, i);
		//c.insertionSort();

		//��
		//sort(sortData, sortData + i);
		//quickSort(sortData, i);
		//medianOfThreeQuickSort(sortData, i);
		//iterativeMedianOfThreeQuickSort(sortData, i);

		//��
		//heapSort(sortData, i);

		//�պ�
		//recursiveMergeSort(sortData, i);
		//iterativeMergeSort(sortData, i);
		naturalMergeSort(sortData, i);

		/**************************************************************************/

		end = clock();		// ���� ��

		sortTime = (double)(end - start) / (double)CLOCKS_PER_SEC;

		timeArr[numOfTimeArr] = i;
		++numOfTimeArr;
		timeArr[numOfTimeArr] = sortTime;
		++numOfTimeArr;
	}

	saveTimeArr(timeArr, numOfTimeArr, arrType, fileName);
}

template <class T>
void Taskmanager::compareTimeOfFunction(int numOfData, int code, string fileName)
{
	//�ʱⰪ
	T* initData = new T[numOfData];

	//����������
	makeData(initData, numOfData);
	string arrType = "������";

	if (code == 2) //��������
	{
		sort(initData, initData + numOfData);
		arrType = "��������";
	}
	else if (code == 3) //��������
	{
		sort(initData, initData + numOfData, greater<T>());
		arrType = "��������";
	}

	//������ ������
	T* sortData = new T[numOfData];
	Chain<T> c;

	time_t start, end;								//����, ���� �ð�
	double sortTime;								//���Ŀ� �ɸ� �ð�
	int numOfTimeArr = 0;							//timeArr�� ����� �� ����

	string funcArr[12];				//<�Լ��̸�>�迭
	double timeArr[12];				//<�ɸ��ð�>�迭
	for (int i = 0; i < 12; ++i)
	{
		cout << i+1 << "��° �Լ������� ������" << endl;
		string funcName = "";

		if (i == 3)//����������Ľ� ������ ü��
		{
			for (int i = 0; i < numOfData; ++i)
			{
				c.insertNode(initData[i]);
			}
		}
		else
		{
			//������ ����
			copy(initData, sortData, numOfData);
		}


		start = clock();	//���� ����

		/**************************************************************************/

		switch (i)
		{
			//����, ����
		case 0:
			bubbleSort(sortData, numOfData);
			funcName = "����";
			break;
		case 1:
			selectionSort(sortData, numOfData);
			funcName = "����";
			break;

			//����
		case 2:
			binaryInsertionSort(sortData, numOfData);
			funcName = "�̿�����";
			break;

		case 3:
			c.insertionSort();
			funcName = "�������";
			break;

			//��
		case 4:
			sort(sortData, sortData + numOfData);
			funcName = "���̺귯�� sort";
			break;

		case 5:
			quickSort(sortData, numOfData);
			funcName = "��";
			break;

		case 6:
			medianOfThreeQuickSort(sortData, numOfData);
			funcName = "MedianOfThree��";
			break;

		case 7:
			iterativeMedianOfThreeQuickSort(sortData, numOfData);
			funcName = "�ݺ� MedianOfThree��";
			break;

			//��
		case 8:
			heapSort(sortData, numOfData);
			funcName = "��";
			break;

			//�պ�
		case 9:
			recursiveMergeSort(sortData, numOfData);
			funcName = "����պ�";
			break;

		case 10:
			iterativeMergeSort(sortData, numOfData);
			funcName = "�ݺ��պ�";
			break;

		case 11:
			naturalMergeSort(sortData, numOfData);
			funcName = "�ڿ��պ�";
			break;

		default:
			break;
		}

		/**************************************************************************/

		end = clock();		// ���� ��

		sortTime = (double)(end - start) / (double)CLOCKS_PER_SEC;

		funcArr[i] = funcName;
		timeArr[i] = sortTime;

		if (i == 3)
		{
			fileOut(c, numOfData, funcName + ".txt");
		}
		else
		{
			fileOut(sortData, numOfData, funcName + ".txt");
		}
	}

	cout << "������ ������";
	saveTimeArr(timeArr, funcArr, arrType, fileName);
}

#endif
