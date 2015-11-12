#include "DirectedGraph.h"

void DirectedGraph::makeDirectedGraph(DirectedAdjListGraph &dl)
{
	IoHandler ioh;

	ioh.putMsg("���� �׷����� ����� ���ϸ��� �Է��Ͻÿ� (����� quit) : ");
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

	//indegree0�ΰ� ã��
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
		//�ݺ�
	}

	if (count != numOfVertex)
	{
		ioh.putMsg("����Ŭ�� ������");
	}
	else
	{
		ioh.printSortedVertex(visitedVertex, numOfVertex);
	}

}