//or
//array of ints

import java.util.ArrayList;
import static java.lang.System.*;

public class IntStack
{
    //pick your storage for the stack
    //you can use the an array or an ArrayList

    //option 1
    private int[] rayOfInts;
    private int numInts;

    //option 2
    private ArrayList<Integer> listOfInts = new ArrayList<Integer>();

    public IntStack()
    {

    }

    public void push(int item)
    {
        listOfInts.add(item);
    }

    public int pop()
    {
        return listOfInts.remove(listOfInts.size()-1);

    }

    public boolean isEmpty()
    {
        if(listOfInts.size()==0)return true;
        else return false;
    }

    public int peek()
    {
        return listOfInts.get(listOfInts.size()-1);
    }

    public String toString()
    {
        return listOfInts+"";
    }
}
