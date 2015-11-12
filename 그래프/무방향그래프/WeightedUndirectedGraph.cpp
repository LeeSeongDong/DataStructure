#include "WeightedUndirectedGraph.h"

void WeightedUndirectedGraph::makeWeightedAdjMatrix(WeightedAdjMatrixGraph &weightedAdjMatrix)
{
	IoHandler ioh;

	ioh.putMsg("������ ����ġ �׷����� ����� ���ϸ��� �Է��Ͻÿ� (����� quit) : ");
	string fileName = ioh.inputMsg();

	if (fileName == "quit")
	{
		return;
	}
	else
	{
		ioh.inputWeightedAdjMatrix(weightedAdjMatrix, fileName);
	}
}

void WeightedUndirectedGraph::kruskal(const WeightedAdjMatrixGraph &weightedAdjMatrix)
{
	int numOfVertex = weightedAdjMatrix.getNumOfVertex();
	int numOfEdge = weightedAdjMatrix.getNumOfEdge();

	int **weightedMatrix = weightedAdjMatrix.getGraph();
	int *vertex = new int[numOfVertex];

	for (int i = 0; i < numOfVertex; ++i)
	{
		vertex[i] = -1;
	}

	int **edgeList = new int*[numOfEdge];
	int *index = new int[numOfEdge];

	//edge ����
	sortEdgeByWeight(edgeList, weightedMatrix, numOfVertex);

	//edge ����
	int u, v;
	int temp1, temp2;
	int selectCount = 0;

	for (int i = 0; i < numOfEdge; ++i)
	{
		temp1 = edgeList[i][0];
		temp2 = edgeList[i][1];

		u = temp1;
		v = temp2;

		//��Ʈ ã��
		while (vertex[u] >= 0)
		{
			u = vertex[u];
		}
		while (vertex[v] >= 0)
		{
			v = vertex[v];
		}

		//����ŬȮ��
		if (u == v)
		{
			continue;
		}

		//�� ū Ʈ���� ����
		if (vertex[u] > vertex[v])
		{
			int temp = temp1;
			temp1 = temp2;
			temp2 = temp;
		}

		vertex[u] += vertex[v];
		vertex[v] = u;

		for (int j = 0; j < numOfVertex; ++j)
		{
			if (vertex[j] == v)
			{
				vertex[j] = u;
			}
		}

		//���õ� ���� üũ
		index[selectCount] = i;
		++selectCount;
	}

	//MST ��������? (������ī��Ʈ 1���϶� ����)
	if (isAbleMST(vertex, numOfVertex))
	{
		//�ּҺ�� ���
		calMinimumCost(edgeList, index, selectCount);
	}
	
	for (int i = 0; i < numOfEdge; ++i)
	{
		delete[]edgeList[i];
	}
	delete[]edgeList;
	delete []index;
	delete []vertex;
}

void WeightedUndirectedGraph::sortEdgeByWeight(int** edgeList, int** weightedMatrix, int numOfVertex)
{
	int edgeCnt = 0;
	bool swapFlag = false;

	//�迭�� edge ����
	for (int i = 0; i < numOfVertex; ++i)
	{
		for (int j = i + 1; j < numOfVertex; ++j)
		{
			if (weightedMatrix[i][j] != 0)
			{
				edgeList[edgeCnt] = new int[3];

				edgeList[edgeCnt][0] = i;
				edgeList[edgeCnt][1] = j;
				edgeList[edgeCnt][2] = weightedMatrix[i][j];

				++edgeCnt;
			}
		}
	}

	//����ġ �񰨼Ҽ� ����
	for (int i = 0; i < edgeCnt; ++i)
	{
		int k = i;
		for (int j = i + 1; j < edgeCnt; ++j)
		{
			if (edgeList[k][2] > edgeList[j][2])
			{
				k = j;
			}
		}

		int temp[3];
		temp[0] = edgeList[k][0];
		temp[1] = edgeList[k][1];
		temp[2] = edgeList[k][2];

		edgeList[k][0] = edgeList[i][0];
		edgeList[k][1] = edgeList[i][1];
		edgeList[k][2] = edgeList[i][2];

		edgeList[i][0] = temp[0];
		edgeList[i][1] = temp[1];
		edgeList[i][2] = temp[2];
	}
}

void WeightedUndirectedGraph::calMinimumCost(int** edgeList, int* index, int selectCount)
{
	IoHandler ioh;

	int sum = 0;

	ioh.putMsg("���õ� ���� : ");

	for (int i = 0; i < selectCount; ++i)
	{
		ioh.printEdge(edgeList[index[i]][0], edgeList[index[i]][1], edgeList[index[i]][2]);
		ioh.putMsg(" ");
	}

	ioh.putNewLine();

	ioh.putMsg("�ּҺ���� : ");

	for (int i = 0; i < selectCount; ++i)
	{
		if (i != 0)
		{
			ioh.putMsg(" + ");
		}

		sum += edgeList[index[i]][2];
		ioh.putNum(edgeList[index[i]][2]);
	}

	ioh.putMsg(" = ");
	ioh.putNum(sum);
	
}

bool WeightedUndirectedGraph::isAbleMST(int* vertex, int numOfVertex)
{
	IoHandler ioh;
	int count = 0;

	for (int i = 0; i < numOfVertex; ++i)
	{
		if (vertex[i] < 0)
		{
			++count;
		}
	}

	if (count == 1)
	{
		ioh.putMsg("�ּҺ�� ����Ʈ���� ���� �� ����");
		ioh.putNewLine();
		return true;
	}
	else
	{
		ioh.putMsg("�ּҺ�� ����Ʈ���� ���� �� ����");
		ioh.putNewLine();
		return false;
	}
}