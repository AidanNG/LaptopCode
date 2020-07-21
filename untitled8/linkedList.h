#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
template <typename T>
class linkedList{
    class ListNode;
private:
    class ListNode{
        T data;
        ListNode *next;
        friend class linkedList;
    };
    static ListNode *head;

public:
    class Iterator;
    Iterator begin(){return Iterator(head);}
    Iterator end(){return Iterator(nullptr);}
    linkedList<T>() noexcept{head = nullptr;}
    ~linkedList<T>(){}
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

