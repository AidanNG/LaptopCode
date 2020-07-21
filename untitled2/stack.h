//
// Created by aidan on 10/29/18.
//

#pragma once

#include <ios>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include "command.h"
class stackEntry{
public:
    friend class stack;
protected:
    stackEntry(command *theCommand, stackEntry *pNext = nullptr);
    virtual ~stackEntry();
    virtual void next(stackEntry *pNext);
    virtual command* data();
    virtual const command* data() const;
    virtual stackEntry* next();
private:
    command* ptrCommand;
    stackEntry* ptrNext;
};

class stack{
public:
    stack();
    stack(const stack &from) = delete;
    stack& operator=(const stack &from) = delete;
    virtual ~stack();
    command* top();
    const command* top() const;
    bool empty() const;
    std::size_t size() const;
    void push(command *newCommand);
    void pop();
    void debug() const;
    void debug(std::ostream &out) const;
private:
    stackEntry* entryPtr;
    std::size_t stackEntries;
};