#include "UndirectedGraph.h"

void UndirectedGraph::makeAdjMatrix(AdjMatrixGraph &adjMatrix, string fileName)
{
	IoHandler ioh;

	ioh.inputAdjMatrix(adjMatrix, fileName);
}

void UndirectedGraph::makeAdjList(AdjListGraph &adjList, string fileName)
{
	IoHandler ioh;

	ioh.inputAdjList(adjList, fileName);
}

void UndirectedGraph::makeUndirectedGraph(AdjMatrixGraph &adjMatrix, AdjListGraph &adjList)
{
	IoHandler ioh;

	ioh.putMsg("무방향 그래프가 저장된 파일명을 입력하시오(종료는 quit) : ");

	string fileName = ioh.inputMsg();

	if (fileName == "quit")
	{
		return;
	}
	else
	{
		makeAdjMatrix(adjMatrix, fileName);
		makeAdjList(adjList, fileName);
	}
}

void UndirectedGraph::printAdjMatrix(const AdjMatrixGraph &adjMatrix) 
{
	IoHandler ioh;
	ioh.putMsg("입력된 그래프의 인접행렬 표현");
	ioh.putNewLine();

	int** adjMatrixGraph = adjMatrix.getGraph();

	int numOfVertex = adjMatrix.getNumOfVertex();

	for (int i = 0; i < numOfVertex; ++i)
	{
		for (int j = 0; j < numOfVertex; ++j)
		{
			ioh.putNum(adjMatrixGraph[i][j]);
			ioh.putMsg(" ");
		}
		ioh.putNewLine();
	}

	ioh.putNewLine();
}

void UndirectedGraph::AdjMatrixBFS(const AdjMatrixGraph &adjMatrix)
{
	IoHandler ioh;
	ioh.putMsg("인접행렬 + BFS");
	ioh.putNewLine();

	queue<int> q;

	int numOfVertex = adjMatrix.getNumOfVertex();

	bool *isVisited = new bool[numOfVertex];
	int *connectedVertex = new int[numOfVertex];
	int** adjMatrixGraph = adjMatrix.getGraph();

	for (int i = 0; i < numOfVertex; ++i)
	{
		isVisited[i] = false;
	}

	int count = 0;
	int connectedComponentCount = 0;
	int connectedVertexCnt = 0;
	int iterator = 0;

	isVisited[iterator] = true;
	q.push(iterator);

	while (true)
	{
		iterator = q.front();
		q.pop();

		connectedVertex[connectedVertexCnt] = iterator;
		++connectedVertexCnt;
		++count;

		for (int i = 0; i < numOfVertex; ++i)
		{
			if (!isVisited[i] && adjMatrixGraph[iterator][i] == 1)
			{
				isVisited[i] = true;

				q.push(i);
			}
		}

		if (q.empty())	//연결요소 찾았을때
		{
			++connectedComponentCount;

			//연결요소출력
			ioh.printConnectedComponent(connectedVertex, connectedVertexCnt, connectedComponentCount);

			if (count == numOfVertex) //모든정점 방문시 종료
			{
				break;
			}
			else
			{
				connectedVertexCnt = 0;

				for (int i = 0; i < numOfVertex; ++i)
				{
					if (!isVisited[i])
					{
						iterator = i;

						isVisited[iterator] = true;
						q.push(iterator);
						break;
					}
				}
			}
		}
	}

	delete[] isVisited;
	delete[] connectedVertex;
	ioh.putNewLine();
}

void UndirectedGraph::AdjMatrixDFS(const AdjMatrixGraph &adjMatrix)
{
	IoHandler ioh;
	ioh.putMsg("인접행렬 + DFS");
	ioh.putNewLine();

	stack<int> stack;

	int numOfVertex = adjMatrix.getNumOfVertex();

	bool *isVisited = new bool[numOfVertex];
	int *connectedVertex = new int[numOfVertex];
	int** adjMatrixGraph = adjMatrix.getGraph();

	for (int i = 0; i < numOfVertex; ++i)
	{
		isVisited[i] = false;
	}

	int count = 0;
	int connectedComponentCount = 0;
	int connectedVertexCnt = 0;
	int iterator;

	while (true)
	{
		if (stack.empty())	//연결요소 찾았을때
		{
			if (count != 0)
			{
				++connectedComponentCount;

				//연결요소출력
				ioh.printConnectedComponent(connectedVertex, connectedVertexCnt, connectedComponentCount);
			}

			if (count == numOfVertex) //모든정점 방문시 종료
			{
				break;
			}
			else
			{
				connectedVertexCnt = 0;

				for (int i = 0; i < numOfVertex; ++i)
				{
					if (!isVisited[i])
					{
						iterator = i;

						isVisited[iterator] = true;
						stack.push(iterator);

						connectedVertex[connectedVertexCnt] = iterator;
						++connectedVertexCnt;
						++count;

						break;
					}
				}
			}
		}

		iterator = stack.top();

		for (int i = 0; i < numOfVertex; ++i)
		{
			if (!isVisited[i] && adjMatrixGraph[iterator][i] == 1)
			{
				isVisited[i] = true;
				stack.push(i);

				connectedVertex[connectedVertexCnt] = i;
				++connectedVertexCnt;
				++count;

				break;
			}

			if (i == numOfVertex - 1)
			{
				stack.pop();
			}
		}
	}

	delete[] isVisited;
	delete[] connectedVertex;

	ioh.putNewLine();
}

void UndirectedGraph::printAdjList(const AdjListGraph &adjList)
{
	IoHandler ioh;
	ioh.putMsg("입력된 그래프의 인접리스트 표현");
	ioh.putNewLine();

	int numOfVertex = adjList.getNumOfVertex();
	AdjListNode** adjListGraph = adjList.getGraph();
	AdjListNode* iterator;

	for (int i = 0; i < numOfVertex; ++i)
	{
		iterator = adjListGraph[i];
		ioh.putNum(i);
		ioh.putMsg(" -> ");

		if (!adjList.getLink(iterator))
		{
			ioh.putMsg("null");
			ioh.putNewLine();
		}
		else
		{
			iterator = adjList.getLink(iterator);

			while (iterator)
			{
				ioh.putNum(adjList.getData(iterator));

				if (adjList.getLink(iterator))
				{
					ioh.putMsg(" - ");
				}

				iterator = adjList.getLink(iterator);
			}

			ioh.putNewLine();
		}
	}

	ioh.putNewLine();
}

void UndirectedGraph::AdjListBFS(const AdjListGraph &adjList)
{
	IoHandler ioh;
	ioh.putMsg("인접리스트 + BFS");
	ioh.putNewLine();

	queue<AdjListNode*> q;

	int numOfVertex = adjList.getNumOfVertex();

	bool *isVisited = new bool[numOfVertex];
	int *connectedVertex = new int[numOfVertex];
	AdjListNode** adjListGraph = adjList.getGraph();
	AdjListNode* iterator = adjListGraph[0];

	for (int i = 0; i < numOfVertex; ++i)
	{
		isVisited[i] = false;
	}

	int count = 0;
	int connectedComponentCount = 0;
	int connectedVertexCnt = 0;

	q.push(iterator);

	while (true)
	{
		iterator = adjListGraph[adjList.getData(q.front())];
		q.pop();

		while (iterator)
		{
			if (!isVisited[adjList.getData(iterator)])
			{
				isVisited[adjList.getData(iterator)] = true;
				connectedVertex[connectedVertexCnt] = adjList.getData(iterator);
				++connectedVertexCnt;
				++count;

				q.push(iterator);
			}

			iterator = adjList.getLink(iterator);
		}
		

		if (q.empty())
		{
			++connectedComponentCount;

			//연결요소출력
			ioh.printConnectedComponent(connectedVertex, connectedVertexCnt, connectedComponentCount);

			if (count == numOfVertex) //모든정점 방문시 종료
			{
				break;
			}
			else
			{
				connectedVertexCnt = 0;

				for (int i = 0; i < numOfVertex; ++i)
				{
					if (!isVisited[i])
					{
						iterator = adjListGraph[i];

						q.push(iterator);
						break;
					}
				}
			}
		}
	}

	delete[] isVisited;
	delete[] connectedVertex;
	ioh.putNewLine();
}

void UndirectedGraph::AdjListDFS(const AdjListGraph &adjList)  
{
	IoHandler ioh;
	ioh.putMsg("인접리스트 + DFS");
	ioh.putNewLine();

	stack<AdjListNode*> stack;

	int numOfVertex = adjList.getNumOfVertex();

	bool *isVisited = new bool[numOfVertex];
	int *connectedVertex = new int[numOfVertex];
	AdjListNode** adjListGraph = adjList.getGraph();
	AdjListNode* iterator = adjListGraph[0];

	for (int i = 0; i < numOfVertex; ++i)
	{
		isVisited[i] = false;
	}

	int count = 0;
	int connectedComponentCount = 0;
	int connectedVertexCnt = 0;

	while (true)
	{
		if (stack.empty())
		{
			if (count != 0)
			{
				++connectedComponentCount;

				//연결요소출력
				ioh.printConnectedComponent(connectedVertex, connectedVertexCnt, connectedComponentCount);
			}

			if (count == numOfVertex) //모든정점 방문시 종료
			{
				break;
			}
			else
			{
				connectedVertexCnt = 0;

				for (int i = 0; i < numOfVertex; ++i)
				{
					if (!isVisited[i])
					{
						iterator = adjListGraph[i];

						stack.push(iterator);
						break;
					}
				}
			}
		}

		iterator = adjListGraph[adjList.getData(stack.top())];

		while (iterator)
		{
			if (!isVisited[adjList.getData(iterator)])
			{
				isVisited[adjList.getData(iterator)] = true;
				connectedVertex[connectedVertexCnt] = adjList.getData(iterator);
				++connectedVertexCnt;
				++count;

				stack.push(iterator);
				break;
			}

			iterator = adjList.getLink(iterator);

			if (!iterator)
			{
				stack.pop();
			}
		}
	}

	delete[] isVisited;
	delete[] connectedVertex;
	ioh.putNewLine();
}