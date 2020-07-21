//(c) A+ Computer Science
//www.apluscompsci.com

//Name -

import static java.lang.System.*;

public class BSTreeRunner
{
   public static void main( String args[] )
   {
 		BinarySearchTree test = new BinarySearchTree();
 		test.add(70);
        test.add(80);
        test.add(85);
        test.add(90);
        test.add(98);
        test.add(100);
        test.add(120);
      System.out.println("IN ORDER");
      test.inOrder();
      System.out.println("PRE ORDER");
      test.preOrder();
      System.out.println("POST ORDER");
      test.postOrder();
      System.out.println("REVERSE ORDER");
      test.revOrder();

       System.out.println("Tree height is "+ test.getHeight());
       System.out.println("Tree width is ");
       System.out.println("Number of leaves is "+ test.getNumLeaves());
      // System.out.println("Number of nodes is " + test.getNumNodes());
       System.out.println("Number of levels is "+ test.getNumLevels());
       System.out.println("Tree as a string"+ test);


 		
 		
 		
 		
 		
 		
 		
 
   }
}