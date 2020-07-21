#include <string>
#include "phoneBookEntry.h"
#include "phoneBook.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ostream>
//declare phonebook vector in the source file
phoneBook::phoneBookEntryList entries;
//first insert function that takes the parameter of an entire phonebook entry
void phoneBook::insert(const phoneBookEntry &entry){
    //checks if the name is there and updates the current entry if it is
    if(find(entry.name())){
        (*ptr) = entry;
    }else{
        entries.push_back(phoneBookEntry(entry));
    }

}
//second insert function with parameters, name and number and email
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email){
    //checks if the name is there and updates the current entry if it is
    if(find(name)){
        (*ptr).phoneNumber(number);
        (*ptr).email(email);
    }else{
        entries.push_back(phoneBookEntry(name,number,email));
    }

}
//third insert function with parameters, name and number
void phoneBook::insert(const std::string &name, const std::string &number){
    //checks if the name is there and updates the current entry if it is
    if(find(name)){
        (*ptr).phoneNumber(number);

    }else{
        entries.push_back(phoneBookEntry(name,number));
    }
}
//search for a certain entry and deletes it from the phonebook
bool phoneBook::erase(std::string name){
    int i=0;
    for (ptr= begin(); ptr<end();ptr++) {

        if((*ptr).name() == name){
            entries.erase(ptr);
            return true;
        }
        i++;
    }
    return false;
}
//checks if a certain entry is in the phonebook
bool phoneBook::find(std::string name){
    bool found = false;
    //loop through the phone book for a ceratin entry
    for (ptr = begin(); ptr < end(); ptr++) {

        if ((*ptr).name() == name) {
            return true;


        }
    }
    return found;
}
//first print function with no parameters
void phoneBook::print() const{
    //create header for the print menu
    std::cout<< "Name:                         Phone Number:   E-Mail:\n";
    for (auto &entrie : entries) {//loop through all the entries
        int spaces = static_cast<int>(31 - entrie.name().length());//number of spaces needed to make sure all then entries stay in line
        //print name
        std::cout<< entrie.name();
        //add spaces
        for(int j =0; j< spaces;j++){
            std::cout<<" ";
        }
        //print out phone number
        if(entrie.phoneNumber().length() ==12) {//check if the size of the phone number is standard length
            std::cout << entrie.phoneNumber() << "    " << entrie.email() << "\n";
        }else{
            std::cout << entrie.phoneNumber();
            spaces = static_cast<int>(16 - entrie.name().length());//number of spaces needed to make sure all then entries stay in line
            for(int j =0; j< spaces;j++){
                std::cout<<" ";
            }
            //print out email
            std::cout<<entrie.email() << "\n";
        }
    }
}
//second print function with parameters
void phoneBook::print(std::ostream &out) const{
    //create header for the print menu
    out<< "Name:                          Phone Number:   E-Mail:\n";
    for (auto &entrie : entries) {//loop through all the entries
        int spaces = static_cast<int>(31 - entrie.name().length());//number of spaces needed to make sure all then entries stay in line
        //print name
        out<< entrie.name();
        //add spaces
        for(int j =0; j< spaces;j++){
            out<<" ";
        }
        //print phone number
        if(entrie.phoneNumber().length() ==12) {//check if the size of the phone number is standard length
            out << entrie.phoneNumber() << "    " << entrie.email() << "\n";
        }else{
            out << entrie.phoneNumber();
            spaces = static_cast<int>(16 - entrie.name().length());//number of spaces needed to make sure all then entries stay in line
            for(int j =0; j< spaces;j++){
                out<<" ";
            }
            //print out email
            out<<entrie.email() << "\n";
        }
    }
}
//function used for testing the phonebook print command as it is almost identical to the print command
void phoneBook::debug(std::ostream &out) const{
    //create header for the print menu
    out<< "Name:                         Phone Number:   E-Mail:\n";
    for (auto &entrie : entries) {//loop through all the entries

        int spaces = static_cast<int>(31 - entrie.name().length());//number of spaces needed to make sure all then entries stay in line
        out<< entrie.name();//output name
        for(int j =0; j< spaces;j++){
            out<<" ";
        }
        //output the phone number and email
        out<< entrie.phoneNumber()<< "   "<< entrie.email()<<"\n";
    }
}
//accessor for the size of the phonebook
std::size_t phoneBook::size() const{
    return entries.size();
}
//save where the beginning of the phonebook is
phoneBook::iterator phoneBook::begin() {
    return entries.begin();
}
//save where the end of the phonebook vector is
phoneBook::iterator phoneBook::end() {
    return entries.end();
}

