#include <iostream>
#include <vector>
#include "linkedList.h"
#include "linkedList.cpp"
using namespace std;
int main() {
    linkedList<int> mylist;
    // Add few items to the end of LinkedList
    mylist.add(1);
    mylist.add(1);
    mylist.add(3);
    cout << "Traversing LinkedList through Iterator" << endl;
    for ( linkedList<int>::Iterator iterator = mylist.begin(); iterator != mylist.end(); iterator++){
        cout << *iterator << " ";
    }
    return 0;
}