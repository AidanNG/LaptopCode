//
// Created by aidan on 11/27/18.
//

#ifndef UNTITLED5_BINARYSEARCHTREE_H
#define UNTITLED5_BINARYSEARCHTREE_H
#include <string>
#include <iostream>

// forward declaration of the template class binarySearchTree
template<class DataType>
class binarySearchTree;

// treeNode class
template <class DataType>
class treeNode
{
    friend class binarySearchTree<DataType>;
    // the rest of the treeNode class declaration goes here
private:
    DataType key;         // Binary search tree data item
    treeNode <DataType>*left; //left child node
    treeNode <DataType>*right; //right child node
public:
    //default constructor
    treeNode(){
        left=nullptr;
        right=nullptr;
    }
    //copy constructor
    treeNode ( const DataType &node, treeNode *l, treeNode *r )
    {
        key= node;
        left=l;
        right=r;
    }
};

// binarySearchTree class
template <class DataType>
class binarySearchTree
{
    // Your binarySearchTree goes here
private:
    size_t treeSize;
    treeNode<DataType>* root;
    //helper node
    treeNode<DataType> *currentNode = nullptr;
public:
    //default constructor
    binarySearchTree(){
        root = nullptr;
        treeSize =0;
    }
    //copy constructor
    binarySearchTree(const binarySearchTree &other) {
        if (other.root == nullptr) {//otherTree is empty
            root = nullptr;
            treeSize = 0;
        } else{
            copyTree(root, other.root);
            treeSize = other.size();
        }
    }
    //deconstructor
    virtual ~binarySearchTree(){
        destroy(root);
    }
    //checks if the current tree is empty
    bool empty() const{
        return treeSize==0;
    }
    //returns the size of the current tree
    std::size_t size() const{
        return treeSize;
    }
    //Display the contents of the binary tree in order by key (inorder traversal) left, value, right
    void print() const{
        printTree(root);
    }
    //The is the print helper function
    void printTree(treeNode<DataType>* node) const{
        if (node == nullptr) return;
        printTree(node->left);
        std::cout<< node->key<<std::endl;
        printTree(node->right);
    }
    // print to ostream
    void print(std::ostream &out) const{
        printTree(root, out, printItemFound);
    }
    //this is the second helper function which takes two parameters
    void printTree(treeNode<DataType>* node, std::ostream &out, void(*printItemFound)(const DataType &foundItem, std::ostream &out)) const{
        if (node != nullptr) {
            if (node->left != nullptr) {
                printTree(node->left, out, printItemFound);
            }
            printItemFound(node->key, out);
            if (node->right != nullptr) {
                printTree(node->right, out, printItemFound);
            }
        }
    }
    //third Helper for simple prints
    static void printItemFound(const DataType &node, std::ostream &out) {
        out << node << std::endl;
    }
    //debug
    void debug(std::ostream &out) const{
        out<<"debugging";
    }
    //navigates through the tree for a certain item
    bool find(const DataType &searchItem, void (*foundNode)(const DataType&)){
        treeNode<DataType>* ptr;
        bool found = false;
        if(empty()) {
            std::cout << "Cannot search an empty tree." << std::endl;
            return false;

        }else {
            ptr = root;
            while (ptr != nullptr) {
                if (ptr->key == searchItem) {
                    foundNode(searchItem);
                    return true;
                } else {
                    if (ptr->key < searchItem) {
                        ptr = ptr->right;
                    } else {
                        ptr = ptr->left;
                    }
                }
            }
        }
        return found;
    }

    bool erase(const DataType &deleteItem)
    {
        treeNode<DataType> *current; //pointer to traverse the tree
        treeNode<DataType> *trailCurrent; //pointer behind current
        bool found = false;
        if (root == nullptr)
            std::cout << "Cannot delete from an empty tree." << std::endl;
        else {
            current = root;
            trailCurrent = root;
            while (current != nullptr && !found) {
                if (current->key == deleteItem)
                    found = true;
                else {
                    trailCurrent = current;
                    if (current->key > deleteItem)
                        current = current->left;
                    else
                        current = current->right;
                }
            }//end while
            if (current == nullptr)
                std::cout << "The item to be deleted is not in the tree." << std::endl;
            else if (found) {
                if (current == root) {
                    deleteFromTree(root);
                    treeSize--;
                } else if (trailCurrent->key > deleteItem) {

                    deleteFromTree(trailCurrent->left);
                    treeSize--;
                } else {
                    deleteFromTree(trailCurrent->right);
                    treeSize--;
                }
            }
        }
        return false;
    } //end deleteNode
    void deleteFromTree(treeNode<DataType>* &p)
        {
            treeNode<DataType> *ptr; //pointer to traverse the tree
            treeNode<DataType> *prev; //pointer behind the ptr
            treeNode<DataType> *temp; //pointer to delete the node
            if (p == nullptr)
                std::cout << "Error: The node to be deleted does not exist." << std::endl;
            else if (p->left == nullptr && p->right == nullptr)
            {
                temp = p;
                p = nullptr;
                delete temp;
            }
            else if (p->left == nullptr)
            {
                temp = p;
                p = temp->right;
                delete temp;
            }
            else if (p->right == nullptr)
            {
                temp = p;
                p = temp->left;
                delete temp;
            }
            else
            {
                ptr = p->left;
                prev = nullptr;
                while (ptr->right != nullptr)
                {
                    prev = ptr;
                    ptr = ptr->right;
                }//end while
                p->key= ptr->key;
                if (prev == nullptr)
                    p->left = ptr->left;
                else
                    prev->right = ptr->left;
                delete prev;
            }//end else
            treeSize--;
        } //end deleteFromTree

    static void processFound(const DataType &item){
        std::cout<< "The word/words found are: "<<std::endl;
    }
    void insert(const DataType &newItem){
        treeNode<DataType> *ptr;
        treeNode<DataType> *prev=nullptr;
        treeNode<DataType> *newNode;
        newNode = new treeNode<DataType>;
        newNode -> key = newItem;
        newNode->left = nullptr;
        newNode->right=nullptr;
        if(root == nullptr) {
            root = newNode;
            treeSize++;
        }else{
            ptr = root;
            while(ptr !=nullptr){
                prev = ptr;
                if (ptr->key == newItem)
                {
                    // std::cout << "The item to be inserted is already ";
                    // std::cout << "in the tree -- duplicates are not " << "allowed." << std::endl;
                    // std::cout << newItem << std::endl;
                    update(ptr->key,newItem);
                    return;
                }
                else if (ptr->key > newItem)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }//end while
            if (prev->key > newItem)
            {
                prev->left = newNode;
                treeSize++;
            }
            else
            {
                prev->right = newNode;
                treeSize++;
            }
        }
    }
    void insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem)){
        /*treeNode<DataType> *ptr;
        treeNode<DataType> *prev=nullptr;
        treeNode<DataType> *newNode;
        newNode = new treeNode<DataType>;
        newNode -> key = newItem;
        newNode->left = nullptr;
        newNode->right=nullptr;
        if(root == nullptr) {
            root = newNode;
            treeSize++;
        }else{
            ptr = root;
            while(ptr !=nullptr){
                prev = ptr;
                if (ptr->key == newItem)
                {
                    duplicateItemFound(ptr->key, newItem);
                    return;
                }
                else if (ptr->key > newItem)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }//end while
            if (prev->key > newItem)
            {
                prev->left = newNode;
                treeSize++;
            }
            else
            {
                prev->right = newNode;
                treeSize++;
            }
        }*/
        /*if (empty())
        {
            treeNode<DataType> *newNode = new treeNode<DataType>(newItem, nullptr, nullptr);

            root = newNode;
        } else {
            if (find(newItem, processFound))
            {
                duplicateItemFound(currentNode->key, newItem);
                return;
            }
            treeNode<DataType> *newNode = new treeNode<DataType>(newItem, nullptr, nullptr);
            if (currentNode->key > newItem)
            {
                currentNode->left = newNode;
            } else {
                currentNode->right = newNode;
            }
        }
        treeSize++;*/
        insert(newItem);
    }
    void update(DataType &existingItem, const DataType &newItem){
        existingItem <= newItem;
    }
    //traverses through the tree for an item
    void traverse(void (*itemFound)(const DataType& foundItem)) const{
        inorder(root, itemFound);
    }
    void traversePreOrder(void (*itemFound)(const DataType& foundItem)) const{
        preorder(root, itemFound);
    }
    void traversePostOrder(void (*itemFound)(const DataType& foundItem)) const{
        postorder(root, itemFound);
    }
    //traverses through the tree using preorder
    void preorder(treeNode<DataType> *p,void (*itemFound)(const DataType& foundItem)) const
    {
        if (p != nullptr)
        {
            (*itemFound)(p->key);
            preorder(p->left, itemFound);
            preorder(p->right, itemFound);
        }
    }
    //traverses through the tree using postorder
    void postorder(treeNode<DataType> *p,void (*itemFound)(const DataType& foundItem)) const
    {
        if (p != nullptr)
        {
            postorder(p->left, itemFound);
            postorder(p->right, itemFound);
            (*itemFound)(p->key);
        }
    }
    //traverses through the tree using inorder
    void inorder(treeNode<DataType> *p,void (*itemFound)(const DataType& foundItem)) const
    {
        if (p != nullptr)
        {
            inorder(p->left, itemFound);
            (*itemFound)(p->key);
            inorder(p->right, itemFound);
        }
    }
    //destroys node and all of it's child nodes and their subsquent child nodes
    void destroy(treeNode<DataType>* &p){
        if(p != nullptr){
            treeSize--;
            destroy(p->left);
            destroy(p->right);
            delete p;
            p=nullptr;
        }
    }
    //copies two trees
    void copyTree(treeNode <DataType>* &copiedTreeRoot,treeNode <DataType>* otherTreeRoot){
        if(otherTreeRoot==nullptr){//other tree is empty


        }else{

            copiedTreeRoot = new treeNode<DataType>;
            copiedTreeRoot->key = otherTreeRoot->key;
            copyTree(copiedTreeRoot->left, otherTreeRoot->left);
            copyTree(copiedTreeRoot->right, otherTreeRoot->right);
        }
    }
    //overload the assignment operator
    const binarySearchTree<DataType>& operator=(binarySearchTree<DataType>& otherTree);
};

template<class DataType>
const binarySearchTree<DataType> &binarySearchTree<DataType>::operator=(binarySearchTree<DataType> &otherTree) {
    //avoid self copy
    if(this != &otherTree){
        //destroy tree if not empty
        if(root != nullptr)destroy(root);
        //check if other tree is empty
        if(otherTree.root==nullptr)root = nullptr;
            //copy tree
        else copyTree(root, otherTree.root);
        treeSize = otherTree.size();
    }
    return *this;
}

#endif //UNTITLED5_BINARYSEARCHTREE_H
