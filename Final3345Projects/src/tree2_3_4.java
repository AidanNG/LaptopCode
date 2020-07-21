//Class and Teacher: Kamran Khan 3345.501
//Name:Aidan Gow
//This file contains both the class for the 2-3-4 tree and the run files of the project description

class intItem{//b/c comparative operations with null dont work with just int
    public int data;
    public intItem(int item){data = item;}
    public String toString(){
        return ""+data;
    }
}
class node{
    private static final int MAX = 4;
    private int keys;
    private node parent;
    private node childArray[] = new node[MAX];
    private intItem keyArray[] = new intItem[MAX-1];
    //connect child to node
    public void connectChild(int childNum, node child) {
        childArray[childNum] = child;
        if(child != null)
            child.parent = this;
    }
    // -------------------------------------------------------------
    // disconnect child from this node, return it
    public node disconnectChild(int childNum) {
        node tempNode = childArray[childNum];
        childArray[childNum] = null;
        return tempNode;
    }
    //set of getter methods for ease of use later
    public node getChild(int childNum) { return childArray[childNum]; }
    public node getParent() { return parent; }
    public boolean isLeaf() { return (childArray[0]==null) ? true : false; }
    public int getKeys() { return keys; }
    public intItem getKey(int index) { return keyArray[index]; }
    public boolean isFull() { return (keys==MAX-1) ? true : false; }
    public int insertItem(intItem newKey) {//use if assuming node is not full
        keys++;
        for(int i=MAX-2; i>=0; i--)
        {

            if(keyArray[i] == null) {
                continue;
            } else {
                if(newKey.data < keyArray[i].data) keyArray[i+1] = keyArray[i];
                else {
                    keyArray[i+1] = newKey;
                    return i+1;
                }
            }
        }
        keyArray[0] = newKey;
        return 0;
    }
    public intItem removeItem(){//removes largest key for ease of use later
        // assumes node not empty
        intItem temp = keyArray[keys-1];
        keyArray[keys-1] = null;
        keys--;
        return temp;
    }
    // display node for ease of use for later full tree display
    public void displayNode() {
        for(int i=0; i<keys; i++) System.out.print(keyArray[i].toString() + " ");
        System.out.println();
    }
    //find operation
    public int findItem(int key){
        for(int i=0; i<MAX-1; i++){ //cycle thru node until found
            if(keyArray[i] == null)
                break;
            else if(keyArray[i].data == key)
                return i;
        }
        return -1;
    }
    //main remove function placed at the node level
    void remove(int k) {
        int idx = findItem(k);
        // The key to be removed is present in this node
        if (idx < keys && keyArray[idx+1].data == k) {
            // If the node is a leaf node - removeFromLeaf is called
            // Otherwise, removeFromNonLeaf function is called
            if (isLeaf())
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        } else {
            // The key to be removed is present in the sub-tree rooted with this node
            // The flag indicates whether the key is present in the sub-tree rooted
            // with the last child of this node
            boolean flag = ((idx == keys) ? true : false);

            // If the child where the key is supposed to exist has less that t keys,
            // we fill that child
            if (childArray[idx+1].getKeys()<MAX)
            fill(idx);

            // If the last child has been merged, it must have merged with the previous
            // child and so we recurse on the (idx-1)th child. Else, we recurse on the
            // (idx)th child which now has atleast t keys
            if (flag && idx > keys){
                childArray[idx - 1].remove(k);
                }else {
                    childArray[idx].remove(k);
            }
        }

    }
    public void fill(int idx){
        // If the previous child(C[idx-1]) has more than t-1 keys, borrow a key
        // from that child
        if (idx!=0 && childArray[idx-1].getKeys()>=MAX)
        borrowFromPrev(idx);

        // If the next child(C[idx+1]) has more than t-1 keys, borrow a key
        // from that child
    else if (idx!=keys && childArray[idx+1].getKeys()>=MAX)
        borrowFromNext(idx);

        // Merge C[idx] with its sibling
        // If C[idx] is the last child, merge it with with its previous sibling
        // Otherwise merge it with its next sibling
    else
        {
            if (idx != keys)
                merge(idx);
            else
                merge(idx-1);
        }
        return;
    }
    public void removeFromLeaf(int idx){
        // Move all the keys after the idx-th pos one place backward
        for (int i=idx+1; i<keys; ++i)
            keyArray[i-1] = keyArray[i];

        // Reduce the count of keys
        keys--;

        return;
    }
    public void removeFromNonLeaf(int idx){
        int k = keyArray[idx].data;

        // If the child that precedes k (C[idx]) has atleast t keys,
        // find the predecessor 'pred' of k in the subtree rooted at
        // C[idx]. Replace k by pred. Recursively delete pred
        // in C[idx]
        if (childArray[idx].getKeys() >= MAX)
        {
            int pred = getPred(idx);
            keyArray[idx].data = pred;
            childArray[idx].remove(pred);
        }

        // If the child C[idx] has less that t keys, examine C[idx+1].
        // If C[idx+1] has atleast t keys, find the successor 'succ' of k in
        // the subtree rooted at C[idx+1]
        // Replace k by succ
        // Recursively delete succ in C[idx+1]
    else if  (childArray[idx+1].getKeys() >= MAX)
        {
            int succ = getSuc(idx);
            keyArray[idx].data = succ;
            childArray[idx+1].remove(succ);
        }

        // If both C[idx] and C[idx+1] has less that t keys,merge k and all of C[idx+1]
        // into C[idx]
        // Now C[idx] contains 2t-1 keys
        // Free C[idx+1] and recursively delete k from C[idx]
    else
        {
            merge(idx);
            childArray[idx].remove(k);
        }

    }
    public int getPred(int idx){
        node cur=childArray[idx];
        while (!cur.isLeaf())
            cur = childArray[cur.getKeys()];

        // Return the last key of the leaf
        return cur.keyArray[cur.getKeys()-1].data;
    }
    public int getSuc(int idx){
        node cur = childArray[idx+1];
        while (!cur.isLeaf())
            cur = cur.childArray[0];

        // Return the first key of the leaf
        return cur.keyArray[0].data;
    }
    public void borrowFromPrev(int idx)
    {

        node child=childArray[idx];
        node sibling=childArray[idx-1];

        // The last key from C[idx-1] goes up to the parent and key[idx-1]
        // from parent is inserted as the first key in C[idx]. Thus, the  loses
        // sibling one key and child gains one key

        // Moving all key in C[idx] one step ahead
        for (int i=child.getKeys()-1; i>=0; --i) {
            child.keyArray[i+1] = child.getKey(i);
        }

        // If C[idx] is not a leaf, move all its child pointers one step ahead
        if (!child.isLeaf())
        {
            for(int i=child.getKeys(); i>=0; --i)
                child.childArray[i+1] = child.childArray[i];
        }

        // Setting child's first key equal to keys[idx-1] from the current node
        child.keyArray[0] = keyArray[idx-1];

        // Moving sibling's last child as C[idx]'s first child
        if(!child.isLeaf())
            child.childArray[0] = sibling.childArray[sibling.getKeys()];

        // Moving the key from the sibling to the parent
        // This reduces the number of keys in the sibling
        keyArray[idx-1] = sibling.keyArray[sibling.getKeys()-1];

        child.keys += 1;
        sibling.keys -= 1;
    }

    // A function to borrow a key from the C[idx+1] and place
// it in C[idx]
    public void borrowFromNext(int idx)
    {

        node child=childArray[idx];
        node sibling= childArray[idx+1];

        // keys[idx] is inserted as the last key in C[idx]
        child.keyArray[(child.getKeys())] = keyArray[idx];

        // Sibling's first child is inserted as the last child
        // into C[idx]
        if (!(child.isLeaf()))
            child.childArray[(child.getKeys())+1] = sibling.childArray[0];

        //The first key from sibling is inserted into keys[idx]
        keyArray[idx] = sibling.keyArray[0];

        // Moving all keys in sibling one step behind
        for (int i=1; i<sibling.getKeys(); ++i)
            sibling.keyArray[i-1] = sibling.keyArray[i];

        // Moving the child pointers one step behind
        if (!sibling.isLeaf())
        {
            for(int i=1; i<=sibling.getKeys(); ++i)
                sibling.childArray[i-1] = sibling.childArray[i];
        }

        // Increasing and decreasing the key count of C[idx] and C[idx+1]
        // respectively
        child.keys += 1;
        sibling.keys -= 1;

    }

    // A function to merge C[idx] with C[idx+1]
// C[idx+1] is freed after merging
    public void merge(int idx)
    {
        node child = childArray[idx];
        node sibling = childArray[idx+1];

        // Pulling a key from the current node and inserting it into (t-1)th
        // position of C[idx]
        child.keyArray[MAX-1] = keyArray[idx];

        // Copying the keys from C[idx+1] to C[idx] at the end
        for (int i=0; i<sibling.getKeys(); ++i)
            child.keyArray[i+MAX] = sibling.keyArray[i];

        // Copying the child pointers from C[idx+1] to C[idx]
        if (!child.isLeaf())
        {
            for(int i=0; i<=sibling.getKeys(); ++i)
                child.childArray[i+MAX] = sibling.childArray[i];
        }

        // Moving all keys after idx in the current node one step before -
        // to fill the gap created by moving keys[idx] to C[idx]
        for (int i=idx+1; i<keys; ++i)
            keyArray[i-1] = keyArray[i];

        // Moving the child pointers after (idx+1) in the current node one
        // step before
        for (int i=idx+2; i<=keys; ++i)
            childArray[i-1] = childArray[i];

        // Updating the key count of child and the current node
        child.keys += sibling.keys+1;
        keys--;

        // Freeing the memory occupied by sibling
        //delete(sibling);

    }
}


public class tree2_3_4 {
    private node root = new node();
    tree2_3_4(){
        root = new node();
    }
    //basic insertion command for tree
    public void insert(int num){
        node current = root;//start at root for traversal
        intItem temp = new intItem(num);
        while(true){
            if( current.isFull() ) {
                // pre split before insertion
                split(current);
                current = current.getParent();
                current = getNextChild(current, num);
            } else if( current.isLeaf() )
                // if the current node is a leaf, then break and insert
                break;
            else
                current = getNextChild(current, num);
        }
        current.insertItem(temp);
    }
    //in the case that we need to split, this helper command should be able to do it at node n
    public void split(node n){
        //remove data
        intItem itemC = n.removeItem();
        intItem itemB = n.removeItem();
        //remove children
        node child2 = n.disconnectChild(2);
        node child3 = n.disconnectChild(3);
        //early declarations
        node newRight = new node();
        node parent;
        if(n==root){//in the event that the node split is the root, we need to make a new root ndoe
            root = new node();
            parent = root;
            root.connectChild(0, n);
        } else
            parent = n.getParent();    // get parent
        // deal with parent
        int itemIndex = parent.insertItem(itemB); // item B to parent
        int k = parent.getKeys();         // total items?
        //move connections
        for(int i=k-1; i>itemIndex; i--) {
            node temp = parent.disconnectChild(i);
            //shift right
            parent.connectChild(i+1, temp);
        }
        // connect new node to parent
        parent.connectChild(itemIndex+1, newRight);
        newRight.insertItem(itemC);
        newRight.connectChild(0, child2);
        newRight.connectChild(1, child3);
    }
    public node getNextChild(node n, int num){
        int numItems = n.getKeys();
        int index;
        for(index=0; index<numItems; index++)
        {
            if( num < n.getKey(index).data ) return n.getChild(index);
        }
        return n.getChild(index);
    }
    public void displayTree(){
        System.out.println("Printing the tree");
        rDisplayTree(root, 0,0);
    }
    //helper command to display tree
    private void rDisplayTree(node n, int level, int child){
        System.out.print("level:"+level+" child:"+child+" -> ");
        n.displayNode();               // display this node


        // call ourselves for each child of this node
        int numItems = n.getKeys();
        for(int i=0; i<numItems+1; i++)
        {
            node next = n.getChild(i);
            if(next != null)
                rDisplayTree(next, level+1, i);
            else
                return;
        }
    }
    //find command
    public int find(int key) {
        node current = root;
        int childNum;
        while (true) {
            if ((childNum = current.findItem(key)) != -1)//find item within the node
                return childNum;               // found it
            else if (current.isLeaf())
                return -1;                        // can't find it
            else                                 // search again
                current = getNextChild(current, key);
        }
    }
    //remove command
    public void remove(int k){
        root.remove(k);

        // If the root node has 0 keys, make its first child as the new root
        //  if it has a child, otherwise set root as null
        if (root.getKeys()==0)
        {
            node tmp = root;
            if (root.isLeaf())
                root = null;
            else
                root = root.getChild(0);

            // Free the old root
            //delete tmp;
        }

    }


}
class treeRunner{
    public static void main(String[] args) {

        tree2_3_4 theTree = new tree2_3_4();
        System.out.println("inserting numbers");
        theTree.insert(1);
        theTree.insert(12);
        theTree.insert(8);
        theTree.insert(2);
        theTree.insert(25);
        theTree.insert(6);
        theTree.insert(14);
        theTree.insert(28);
        theTree.insert(17);
        theTree.insert(7);
        theTree.insert(52);
        theTree.insert(16);
        theTree.insert(48);
        theTree.insert(68);
        theTree.insert(3);
        theTree.insert(26);
        theTree.insert(29);
        theTree.insert(53);
        theTree.insert(55);
        theTree.insert(45);
        theTree.displayTree();
        System.out.println();
        System.out.println("removing numbers");

        theTree.remove(3);
        theTree.remove(17);
        theTree.remove(55);
        theTree.remove(1);
        theTree.remove(52);
        theTree.remove(48);
        theTree.remove(2);
        theTree.remove(14);
        theTree.remove(25);

        theTree.displayTree();
    }
}