#ifndef __WEIGHTEDUNDIRECTEDGRAPH_H__
#define __WEIGHTEDUNDIRECTEDGRAPH_H__

#include "IoHandler.h"
#include <queue>

class WeightedUndirectedGraph
{
private :
	void sortEdgeByWeight(int** edgeList, int** weightedMatrix, int numOfVertex);
	void calMinimumCost(int** edgeList, int* index, int selectCount);
	bool isAbleMST(int* vertex, int numOfVertex);

public :
	void makeWeightedAdjMatrix(WeightedAdjMatrixGraph &weightedAdjMatrix);

	void kruskal(const WeightedAdjMatrixGraph &weightedAdjMatrix);
};

#endif
