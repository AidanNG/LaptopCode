#include <iostream>
using namespace std;
class integerLinkedList{
private:
    struct ListNode{
        int data;
        ListNode *next;
    };
    ListNode *head;
public:
    integerLinkedList() {head = nullptr;}
    ~integerLinkedList();
    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    void displayList() const;

};


#pragma once
