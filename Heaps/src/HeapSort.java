//(c) A+ Computer Science
//www.apluscompsci.com

//Name -

import java.util.List;
import java.util.ArrayList;
import static java.lang.System.*;

public class HeapSort
{
	private List<Integer> list;

	public HeapSort()
	{
		list = new ArrayList<Integer>();
	}

   public void swapUp(int index)
   {
	   int parent = (index-1)/2;
	   if(parent < 0) return;
	   if(list.get(index) > list.get(parent)){
		   swap(index, parent);
		   swapUp(parent);
	   }
	}

	public void swapDown(int index)
	{
		int child = index*2+1;
		int child2 = index*2+2;

		if(child < list.size()&&list.get(child) > list.get(child2) &&list.get(index) < list.get(child)) {
			swap(child, index);
			swapDown(child);
		}


		if( child2 < list.size()&&list.get(child2)> list.get(child)&&list.get(index) < list.get(child2)){
			swap(child2,index);
			swapDown(child2);
		}
	}

   public void heapSort(int[] nums)
   {

	   Heap fun = new Heap();
	   for(int s: nums) fun.add(s);
	   for(int i = 0; i< nums.length;i++) {
	   	nums[i] = fun.remove();
	   }

   }
   
   private void swap(int first, int last)
   {
	   int i = list.get(first);
	   list.set(first,list.get(last));
	   list.set(last,i);
  	}

	public String toString()
	{
		return list.toString();
	}





}