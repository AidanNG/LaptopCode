/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <cstddef>

#include "linkedList.h"

template<class DataType>
class orderedLinkedList
{
public:
    typedef linkedList<DataType>              unorderedLinkedList;
    typedef std::bidirectional_iterator_tag	iterator_category;
    typedef std::ptrdiff_t 					      difference_type;
    typedef std::size_t						      size_type;
    typedef typename unorderedLinkedList::iterator  iterator;
    typedef const iterator	  	               const_iterator;
private:
    // we are making use of the DoubleLinkedList class
    unorderedLinkedList list;
public:
    // default constructor
    orderedLinkedList(){}
    // copy constructor
    orderedLinkedList(const orderedLinkedList &other);
    // assignment operator
    const orderedLinkedList& operator=(const orderedLinkedList &other){
        orderedLinkedList list(other);
        return list;
    }
    // destructor
    virtual ~orderedLinkedList();
    // iterators
    iterator begin()
    {
        return list.begin();
    }

    iterator end()
    {
        return list.end();
    }

    const_iterator begin() const
    {
        return list.begin();
    }

    const_iterator end() const
    {
        return list.end();
    }

    // number of items in the list
    virtual std::size_t size() const;
    // is the list empty (true) or does it have entries (false)
    virtual bool empty() const;
    // print the items in the list
    virtual void print() const;
    // display the contents of the list to the ostream&
    virtual void print(std::ostream &out) const;
    // display debug information on the passed in ostream
    virtual void debug(std::ostream &out) const;
    // find the element and return an interator for it
    virtual iterator find(const DataType &existingItem){
        return list.find(existingItem);
    }
    // remove the node equal to currentItem
    virtual bool erase(const DataType &currentItem);
    // remove the node by address existingNode
    virtual iterator erase(iterator iter){
        list.erase(iter);
    }
    // insert the new item into the list (in sorted order)
    // a duplicate entry will be ignored
    virtual void insert(const DataType &newItem);
    // get the last entry
    iterator back()
    {
        return list.back();
    }

    const_iterator back() const
    {
        return list.back();
    }
};
// Your implementation code goes here
template<class DataType>
std::size_t orderedLinkedList<DataType>::size() const {
    return list.size();
}

template<class DataType>
bool orderedLinkedList<DataType>::empty() const {
    return list.empty();
}

template<class DataType>
void orderedLinkedList<DataType>::print() const {
    print(std::cout);
}

template<class DataType>
void orderedLinkedList<DataType>::print(std::ostream &out) const {
    list.print(out);
}

template<class DataType>
void orderedLinkedList<DataType>::debug(std::ostream &out) const {
    list.debug(out);
}

template<class DataType>
bool orderedLinkedList<DataType>::erase(const DataType &currentItem) {
    return list.erase(currentItem);
}


template<class DataType>
orderedLinkedList<DataType>::orderedLinkedList(const orderedLinkedList &other) {
    iterator listIter = back();
    while(!empty())
    {
        erase(listIter);
        listIter--;
    }
    bool done = false;
    for (auto listIter = other.back(); !done; listIter--)
    {
        if (listIter != other.end())
        {
            list.push_front(*listIter);
            if (listIter == other.begin())
            {
                done = true;
            }
        }
    }
}

template<class DataType>
orderedLinkedList<DataType>::~orderedLinkedList() {
    if (!empty()) {
        iterator listIter = back();
        while(!empty())
        {
            erase(listIter);
            listIter--;
        }
    }
}

template<class DataType>
void orderedLinkedList<DataType>::insert(const DataType &newItem) {
    if(empty()){
        list.push_front(newItem);
    }else if(find(newItem)==nullptr){
        bool fin = false;
        for (auto listIter = begin(); !fin; listIter++) {
            if(listIter!=end()){
                if (listIter == begin() && (*listIter > newItem)) {
                    list.push_front(newItem);
                    fin = true;
                }else if(*listIter > newItem){
                    list.insert_before(listIter,newItem);
                    fin=true;
                }else if(listIter==back()){
                    list.push_back(newItem);
                    fin = true;
                }
            }
        }
    }
}


#endif /* ORDEREDLINKEDLIST_H_ */
