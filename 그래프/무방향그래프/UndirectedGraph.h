#ifndef __UNDIRECTEDGRAPH_H__
#define __UNDIRECTEDGRAPH_H__

#include "IoHandler.h"
#include <queue>
#include <stack>

class UndirectedGraph
{
private :
	void makeAdjMatrix(AdjMatrixGraph &adjMatrix, string fileName);        //인접행렬 생성
	void makeAdjList(AdjListGraph &adjList, string fileName);              //인접리스트 생성

public :
	UndirectedGraph() {};
	~UndirectedGraph() {};

	void makeUndirectedGraph(AdjMatrixGraph &adjMatrix, AdjListGraph &adjList);

	void printAdjMatrix(const AdjMatrixGraph &adjMatrix); //행렬 출력
	void AdjMatrixBFS(const AdjMatrixGraph &adjMatrix);   //행렬 BSF
	void AdjMatrixDFS(const AdjMatrixGraph &adjMatrix);   //행렬 DFS

	void printAdjList(const AdjListGraph &adjList);       //리스트 출력
	void AdjListBFS(const AdjListGraph &adjList);         //리스트 BFS
	void AdjListDFS(const AdjListGraph &adjList);         //리스트 DFS

};

#endif