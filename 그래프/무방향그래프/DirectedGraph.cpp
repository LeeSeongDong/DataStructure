#include "DirectedGraph.h"

void DirectedGraph::makeDirectedGraph(DirectedAdjListGraph &dl)
{
	IoHandler ioh;

	ioh.putMsg("방향 그래프가 저장된 파일명을 입력하시오 (종료는 quit) : ");
	string fileName = ioh.inputMsg();

	if (fileName == "quit")
	{
		return;
	}
	else
	{
		ioh.inputDirectedAdjList(dl, fileName);
	}
}

void DirectedGraph::topologicalSort(DirectedAdjListGraph &dl) const
{
	IoHandler ioh;

	int numOfVertex = dl.getNumOfVertex();
	int *visitedVertex = new int[numOfVertex];
	bool *isVisited = new bool[numOfVertex];
	AdjListNode **vertex = dl.getGraph();
	AdjListNode* iterator;
	int count = 0;

	for (int i = 0; i < numOfVertex; ++i)
	{
		isVisited[i] = false;
	}

	//indegree0인거 찾기
	for (int i = 0; i < numOfVertex; ++i)
	{
		for (int j = 0; j < numOfVertex; ++j)
		{
			if (isVisited[j])
			{
				continue;
			}

			iterator = vertex[j];

			while (dl.getLink(iterator))
			{
				if (!isVisited[dl.getData(dl.getLink(iterator))])
				{
					break;
				}

				iterator = dl.getLink(iterator);
			}

			if (dl.getLink(iterator))
			{
				continue;
			}

			isVisited[j] = true;
			visitedVertex[count] = j;
			++count;
			break;
		}
		//반복
	}

	if (count != numOfVertex)
	{
		ioh.putMsg("사이클이 존재함");
	}
	else
	{
		ioh.printSortedVertex(visitedVertex, numOfVertex);
	}

}