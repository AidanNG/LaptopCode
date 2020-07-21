import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

//Create the class
public class DijkstraPriorityQueue
{
    //Declare the private members variables.
    private HashMap<String, Integer> optimalDistances;
    private HashMap<String, Integer> distances;
    private Set<String> settled;
    private List<Path> visitedNodesList;
    private PriorityQueue<Node> priorityQueue;
    private int optType,otherType;
    private String pathCostTime[][], Source, Destination;
    private List<String> nodeList;
    //constructor
    public DijkstraPriorityQueue(List<String> nodeList)
    {
        this.nodeList = nodeList;
        optimalDistances = new HashMap<String,Integer>();
        distances = new HashMap<String,Integer>();
        settled = new HashSet<String>();
        visitedNodesList = new ArrayList<Path>();
        priorityQueue = new PriorityQueue<Node>(new Node());
    }
    // definition of the method dijkstra_algorithm()
    public void dijkstra_algorithm(String pathCostTime[][], String requestedPath[])
    {
        String evaluationNode;
        Source = requestedPath[0];
        Destination = requestedPath[1];
        if(requestedPath[2].equalsIgnoreCase("C"))
        {
            optType = 2;
            otherType = 3;
        }
        else
        {
            optType = 3;
            otherType = 2;
        }
        this.pathCostTime = pathCostTime;
        for (String node:nodeList)
        {
            optimalDistances.put(node, Integer.MAX_VALUE);
            distances.put(node, Integer.MAX_VALUE);
        }
        priorityQueue.add(new Node(Source, 0));
        optimalDistances.replace(Source,0);
        distances.replace(Source, 0);
        while (!priorityQueue.isEmpty())
        {
            evaluationNode = getNodeWithMinimumDistanceFromPriorityQueue();
            Path evaluationNodeList = new Path();
            evaluationNodeList.setNode(evaluationNode);
            settled.add(evaluationNode);
            evaluateNeighbours(evaluationNode, evaluationNodeList);
            if(!nodeExists(visitedNodesList, evaluationNode))
                visitedNodesList.add(evaluationNodeList);
        }
    }
    // definition of the method nodeExists()
    private boolean nodeExists(List<Path> visitedNodesList2, String evaluationNode)
    {
        for (Path path : visitedNodesList)
        {
            if(path.getNode().equals(evaluationNode))
                return true;
        }
        return false;
    }
    // definition of the method getNodeWithMinimumDistanceFromPriorityQueue()
    private String getNodeWithMinimumDistanceFromPriorityQueue()
    {
        String node = priorityQueue.remove().node;
        return node;
    }
    // definition of the method evaluateNeighbours()
    private void evaluateNeighbours(String evaluationNode, Path evaluationNodeList)
    {
        int edgeDistance = -1;
        int newDistance = -1;
        for (int i = 0; i<pathCostTime.length; i++)
        {
            if(!pathCostTime[i][0].equals(evaluationNode))
                continue;
            String destinationNode;
            for (int j = 0; j < nodeList.size(); j++)
            {
                destinationNode = nodeList.get(j);
                if(!pathCostTime[i][1].equals(destinationNode))
                    continue;
                if (!settled.contains(destinationNode))
                {
                    edgeDistance = Integer.parseInt(pathCostTime[i][optType]);
                    newDistance = optimalDistances.get(evaluationNode) + edgeDistance;
                    if (newDistance < optimalDistances.get(destinationNode))
                    {
                        optimalDistances.replace(destinationNode,newDistance);
                        distances.replace(destinationNode,distances.get(evaluationNode) +
                                Integer.parseInt(pathCostTime[i][otherType]));
                        for (Path path : visitedNodesList)
                        {
                            if(path.exists(destinationNode))
                                path.delete(destinationNode);
                            break;
                        }
                        evaluationNodeList.add(destinationNode);
                    }
                    priorityQueue.add(new Node(destinationNode,optimalDistances.get(destinationNode)));
                }
            }
        }
    }
    // definition of the method main()
    //takes the names of the two input files as well as the output file as arguments.
    public static void main(String args[]) throws FileNotFoundException
    {
        //Declare the variables.
        String pathCostTime[][],requsetedPathList[][];
        BufferedReader flightData, requestedFlightData;
        List<String> nodesList;
        String infile1 = "FlightData.txt";
        String infile2 = "RequestedFlightData.txt";
        String outFile = "output.txt";
        PrintWriter out = new PrintWriter(outFile);
        try
        {
            // Read the data from the files
            flightData = new BufferedReader(new FileReader(infile1));
            requestedFlightData = new BufferedReader(new FileReader(infile2));
            String str;
            nodesList = new ArrayList<String>();
            pathCostTime = new String[Integer.parseInt(flightData.readLine())][4];
            requsetedPathList = new String[Integer.parseInt(requestedFlightData.readLine())][3];
            int i=0,j; String _node;
            // Make tokens of the data of the flightData file
            while((str = flightData.readLine()) != null)
            {
                j=0;
                StringTokenizer data = new StringTokenizer(str,"|");
                int k = 1;
                while(k<=2)
                {
                    if(!nodesList.contains(_node = data.nextToken()))
                    {
                        pathCostTime[i][j++] = _node;
                        nodesList.add(_node);
                    }
                    else
                        pathCostTime[i][j++] = _node;
                    k++;
                }
                while(data.hasMoreTokens())
                {
                    pathCostTime[i][j++] = data.nextToken();
                }
                i++;
            }
            i=0;
            // Make tokens of the data of the requestedFlightData file
            while((str = requestedFlightData.readLine()) != null)
            {
                j=0;
                StringTokenizer data = new StringTokenizer(str,"|");
                while(data.hasMoreTokens())
                    requsetedPathList[i][j++] = data.nextToken();
                i++;
            }
            i=1;
            // Check the type of the cost
            for(String requsetedPath[] : requsetedPathList)
            {
                if(!(nodesList.contains(requsetedPath[0])&& nodesList.contains(requsetedPath[1])))
                {
                    out.println("Path can not be find !!!!!");
                    continue;
                }
                String _type,_otherType;
                if(requsetedPath[2].equals("T"))
                {
                    _type = "Time";
                    _otherType = "Cost";
                }
                else
                {
                    _type = "Cost";
                    _otherType = "Time";
                }
                // Call the DijkstraPriorityQueue to make the priority queue.
                DijkstraPriorityQueue dijkstrasPriorityQueue = new DijkstraPriorityQueue(nodesList);
                // Call the dijkstra_algorithm method to run the Dijkstra's algorithm
                dijkstrasPriorityQueue.dijkstra_algorithm(pathCostTime, requsetedPath);
                out.println("Flight "+i+": "+dijkstrasPriorityQueue.Source+", "+
                        dijkstrasPriorityQueue.Destination+" ("+_type+")");
                for (String node:nodesList)
                {
                    if(!node.equals(dijkstrasPriorityQueue.Destination))
                        continue;
                    List<String> completePath = findPath(dijkstrasPriorityQueue.visitedNodesList,
                            dijkstrasPriorityQueue.Destination);
                    for (int k = 0; k < completePath.size(); k++)
                    {
                        if(k == completePath.size()-1 )
                            out.print(completePath.get(k)+". ");
                        else
                            out.print(completePath.get(k)+" --> ");
                    }
                    out.println(_type+": " + dijkstrasPriorityQueue.optimalDistances.get(node)+" "
                            +_otherType+": "+dijkstrasPriorityQueue.distances.get(node));
                    break;
                }
                i++;
            }
        } catch (Exception e)
        {
            System.out.println("Exception has occured:" + e.toString());
        }
        out.close();
    }
    // definition of the method findPath()
    private static List<String> findPath(List<Path> visitedNodesList, String Destination)
    {
        List<String> completePath = new ArrayList<String>();
        for( Path path : visitedNodesList)
        {
            if(!path.exists(Destination))
                continue;
            completePath = findPath(visitedNodesList, path.getNode());
            completePath.add(Destination);
            return completePath;
        }
        completePath.add(Destination);
        return completePath;
    }
}

// Class
class Node implements Comparator<Node>
{
    public String node;
    public int CostTime;
    public Node()
    {
    }
    // Set the node and their cost
    public Node(String node, int CostTime)
    {
        this.node = node;
        this.CostTime = CostTime;
    }
    // Compare the nodes.
    @Override
    public int compare(Node node1, Node node2)
    {
        if (node1.CostTime < node2.CostTime)
            return -1;
        if (node1.CostTime > node2.CostTime)
            return 1;
        return 0;
    }
}

class Path
{
    private List<String> path;
    private String Node;
    //Create the arrayList
    public Path()
    {
        path = new ArrayList<String>();
    }
    // Set the node
    public void setNode(String Node)
    {
        this.Node = Node;
    }
    // Get the node
    public String getNode()
    {
        return this.Node;
    }
    // Check if the node exist or not
    public Boolean exists(String node)
    {
        if(path.contains(node))
            return true;
        return false;
    }
    // Add the node in the array List
    public void add(String node)
    {
        path.add(node);
    }
    //Delete the node from the list
    public void delete(String node)
    {
        path.remove(node);
    }
}
