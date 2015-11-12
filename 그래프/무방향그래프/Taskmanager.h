#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "UndirectedGraph.h"
#include "WeightedUndirectedGraph.h"
#include "DirectedGraph.h"

class Taskmanager
{
private :
	//������׷���
	void runSearchPrg(UndirectedGraph &ug, AdjMatrixGraph &am, AdjListGraph &al);
	//����Ʈ��
	void runMSTPrg(WeightedUndirectedGraph &wug, WeightedAdjMatrixGraph &wam);
	//����׷���
	void runTopologicalSort(DirectedGraph &dg, DirectedAdjListGraph &dl);

public :
	Taskmanager() {};
	~Taskmanager() {};


	void run(UndirectedGraph &ug, AdjMatrixGraph &am, AdjListGraph &al, WeightedUndirectedGraph &wug, WeightedAdjMatrixGraph &wam, DirectedGraph &dg, DirectedAdjListGraph &dl);


};

#endif
