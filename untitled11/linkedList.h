#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class linkedList{
private:
    struct ListNode{
        T data;
        ListNode *next;
        ListNode& operator =(const ListNode& rhs){
            this->data = rhs->data;
            this->next = rhs->next;
            return *this;
        }
    };
    static ListNode *head;

public:
    class Iterator;
    Iterator begin(){return Iterator(head);}
    Iterator end(){return Iterator(nullptr);}
    linkedList() noexcept{head = nullptr;}
    ~linkedList(){}
    struct ListNode *getTail(ListNode* nodePtr){
        while (nodePtr != NULL && nodePtr->next != NULL)
            nodePtr = nodePtr->next;
        return nodePtr;}
    void quicksort();
    ListNode* quicksortR(ListNode*,ListNode*);
    ListNode* partition(struct ListNode*, struct ListNode*, struct ListNode**, struct ListNode**);
    void add(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
    class Iterator{
    public:
        Iterator() noexcept :
                current (head) { }

        Iterator(const ListNode* pNode) noexcept :
                current (pNode) { }

        Iterator& operator=(ListNode* pNode) {
            this->current = pNode;
            return *this;
        }

        // allow iterator to increment prefix
        Iterator& operator++() {
            if (current)
                current = current->next;
            return *this;
        }
        //allow iterator to increment postfix
        Iterator operator++(int) {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
        bool operator!=(const Iterator& iterator) { return current != iterator.current; }
        int operator*() { return current->data; }
    private:
        const ListNode *current;
    };
};



#pragma once