package 위상정렬;

public class DirectedGraph
{
	private int vertex[][];
	private int numOfVertex;
	private int numOfEdge;
	
	public DirectedGraph() {}
	public DirectedGraph(int inputNum)
	{
		setNumOfVertex(inputNum);
	}
	
	public int getNumOfVertex()
	{
		return numOfVertex;
	}
	
	public int getNumOfEdge()
	{
		return numOfEdge;
	}
	
	public void setNumOfVertex(int inputNumOfVertex)
	{
		numOfVertex = inputNumOfVertex;
		
		vertex = new int[numOfVertex][];
		
		for(int i = 0; i < numOfVertex; ++i)
		{
			vertex[i] = new int[numOfVertex];
		}
	}
	
	public boolean isExistEdge(int u, int v)
	{
		if (vertex[u][v] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public boolean insertEdge(int u, int v)
	{
		if (isExistEdge(u, v))
		{
			return false;
		}
		else
		{
			vertex[u][v] = 1;
			++numOfEdge;
			
			return true;
		}
	}
	
	public boolean deleteEdge(int u, int v)
	{
		if(!isExistEdge(u, v))
		{
			return false;
		}
		else
		{
			vertex[u][v] = 0;
			--numOfEdge;
			
			return true;
		}
	}
	
	public int getInDegree(int u)
	{
		int inDegree = 0;
		
		for(int i = 0; i < numOfVertex; ++i)
		{
			if(vertex[i][u] != 0)
			{
				++inDegree;
			}
		}
		
		return inDegree;
	}
	
	public int[][] getGraph()
	{
		return vertex;
	}
}
