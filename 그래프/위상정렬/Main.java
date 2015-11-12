package 위상정렬;

public class Main
{
	public static void main(String[] args)
	{
		Taskmanager tm = new Taskmanager();
		DirectedGraph dg = new DirectedGraph();
		
		tm.makeDirectedGraph(dg);	
		tm.topologicalSort(dg);
	}

}
