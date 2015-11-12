#include "AdjListGraph.h"

AdjListGraph::~AdjListGraph()
{
	deleteGraph();
}

void AdjListGraph::setAdjListGraph(int num)
{
	numOfVertex = num;
	adjList = new AdjListNode*[num];

	for (int i = 0; i < num; ++i)
	{
		adjList[i] = new AdjListNode(i);
	}
}

bool AdjListGraph::isExistEdge(int u, int v) const
{
	AdjListNode* iterator = adjList[u];
	while (iterator)
	{
		if (iterator->data == v)
		{
			return true;
		}
		iterator = iterator->link;
	}

	return false;
}

bool AdjListGraph::insertEdge(int u, int v)
{
	if (isExistEdge(u, v))
	{
		return false;
	}
	else
	{
		AdjListNode* edge1 = new AdjListNode(v);
		edge1->link = adjList[u]->link;
		adjList[u]->link = edge1;

		AdjListNode* edge2 = new AdjListNode(u);
		edge2->link = adjList[v]->link;
		adjList[v]->link = edge2;

		return true;
	}
}

AdjListNode** AdjListGraph::getGraph() const
{
	return adjList;
}

AdjListNode* AdjListGraph::getLink(const AdjListNode* adjListNode) const
{
	return adjListNode->link;
}

int AdjListGraph::getData(const AdjListNode* adjListNode) const
{
	return adjListNode->data;
}

void AdjListGraph::deleteGraph()
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