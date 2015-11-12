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

	//초기값
	T* initData = new T[numOfData];

	//렌덤값생성
	makeData(initData, numOfData);
	string arrType = "랜덤값";

	if (code == 2) //오름차순
	{
		sort(initData, initData + numOfData);
		arrType = "오름차순";
	}
	else if (code == 3) //내림차순
	{
		sort(initData, initData + numOfData, greater<T>());
		arrType = "내림차순";
	}

	//정렬할 데이터
	T* sortData = new T[numOfData];

	time_t start, end;								//시작, 종료 시간
	double sortTime;								//정렬에 걸린 시간
	int numOfTimeArr = 0;							//timeArr에 저장된 값 개수
	int capacity = numOfData / per + 1;
	double* timeArr = new double[capacity * 2];				//<데이터개수, 걸린시간>쌍의 배열 (per단위씩)

	//정렬
	for (int i = 1; i <= numOfData; i += per)
	{
		cout << i << "개의 값에대해 정렬중" << endl;

		//데이터 복사
		copy(initData, sortData, numOfData);

		/*
		연결삽입정렬시 생성될 체인
		Chain<T> c;
		for (int i = 0; i < numOfData; ++i)
		{
		c.insertNode(initData[i]);
		}
		*/

		start = clock();	//정렬 시작

		/**************************************************************************/

		//버블, 선택
		//bubbleSort(sortData, i);
		//selectionSort(sortData, i);

		//삽입
		//binaryInsertionSort(sortData, i);
		//c.insertionSort();

		//퀵
		//sort(sortData, sortData + i);
		//quickSort(sortData, i);
		//medianOfThreeQuickSort(sortData, i);
		//iterativeMedianOfThreeQuickSort(sortData, i);

		//힙
		//heapSort(sortData, i);

		//합병
		//recursiveMergeSort(sortData, i);
		//iterativeMergeSort(sortData, i);
		naturalMergeSort(sortData, i);

		/**************************************************************************/

		end = clock();		// 정렬 끝

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
	//초기값
	T* initData = new T[numOfData];

	//렌덤값생성
	makeData(initData, numOfData);
	string arrType = "랜덤값";

	if (code == 2) //오름차순
	{
		sort(initData, initData + numOfData);
		arrType = "오름차순";
	}
	else if (code == 3) //내림차순
	{
		sort(initData, initData + numOfData, greater<T>());
		arrType = "내림차순";
	}

	//정렬할 데이터
	T* sortData = new T[numOfData];
	Chain<T> c;

	time_t start, end;								//시작, 종료 시간
	double sortTime;								//정렬에 걸린 시간
	int numOfTimeArr = 0;							//timeArr에 저장된 값 개수

	string funcArr[12];				//<함수이름>배열
	double timeArr[12];				//<걸린시간>배열
	for (int i = 0; i < 12; ++i)
	{
		cout << i+1 << "번째 함수에대해 정렬중" << endl;
		string funcName = "";

		if (i == 3)//연결삽입정렬시 생성될 체인
		{
			for (int i = 0; i < numOfData; ++i)
			{
				c.insertNode(initData[i]);
			}
		}
		else
		{
			//데이터 복사
			copy(initData, sortData, numOfData);
		}


		start = clock();	//정렬 시작

		/**************************************************************************/

		switch (i)
		{
			//버블, 선택
		case 0:
			bubbleSort(sortData, numOfData);
			funcName = "버블";
			break;
		case 1:
			selectionSort(sortData, numOfData);
			funcName = "선택";
			break;

			//삽입
		case 2:
			binaryInsertionSort(sortData, numOfData);
			funcName = "이원삽입";
			break;

		case 3:
			c.insertionSort();
			funcName = "연결삽입";
			break;

			//퀵
		case 4:
			sort(sortData, sortData + numOfData);
			funcName = "라이브러리 sort";
			break;

		case 5:
			quickSort(sortData, numOfData);
			funcName = "퀵";
			break;

		case 6:
			medianOfThreeQuickSort(sortData, numOfData);
			funcName = "MedianOfThree퀵";
			break;

		case 7:
			iterativeMedianOfThreeQuickSort(sortData, numOfData);
			funcName = "반복 MedianOfThree퀵";
			break;

			//힙
		case 8:
			heapSort(sortData, numOfData);
			funcName = "힙";
			break;

			//합병
		case 9:
			recursiveMergeSort(sortData, numOfData);
			funcName = "재귀합병";
			break;

		case 10:
			iterativeMergeSort(sortData, numOfData);
			funcName = "반복합병";
			break;

		case 11:
			naturalMergeSort(sortData, numOfData);
			funcName = "자연합병";
			break;

		default:
			break;
		}

		/**************************************************************************/

		end = clock();		// 정렬 끝

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

	cout << "데이터 저장중";
	saveTimeArr(timeArr, funcArr, arrType, fileName);
}

#endif
