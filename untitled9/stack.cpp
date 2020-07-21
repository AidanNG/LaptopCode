#include <iostream>
using namespace std;

const int SIZE = 10;

template <class StackType> class stack {
    StackType stck[SIZE];
    int tos;

public:
    stack() {
        tos = 0;
    }
    void push(StackType ob)
    {
        if(tos==SIZE) {
            cout << "Stack is full.\n";
            return;
        }
        stck[tos] = ob;
        tos++;
    }

    StackType pop()
    {
        if(tos==0) {
            cout << "Stack is empty.\n";
            return 0; // return null on empty stack
        }
        tos--;
        return stck[tos];
    }
};

