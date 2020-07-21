#include <iostream>
#include "integerLinkedList.h"

integerLinkedList::~integerLinkedList(){}
void integerLinkedList::appendNode(int num){
    ListNode *newNode; // To point to a new node
    ListNode *nodePtr; // To move through the list

     // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->data = num;
    newNode->next = nullptr;

     // If there are no nodes in the list
     // make newNode the first node.
     if (!head)
         head = newNode;
     else // Otherwise, insert newNode at end.
     {
         // Initialize nodePtr to head of list.
         nodePtr = head;

         // Find the last node in the list.
         while (nodePtr->next)
             nodePtr = nodePtr->next;

         // Insert newNode as the last node.
         nodePtr->next = newNode;
     }

}
void integerLinkedList::insertNode(int num){
    ListNode *newNode; // To point to a new node
    ListNode *nodePtr; // To move through the list
    ListNode *previousNode = nullptr;
    newNode = new ListNode;
    newNode->data = num;
    if(!head){
        head = newNode;
        newNode->next = nullptr;
    }else{
        nodePtr = head;
        previousNode = nullptr;
        while(nodePtr != nullptr && nodePtr->data < num){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(previousNode == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        }else{
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
void integerLinkedList::deleteNode(int num){
    ListNode *previousNode = nullptr;
    ListNode *nodePtr;

    if(!head){
        return;
    }
    if (head->data == num){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->data != num){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr){
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
void integerLinkedList::displayList() const{
    ListNode *n = head;
    while(n != nullptr){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";
}
