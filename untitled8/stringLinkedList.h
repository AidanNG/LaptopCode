#include <iostream>
using namespace std;
class stringLinkedList{
private:
    struct ListNode{
        string data;
        ListNode *next;
    };
    ListNode *head;
public:
    stringLinkedList() {head = NULL;}
    ~stringLinkedList();
    void appendNode(string);
    void insertNode(string);
    void deleteNode(string);
    void displayList() const;

};
