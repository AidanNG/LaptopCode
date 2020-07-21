package stack;
import java.io.*;
import java.util.*;

public class stack <T>{
    private ArrayList<T> stack = new ArrayList<T> ();
    private int top;
    public void push (T data){
        stack.add(data);
        top++;

    }
    public T pop(){
        return stack.remove(--top);
    }
    public T peek(){
        return stack.get(top-1);
    }
}
