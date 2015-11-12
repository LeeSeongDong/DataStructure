#include "IoHandler.h"

void IoHandler::inputAdjMatrix(AdjMatrixGraph &adjMatrix, string fileName)
{
	ifstream inputFile;
	
	inputFile.open(fileName);

	if (inputFile.fail())
	{
		cout << "파일을 찾지 못했습니다.";
		return;
	}

	string strNumOfVertex;
	int numOfVertex;

	string u, v;

	inputFile >> strNumOfVertex;
	numOfVertex = atoi(strNumOfVertex.c_str());

	adjMatrix.setAdjMatrixGraph(numOfVertex);

	while (true)
	{
		inputFile >> u;

		if (u == "-1")
		{
			break;
		}
		inputFile >> v;

		adjMatrix.insertEdge(atoi(u.c_str()), atoi(v.c_str()));
	}

	inputFile.close();
}

void IoHandler::inputAdjList(AdjListGraph &adjList, string fileName)
{
	ifstream inputFile;

	inputFile.open(fileName);

	if (inputFile.fail())
	{
		cout << "파일을 찾지 못했습니다.";
		return;
	}

	string strNumOfVertex;
	int numOfVertex;

	string u, v;

	inputFile >> strNumOfVertex;
	numOfVertex = atoi(strNumOfVertex.c_str());

	adjList.setAdjListGraph(numOfVertex);

	while (true)
	{
		inputFile >> u;

		if (u == "-1")
		{
			break;
		}
		inputFile >> v;

		adjList.insertEdge(atoi(u.c_str()), atoi(v.c_str()));
	}

	inputFile.close();
}

void IoHandler::inputWeightedAdjMatrix(WeightedAdjMatrixGraph &weightedAdjMatrix, string fileName)
{
	ifstream inputFile;

	inputFile.open(fileName);

	if (inputFile.fail())
	{
		cout << "파일을 찾지 못했습니다.";
		return;
	}

	string strNumOfVertex;
	int numOfVertex;

	string u, v, w;

	inputFile >> strNumOfVertex;
	numOfVertex = atoi(strNumOfVertex.c_str());

	weightedAdjMatrix.setWeightedAdjMatrixGraph(numOfVertex);

	while (true)
	{
		inputFile >> u;

		if (u == "-1")
		{
			break;
		}
		inputFile >> v >> w;

		weightedAdjMatrix.insertEdge(atoi(u.c_str()), atoi(v.c_str()), atoi(w.c_str()));
	}

	inputFile.close();
}

void IoHandler::inputDirectedAdjList(DirectedAdjListGraph &directedAdjList, string fileName)
{
	ifstream inputFile;

	inputFile.open(fileName);

	if (inputFile.fail())
	{
		cout << "파일을 찾지 못했습니다.";
		return;
	}

	string strNumOfVertex;
	int numOfVertex;

	string u, v;

	inputFile >> strNumOfVertex;
	numOfVertex = atoi(strNumOfVertex.c_str());

	directedAdjList.setAdjListGraph(numOfVertex);

	while (true)
	{
		inputFile >> u;

		if (u == "-1")
		{
			break;
		}
		inputFile >> v;

		directedAdjList.insertEdge(atoi(u.c_str()), atoi(v.c_str()));
	}

	inputFile.close();
}


string IoHandler::inputMsg()
{
	string msg;
	cin >> msg;

	return msg;
}
int IoHandler::inputNum()
{
	int num;
	cin >> num;

	return num;
}
char IoHandler::inputChar()
{
	char a;
	cin >> a;

	return a;
}
void IoHandler::putMsg(string msg)
{
	cout << msg;
}
void IoHandler::putNum(int num)
{
	cout << num;
}

void IoHandler::putNewLine()
{
	cout << endl;
}

void IoHandler::printConnectedComponent(const int* connectedComponent, int connectedVertexCnt, int count)
{
	cout << "연결요소" << count << " - ";
	for (int i = 0; i < connectedVertexCnt; ++i)
	{
		cout << connectedComponent[i] << " ";
	}
	cout << endl;
}

void IoHandler::printEdge(int u, int v, int weight)
{
	cout << "(" << u << " " << v << " " << weight << ")";
}

void IoHandler::printSortedVertex(const int *visitedVertex, int numOfVertex)
{
	cout << "가능한 하나의 위상정렬 : ";
	
	for (int i = 0; i < numOfVertex; ++i)
	{
		cout << visitedVertex[i] << " ";
	}
}