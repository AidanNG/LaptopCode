#include <iostream>
#include "linkedList.h"
template <typename T>
typename linkedList<T>::ListNode* linkedList<T>::head = nullptr;

template <typename T>
void linkedList<T>::add(T num){
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
template <typename T>
void linkedList<T>::insertNode(T num){
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
template <typename T>
void linkedList<T>::deleteNode(T num){
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
template <typename T>
void linkedList<T>::displayList() const{
    ListNode *n = head;
    while(n != nullptr){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";
}

template <typename T>
typename linkedList<T>::ListNode* linkedList<T>::quicksortR(ListNode* pivHead, ListNode* pivEnd) {
    if (!pivHead || pivHead == pivEnd) return pivHead;
    ListNode* nHead = NULL, *nEnd = NULL;
    ListNode *pivot = partition(pivHead, pivEnd, &nHead, &nEnd);
    if (nHead != pivot) {
        ListNode* temp = nHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;
        nHead = quicksortR(nHead, temp);
        temp = getTail(nHead);
        temp->next = pivot;
    }
    pivot->next = quicksortR(pivot->next, nEnd);
    return nHead;
}
template <typename T>
typename linkedList<T>::ListNode* linkedList<T>::partition(struct ListNode* pivHead, struct ListNode* pivEnd, struct ListNode** nHead, struct ListNode** nEnd) {
    ListNode *pivot = pivEnd;
    ListNode *prev = NULL, *curr = pivHead, *tail = pivot;
    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*nHead == NULL) *nHead = curr;
            prev = curr;
            curr = curr->next;
        }else{
            if (prev) prev->next = curr->next;
            //swap
            ListNode *temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    if (*nHead == NULL) *nHead = pivot;
    *nEnd = tail;
    return pivot;
}
template <typename T>
void linkedList<T>::quicksort() {
    head = quicksortR(head, getTail(head));

}


