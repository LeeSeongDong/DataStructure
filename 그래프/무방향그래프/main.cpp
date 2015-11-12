#include "Taskmanager.h"

int main()
{
	AdjMatrixGraph am;
	AdjListGraph al;
	WeightedAdjMatrixGraph wam;

	Taskmanager tm;
	UndirectedGraph ug;
	WeightedUndirectedGraph wug;

	DirectedGraph dg;
	DirectedAdjListGraph dl;

	tm.run(ug, am, al, wug, wam, dg, dl);

	return 0;
}