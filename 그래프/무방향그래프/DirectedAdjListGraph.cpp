#include "DirectedAdjListGraph.h"
/*
bool DirectedAdjListGraph::isExistEdge(int u, int v) const
{
	AdjListNode* iterator = adjList[v];
	while (iterator)
	{
		if (iterator->data == u)
		{
			return true;
		}
		iterator = iterator->link;
	}

	return false;
}

*/

bool DirectedAdjListGraph::insertEdge(int u, int v)
{
	if (isExistEdge(u, v))
	{
		return false;
	}
	else
	{
		AdjListNode* edge = new AdjListNode(u);
		edge->link = adjList[v]->link;
		adjList[v]->link = edge;

		return true;
	}
}
/*
void DirectedAdjListGraph::setDirectedAdjListGraph(int num)
{
	numOfVertex = num;
	adjList = new AdjListNode*[num];

	for (int i = 0; i < num; ++i)
	{
		adjList[i] = new AdjListNode(i);
	}
}

void DirectedAdjListGraph::deleteGraph()
{
	AdjListNode* iterator;

	for (int i = 0; i < numOfVertex; ++i)
	{
		while (adjList[i])
		{
			iterator = adjList[i]->link;
			delete adjList[i];
			adjList[i] = iterator;
		}
	}

	delete[]adjList;
}

AdjListNode** DirectedAdjListGraph::getGraph() const
{
	return adjList;
}
*/