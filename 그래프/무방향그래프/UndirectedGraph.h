#ifndef __UNDIRECTEDGRAPH_H__
#define __UNDIRECTEDGRAPH_H__

#include "IoHandler.h"
#include <queue>
#include <stack>

class UndirectedGraph
{
private :
	void makeAdjMatrix(AdjMatrixGraph &adjMatrix, string fileName);        //������� ����
	void makeAdjList(AdjListGraph &adjList, string fileName);              //��������Ʈ ����

public :
	UndirectedGraph() {};
	~UndirectedGraph() {};

	void makeUndirectedGraph(AdjMatrixGraph &adjMatrix, AdjListGraph &adjList);

	void printAdjMatrix(const AdjMatrixGraph &adjMatrix); //��� ���
	void AdjMatrixBFS(const AdjMatrixGraph &adjMatrix);   //��� BSF
	void AdjMatrixDFS(const AdjMatrixGraph &adjMatrix);   //��� DFS

	void printAdjList(const AdjListGraph &adjList);       //����Ʈ ���
	void AdjListBFS(const AdjListGraph &adjList);         //����Ʈ BFS
	void AdjListDFS(const AdjListGraph &adjList);         //����Ʈ DFS

};

#endif