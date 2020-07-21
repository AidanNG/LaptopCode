//
// Created by aidan on 10/29/18.
//

#include "stack.h"
//stackEntry function definitions
stackEntry::stackEntry(command *theCommand, stackEntry *pNext){
    ptrCommand = theCommand;
    ptrNext = pNext;

}
stackEntry::~stackEntry(){}
void stackEntry::next(stackEntry *pNext){
    ptrNext = pNext;
}
command* stackEntry::data(){
    return ptrCommand;
}
const command* stackEntry::data() const{
    return ptrCommand;
}
stackEntry *stackEntry::next(){
    return ptrNext;
}
//stack function definitions
stack::stack(){
    entryPtr = nullptr;
    stackEntries =0;

}
stack:: ~stack(){
    while(!empty()){
        pop();
    }
}
command* stack::top(){
    if(stackEntries <= 0) return nullptr;
    else return entryPtr->data();
}
const command* stack::top() const{
    if(stackEntries <= 0) return nullptr;
    else return entryPtr->data();
}
bool stack::empty() const{
    return stackEntries <= 0;
}
std::size_t stack::size() const{
    return stackEntries;
}
void stack::push(command *newCommand){
    entryPtr = new stackEntry(newCommand, entryPtr);
    stackEntries++;

}
void stack::pop(){
    //making sure not to pop an empty stack
    if(!empty()){
        stackEntry* ptrNewTop = entryPtr;
        entryPtr = entryPtr->next();

        delete ptrNewTop;

        stackEntries--;
    }
}
void stack::debug() const{

}
void stack::debug(std::ostream &out) const{

}