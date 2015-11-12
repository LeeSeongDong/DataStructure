#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include "AdjMatrixGraph.h"
#include "AdjListGraph.h"
#include "WeightedAdjMatrixGraph.h"
#include "DirectedAdjListGraph.h"

class IoHandler
{
private :

public :
	IoHandler() {}
	~IoHandler() {};

	string inputMsg();
	char inputChar();
	int inputNum();
	void putMsg(string msg);
	void putNum(int num);

	void putNewLine();

	//������׷��� �����Է�
	void inputAdjMatrix(AdjMatrixGraph &adjMatrix, string fileName);
	void inputAdjList(AdjListGraph &adjList, string fileName);
	void printConnectedComponent(const int* connectedComponent, int connectedVertexCnt, int count);

	//����Ʈ���׷��� �����Է�
	void inputWeightedAdjMatrix(WeightedAdjMatrixGraph &weightedAdjMatrix, string fileName);
	void printEdge(int u, int v, int weight);

	//����׷���
	void inputDirectedAdjList(DirectedAdjListGraph &directedAdjList, string fileName);
	void printSortedVertex(const int *visitedVertex, int numOfVertex);
};

#endif
