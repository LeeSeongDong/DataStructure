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
인접행렬에 대한 표현 사용.

알고리즘이 간선에 대해 접근이 잦기 때문에
인접리스트보다 인접행렬에 대한 표현이 더 좋다고 판단.
*/