package 위상정렬;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class IoHandler
{
	Scanner sc = new Scanner(System.in);
	public IoHandler() {}
	
	public String inputMsg()
	{
		String msg;
		
		msg = sc.next();
		return msg;
	}

	public int inputNum()
	{
		int num;
		
		num = sc.nextInt();
		return num;
	}
	
	public void putMsg(String msg)
	{
		System.out.print(msg);
	}
	
	public void putNum(int num)
	{
		System.out.print(num);
	}

	public void putNewLine()
	{
		System.out.println();
	}
	
	public void inputFile(DirectedGraph dg, String fileName)
	{
		try
		{
			FileReader in = new FileReader(fileName);
			Scanner s = new Scanner(in);
			
			int num = s.nextInt();
			int u, v;
			
			dg.setNumOfVertex(num);
			
			while(true)
			{
				u = s.nextInt();
				
				if(u == -1)
				{
					break;
				}
				v = s.nextInt();
				
				dg.insertEdge(u, v);
			}
			
			in.close();	
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}

	}
	
	public void printSortedVertex(int[] sortedVertex, int numOfVertex)
	{
		System.out.print("가능한 하나의 위상정렬 : ");
		
		for(int i = 0; i < numOfVertex; ++i)
		{
			System.out.print(sortedVertex[i] + " ");
		}
	}

}
