#include <iostream>
#include "stringLinkedList.h"

stringLinkedList::~stringLinkedList(){}
void stringLinkedList::appendNode(string n){
    ListNode *newNode; // To point to a new node
    ListNode *nodePtr; // To move through the list

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->data = n;
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
void stringLinkedList::insertNode(string n){
    ListNode *newNode; // To point to a new node
    ListNode *nodePtr; // To move through the list
    ListNode *previousNode = nullptr;
    newNode = new ListNode;
    newNode->data = n;
    if(!head){
        head = newNode;
        newNode->next = nullptr;
    }else{
        nodePtr = head;
        previousNode = nullptr;
        while(nodePtr != nullptr && nodePtr->data < n){
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
void stringLinkedList::deleteNode(string n){
    ListNode *previousNode = nullptr;
    ListNode *nodePtr;

    if(!head){
        return;
    }
    if (head->data == n){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->data != n){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr){
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
void stringLinkedList::displayList() const{
    ListNode *n = head;
    while(n != nullptr){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";
}

