#ifndef __DIRECTEDGRAPH_H__
#define __DIRECTEDGRAPH_H__

#include "DirectedAdjListGraph.h"

class DirectedGraph
{
private :

public :
	DirectedGraph() {};
	~DirectedGraph() {};

	void makeDirectedGraph(DirectedAdjListGraph &dl);
	void topologicalSort(DirectedAdjListGraph &dl) const;

};

#endif
