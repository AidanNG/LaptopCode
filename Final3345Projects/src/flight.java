import list.linkedList;
import java.util.*;
import stack.*;
import java.io.*;
public class flight {
    class city{
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
    class adjNode<city> {
        city source;
        city destination;
        adjNode next;

        public adjNode(city source, city destination) {
            this.source = source;
            this.destination = destination;
            next = null;
        }
    }

    class adjList {
        adjNode head;
    }

    class Graph {
        int V;
        adjList array[];

        public Graph(int V) {
            this.V = V;
            array = new adjList[V];

            for (int i = 0; i < V; i++) {
                array[i] = new adjList();
                array[i].head = null;
            }
        }

        /*public void addEdge(city source, city destination) {

            adjNode adn = new adjNode(source, destination);
            adn.next = array[source].head;
            array[source].head = adn;

        }*/
    }
    public static void main(String[] args) throws IOException{
        Scanner data = new Scanner(new File("FlightData.txt"));
        int paths = data.nextInt();
        for(int i =0; i<paths-1;i++){

        }
    }
}
