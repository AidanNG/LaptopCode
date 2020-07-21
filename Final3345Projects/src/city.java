import java.util.*;

public class city{
    private String name;
    private int cost;
    private int time;
    public city(){
        name="";
        cost=0;
        time=0;
    }
    city(String n, int cot,int tim){
        name =n;
        cost= cot;
        time = tim;

    }
    public String getName(){
       return name;
    }
    public int getCost() {
        return cost;
    }
    public int getTime() {
        return time;
    }
    public int compareCost(city node1, city node2)
    {
        if (node1.getCost() < node2.getCost())
            return -1;
        if (node1.getCost() > node2.getCost())
            return 1;
        return 0;
    }
    public int compareTime(city node1, city node2)
    {
        if (node1.getTime() < node2.getTime())
            return -1;
        if (node1.getTime() > node2.getTime())
            return 1;
        return 0;
    }
    public String toString(){
        return name +" cost: " + getCost() +" time: "+ getTime();
    }
}
