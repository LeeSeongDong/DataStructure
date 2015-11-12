#ifndef __DIRECTEDADJLISTGRAPH_H__
#define __DIRECTEDADJLISTGRAPH_H__

#include "IoHandler.h"

class DirectedAdjListGraph : public AdjListGraph
{
private :


public :
	DirectedAdjListGraph() : AdjListGraph()
	{

	}
	~DirectedAdjListGraph() {}

	bool insertEdge(int u, int v);

};

#endif
