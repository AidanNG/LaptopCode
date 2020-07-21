//(c) A+ Computer Science
//www.apluscompsci.com

//Name -

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import static java.lang.System.*;

public class Heap
{
	private List<Integer> list;

	public Heap()
	{
		list = new ArrayList<Integer>();
	}

	public void add(int value)
	{
		list.add(value);
		swapUp(list.size()-1);
	}

   public void swapUp(int bot)
   {
   		int parent = (bot - 1) / 2;

   		if (bot >= 0 && list.get(bot) < list.get(parent)) {
   			swap(bot, parent);
   			swapUp(parent);
		}
	}

	public int remove( )
	{
		if (list.isEmpty()) return -1;

		int ret = list.get(0);
		list.set(0, list.get(list.size() - 1)); // set top to bottom right
		list.remove(list.size() - 1); // remove bottom right from array
		swapDown(0);
		return ret;

	}

	public void swapDown(int top)
	{
		int left = top * 2 +1;
		int right = top * 2 + 2;
		if (left < list.size() && list.get(left) < list.get(top)) {
			swap(left, top);
			swapDown(left);
		}
		if (right < list.size() && list.get(right) < list.get(top)) {
			swap(right, top);
			swapDown(right);
		}
	}

	
	private void swap(int start, int parent)
	{
		int i = list.get(start);
		list.set(start,list.get(parent));
		list.set(parent,i);
	}

	public void print()
	{
		out.println("\n\nPRINTING THE HEAP!\n\n");
		StringBuilder sb = new StringBuilder();
		int max=0;
		for(int i=0;i<list.size();i++){
			for(int j=0;j<Math.pow(2,i)&&j+Math.pow(2,i)<list.size();j++){

				if(j>max){
					max=j;
				}
			}

		}

		for(int i=0;i<list.size();i++){
			for(int j=0;j<Math.pow(2,i)&&j+Math.pow(2,i)<list.size();j++){

				for(int k=0;(k<max/((int)Math.pow(2, i)));k++){
					sb.append(" ");
				}
				sb.append(list.get(j+(int)Math.pow(2,i)-1)+" ");

			}
			sb.append("\n");

		}



		System.out.println(sb.toString());

		/*for(int i=0;i<list.size();i++){
			System.out.print("  ");
			for(int j=0;j<Math.pow(2,i)&&j+Math.pow(2,i)<list.size();j++){
				System.out.print(list.get(j+(int)Math.pow(2,i)-1)+" ");

			}
			System.out.println();
		}*/



	}


	public String toString()
	{
		return list.toString();
	}
}