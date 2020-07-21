#include <iostream>
using namespace std;

const int SIZE = 10;

template <class StackType>
class stack {
    StackType stck[SIZE];
    int size;

public:
    stack() {
        size = 0;
    }
    bool isEmpty(){
        return size==0;
    }

    void push(StackType ob)
    {
        if(size==SIZE) {
            cout << "Stack is full.\n";
            return;
        }
        stck[size] = ob;
        size++;
    }

    StackType pop()
    {
        if(size==0) {
            cout << "Stack is empty.\n";
            return 0; // return null on empty stack
        }
        size--;
        return stck[size];
    }
    StackType peek(){
        return stck[size];
    }
};

