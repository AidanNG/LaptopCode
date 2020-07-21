//(c) A+ Computer Science
//www.apluscompsci.com

//Name -

import static java.lang.System.*;

import java.util.Arrays;
import java.util.LinkedList;

public class BinarySearchTree
{
	private TreeNode root;

	public BinarySearchTree()
	{
		root = null;
	}

	public void add(Comparable val)
	{
		root = add(val, root);
	}

	private TreeNode add(Comparable val, TreeNode tree)
	{
	   if(tree == null)
			tree = new TreeNode(val);

		Comparable treeValue = tree.getValue();
		int dirTest = val.compareTo(treeValue);


		if(dirTest < 0)
			tree.setLeft(add(val, tree.getLeft()));
		else if(dirTest > 0)
			tree.setRight(add(val, tree.getRight()));

		return tree;
	}



	public void inOrder()
	{
		inOrder(root);
		System.out.println("\n\n");
	}

	private void inOrder(TreeNode tree)//left,root,right
	{
		if (tree != null){
			inOrder(tree.getLeft());
			System.out.print(tree.getValue() + " ");
			inOrder(tree.getRight());
		}
	}

	//add preOrder, postOrder, and revOrder

	public void revOrder()
	{
		revOrder(root);
		System.out.println("\n\n");
	}
	private void revOrder(TreeNode tree){//right,root,left
		if(tree != null){
			revOrder(tree.getRight());
			System.out.print(tree.getValue() + " ");
			revOrder(tree.getLeft());
		}
	}
	public void postOrder()
	{
		postOrder(root);
		System.out.println("\n\n");
	}
	private void postOrder(TreeNode tree){//left,right,root
		if(tree != null){
			postOrder(tree.getLeft());
			postOrder(tree.getRight());
			System.out.print(tree.getValue() + " ");

		}
	}
	public void preOrder()
	{
		preOrder(root);
		System.out.println("\n\n");
	}
	private void preOrder(TreeNode tree){//root,left,right
		if(tree != null){
			System.out.print(tree.getValue() + " ");
			preOrder(tree.getLeft());
			preOrder(tree.getRight());


		}
	}


	public int getNumLevels()
	{
		return getNumLevels(root);
	}

	private int getNumLevels(TreeNode tree)
	{
		if(tree==null)
			return 0;
		else if(getNumLevels(tree.getLeft())>getNumLevels(tree.getRight()))
			return 1+getNumLevels(tree.getLeft());
		else
			return 1+getNumLevels(tree.getRight());
	}




	//add getNumLeaves, getWidth, getHeight, getNumNodes, and isFull
	public int getHeight()
	{
		return getHeight(root);
	}

	private int getHeight(TreeNode tree)
	{
		if(tree==null)
			return -1;
		else if(getHeight(tree.getLeft())>getHeight(tree.getRight())){

			return 1+getHeight(tree.getLeft());}
		else{

			return 1+getHeight(tree.getRight());}
	}

	public int getNumLeaves()
	{
		return getNumLeaves(root);
	}

	private int getNumLeaves(TreeNode node)
	{
		if (node == null)
			return 0;
		if (node.getLeft() == null && node.getRight() == null)
			return 1;
		else
			return getNumLeaves(node.getLeft()) + getNumLeaves(node.getRight());
	}













	//add extra credit options here - 10 points each

	//search

	//maxNode

	//minNode

	//level order

	//display like a tree

	//remove


	public String toString()
	{
		return toString(root);
	}

	private String toString(TreeNode tree)
	{
		if(tree==null)
			return "";
		else return "" + toString(tree.getLeft())+ " " + tree.getValue() + " "  + toString(tree.getRight());
	}
}

