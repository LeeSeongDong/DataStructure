#ifndef __ADJMATRIXGRAPH_H__
#define __ADJMATRIXGRAPH_H__

#include "Header.h"

class AdjMatrixGraph
{
private :
	int numOfVertex;
	int numOfEdge;

	int **vertex;

public :
	AdjMatrixGraph()
	{
		numOfEdge = 0;
		numOfVertex = 0;
	}
	AdjMatrixGraph(int num);
	~AdjMatrixGraph();

	void setAdjMatrixGraph(int num);
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

	int getDegree(int v) const;

	//bool isExistVertex(int v) const;
	bool isExistEdge(int u, int v) const ;

	//bool insertVertex(int v);
	bool insertEdge(int u, int v);

	//bool deleteVertex(int v);
	bool deleteEdge(int u, int v);

	int** getGraph() const;
	void deleteGraph();
};

#endif
