
//definitons for the base class for a phone book entry
#include <iostream>
#include <string>
#include "phoneBookEntry.h"
//default constructor for empty entries
phoneBookEntry::phoneBookEntry() {
    person = "";
    number = "";
    e = "";
}
//constructor that takes in an entry with no email
phoneBookEntry::phoneBookEntry(const std::string &newName, const std::string &newNumber){
    person = newName;
    number = newNumber;
    e = "";
}
//constructor that takes in all three parameters or name, number, and email
phoneBookEntry::phoneBookEntry(const std::string &newName, const std::string &newNumber,  const std::string &newEmail){
    person = newName;
    number = newNumber;
    e = newEmail;
}
//constructor for a direct phonebook entry
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from){
    person = from.name();
    number = from.phoneNumber();
    e = from.email();

}
//accessor function for name of entry
std::string phoneBookEntry::name() const{
    return person;
}
//accessor function for phone number of entry
std::string phoneBookEntry::phoneNumber() const{
    return number;
}
//accessor function for email of entry
std::string phoneBookEntry::email() const{
    return e;
}
//modifier function for the phone number of an entry
void phoneBookEntry::phoneNumber(const std::string &newNumber){
    number = newNumber;
}
//modifier function for the email of an entry
void phoneBookEntry::email(const std::string &newEmail){
    e = newEmail;
}
bool phoneBookEntry::operator==(const phoneBookEntry &entry) const{
    return name() == entry.name();
}
bool phoneBookEntry::operator!=(const phoneBookEntry &entry) const{
    return name() != entry.name();
}
bool phoneBookEntry::operator<(const phoneBookEntry &entry) const{
    return name() < entry.name();
}
bool phoneBookEntry::operator<=(const phoneBookEntry &entry) const{
    return name() <= entry.name();
}
bool phoneBookEntry::operator>(const phoneBookEntry &entry) const{
    return name() > entry.name();
}
bool phoneBookEntry::operator>=(const phoneBookEntry &entry) const{
    return name() >= entry.name();
}

