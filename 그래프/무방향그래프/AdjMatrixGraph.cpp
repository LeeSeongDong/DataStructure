#include "AdjMatrixGraph.h"

AdjMatrixGraph::AdjMatrixGraph(int num)
{
	setAdjMatrixGraph(num);
}

AdjMatrixGraph::~AdjMatrixGraph()
{
	deleteGraph();
}

void AdjMatrixGraph::setAdjMatrixGraph(int num)
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

int AdjMatrixGraph::getDegree(int v) const
{
	int degree = 0;

	for (int i = 0; i < numOfVertex; ++i)
	{
		degree += vertex[v][i];
	}

	return degree;
}


bool AdjMatrixGraph::isExistEdge(int u, int v) const
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

bool AdjMatrixGraph::insertEdge(int u, int v)
{
	if (isExistEdge(u, v))
	{
		return false;
	}
	else
	{
		vertex[u][v] = 1;
		vertex[v][u] = 1;
		++numOfEdge;

		return true;
	}
}

bool AdjMatrixGraph::deleteEdge(int u, int v)
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

int** AdjMatrixGraph::getGraph() const
{
	return vertex;
}

void AdjMatrixGraph::deleteGraph()
{
	for (int i = 0; i < numOfVertex; ++i)
	{
		delete[] vertex[i];
	}

	delete[]vertex;
}