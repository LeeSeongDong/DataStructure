#include "WeightedAdjMatrixGraph.h"

WeightedAdjMatrixGraph::WeightedAdjMatrixGraph(int num)
{
	setWeightedAdjMatrixGraph(num);
}

WeightedAdjMatrixGraph::~WeightedAdjMatrixGraph()
{
	deleteGraph();
}

void WeightedAdjMatrixGraph::setWeightedAdjMatrixGraph(int num)
{
	numOfVertex = num;

	vertex = new int*[num];

	for (int i = 0; i < num; ++i)
	{
		vertex[i] = new int[num];
	}

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			vertex[i][j] = 0;
		}
	}
}

bool WeightedAdjMatrixGraph::isExistEdge(int u, int v) const
{
	if (vertex[u][v] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool WeightedAdjMatrixGraph::insertEdge(int u, int v, int weight)
{
	if (isExistEdge(u, v))
	{
		return false;
	}
	else
	{
		vertex[u][v] = weight;
		vertex[v][u] = weight;
		++numOfEdge;

		return true;
	}
}

bool WeightedAdjMatrixGraph::deleteEdge(int u, int v)
{
	if (!isExistEdge(u, v))
	{
		return false;
	}
	else
	{
		vertex[u][v] = 0;
		vertex[v][u] = 0;
		--numOfEdge;
		
		return true;
	}
}

int** WeightedAdjMatrixGraph::getGraph() const
{
	return vertex;
}

void WeightedAdjMatrixGraph::deleteGraph()
{
	for (int i = 0; i < numOfVertex; ++i)
	{
		delete[] vertex[i];
	}

	delete[]vertex;
}