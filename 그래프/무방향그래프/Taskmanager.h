#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "UndirectedGraph.h"
#include "WeightedUndirectedGraph.h"
#include "DirectedGraph.h"

class Taskmanager
{
private :
	//무방향그래프
	void runSearchPrg(UndirectedGraph &ug, AdjMatrixGraph &am, AdjListGraph &al);
	//신장트리
	void runMSTPrg(WeightedUndirectedGraph &wug, WeightedAdjMatrixGraph &wam);
	//방향그래프
	void runTopologicalSort(DirectedGraph &dg, DirectedAdjListGraph &dl);

public :
	Taskmanager() {};
	~Taskmanager() {};


	void run(UndirectedGraph &ug, AdjMatrixGraph &am, AdjListGraph &al, WeightedUndirectedGraph &wug, WeightedAdjMatrixGraph &wam, DirectedGraph &dg, DirectedAdjListGraph &dl);


};

#endif
