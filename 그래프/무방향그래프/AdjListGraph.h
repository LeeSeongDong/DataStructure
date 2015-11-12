#ifndef __ADJLISTGRAPH_H__
#define __ADJLISTGRAPH_H__

#include "AdjListNode.h"

class AdjListGraph
{
	friend class DirectedAdjListGraph;
private :
	AdjListNode** adjList;
	int numOfVertex;

public :
	AdjListGraph()
	{
		numOfVertex = 0;
	}
	~AdjListGraph();
	void setAdjListGraph(int num);
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

	//bool isExistVertex(int v) const;
	bool isExistEdge(int u, int v) const;

	//bool insertVertex(int v);
	bool insertEdge(int u, int v);

	//bool deleteVertex(int v);
	//bool deleteEdge(int u, int v);

	AdjListNode** getGraph() const;
	AdjListNode* getLink(const AdjListNode* adjListNode) const;
	int getData(const AdjListNode* adjListNode) const;

	void deleteGraph();
};

#endif
