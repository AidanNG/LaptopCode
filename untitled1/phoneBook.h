

#ifndef UNTITLED1_PHONEBOOK_H
#define UNTITLED1_PHONEBOOK_H

#include <string>
#include "phoneBookEntry.h"

class phoneBook{
public:
    //first insert function that takes the parameter of an entire phonebook entry
    void insert(const phoneBookEntry &entry);
    //second insert function with parameters, name and number and email
    void insert(const std::string &name, const std::string &number, const std::string &email);
    //third insert function with parameters, name and number
    void insert(const std::string &name, const std::string &number);
    //search for a certain entry and deletes it from the phonebook
    bool erase(std::string name);
    //checks if a certain entry is in the phonebook
    bool find(std::string name);
    //first print function with no parameters
    void print() const;
    //second print function with parameters
    void print(std::ostream &out) const;
    //function used for testing the phonebook print command as it is almost identical to the print command
    void debug(std::ostream &out) const;
    //accessor for the size of the phonebook
    std::size_t size() const;
    //declare phonebook vector in the header file
    typedef std::vector<phoneBookEntry> phoneBookEntryList;
    typedef phoneBookEntryList::iterator iterator;
    typedef phoneBookEntryList::const_iterator const_iterator;
    //save where the beginning of the phonebook is
    iterator begin();
    //save where the end of the phonebook vector is
    iterator end();

private:
    //pointer for navigating the vector
    iterator ptr;

};
#endif //UNTITLED1_PHONEBOOK_H
