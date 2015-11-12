#include "Taskmanager.h"

void Taskmanager::run(UndirectedGraph &ug, AdjMatrixGraph &am, AdjListGraph &al, WeightedUndirectedGraph &wug, WeightedAdjMatrixGraph &wam, DirectedGraph &dg, DirectedAdjListGraph &dl)
{
	IoHandler ioh;


	ioh.putMsg("프로그램을 선택하세요 ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit]) :");

	char menu = ioh.inputChar();

	switch (menu)
	{
	case 's':
	case 'S':
	{
		runSearchPrg(ug, am, al);

		break;
	}
	case 'm':
	case 'M':
	{
		runMSTPrg(wug, wam);

		break;
	}
	case 't':
	case 'T':
	{
		runTopologicalSort(dg, dl);

		break;
	}
	case 'q':
	case 'Q':
	{
		return;
	}
	default:
		break;
	}
}

void Taskmanager::runSearchPrg(UndirectedGraph &ug, AdjMatrixGraph &am, AdjListGraph &al)
{
	ug.makeUndirectedGraph(am, al);

	if (!am.getGraph() || !al.getGraph())
	{
		return;
	}

	ug.printAdjMatrix(am);
	ug.AdjMatrixBFS(am);
	ug.AdjMatrixDFS(am);

	ug.printAdjList(al);
	ug.AdjListBFS(al);
	ug.AdjListDFS(al);
}

void Taskmanager::runMSTPrg(WeightedUndirectedGraph &wug, WeightedAdjMatrixGraph &wam)
{
	wug.makeWeightedAdjMatrix(wam);

	if (!wam.getGraph())
	{
		return;
	}

	wug.kruskal(wam);
}

void Taskmanager::runTopologicalSort(DirectedGraph &dg, DirectedAdjListGraph &dl)
{
	dg.makeDirectedGraph(dl);

	if (!dl.getGraph())
	{
		return;
	}

	dg.topologicalSort(dl);
}