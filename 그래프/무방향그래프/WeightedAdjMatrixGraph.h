#ifndef __WEIGHTEDADJMATRIXGRAPH_H__
#define __WEIGHTEDADJMATRIXGRAPH_H__

#include "Header.h"

class WeightedAdjMatrixGraph
{
private:
	int numOfVertex;
	int numOfEdge;

	int **vertex;

public:
	WeightedAdjMatrixGraph()
	{
		numOfEdge = 0;
		numOfVertex = 0;
	}
	WeightedAdjMatrixGraph(int num);
	~WeightedAdjMatrixGraph();

	void setWeightedAdjMatrixGraph(int num);
	bool isEmpty() const
	{
		if (numOfVertex == 0)
		{
			return true;
		}
		else
		{
			false;
		}
	}

	int getNumOfVertex() const
	{
		return numOfVertex;
	}
	int getNumOfEdge() const
	{
		return numOfEdge;
	}

	//bool isExistVertex(int v) const;
	bool isExistEdge(int u, int v) const;

	//bool insertVertex(int v);
	bool insertEdge(int u, int v, int weight);

	//bool deleteVertex(int v);
	bool deleteEdge(int u, int v);

	int** getGraph() const;

	void deleteGraph();
};

#endif


/*
������Ŀ� ���� ǥ�� ���.

�˰����� ������ ���� ������ ��� ������
��������Ʈ���� ������Ŀ� ���� ǥ���� �� ���ٰ� �Ǵ�.
*/