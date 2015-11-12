package 위상정렬;

public class Taskmanager
{
	public Taskmanager() {}
	
	public void makeDirectedGraph(DirectedGraph dg)
	{
		IoHandler ioh = new IoHandler();

		ioh.putMsg("방향 가중치 그래프가 저장된 파일명을 입력하시오 (종료는 quit) : ");
		String fileName = ioh.inputMsg();

		if (fileName == "quit")
		{
			return;
		}
		else
		{
			ioh.inputFile(dg, fileName);
		}
	}
	
	public void topologicalSort(DirectedGraph dg)
	{
		IoHandler ioh = new IoHandler();
	
		int numOfVertex = dg.getNumOfVertex();
		int visitedVertex[] = new int[numOfVertex];
		boolean isVisited[] = new boolean[numOfVertex];
		final int[][] vertex = dg.getGraph();
		int count = 0;	
		
		for(int i = 0; i < numOfVertex; ++i)
		{
			isVisited[i] = false;
		}
		
		//indegree0인거 찾기
		//edge 삭제하고 temp
		//반복
		
		for(int i = 0; i < numOfVertex; ++i)
		{
			int u = -1;
			
			//inDegree == 0 인 vertex : u
			for(int j = 0; j < numOfVertex; ++j)
			{
				if(dg.getInDegree(j) == 0 && !isVisited[j])
				{
					u = j;
					break;
				}
			}
			
			int v = -1;
			
			//u와 연결된 vertex : v
			for(int j = 0; j < numOfVertex; ++j)
			{
				if(vertex[u][j] == 1)
				{
					v = j;
					dg.deleteEdge(u, v);
				}
			}
			
			isVisited[u] = true;
			visitedVertex[i] = u;
			++count;
		}
		
		if(count != numOfVertex)
		{
			ioh.putMsg("사이클이 존재함");
		}
		else
		{
			ioh.printSortedVertex(visitedVertex, numOfVertex);
		}
	}
	
}
