

#ifndef UNTITLED1_PHONEBOOKENTRY_H
#define UNTITLED1_PHONEBOOKENTRY_H

#include <string>
#include <vector>
//base class for a phone book entry
class phoneBookEntry{
private:
    //declares name of person variable
    std::string person;
    //declares phone number variable
    std::string number;
    //declares email variable
    std::string e;
public:
    //default constructor for empty entries
    phoneBookEntry();
    //constructor that takes in an entry with no email
    phoneBookEntry(const std::string &name, const std::string &number);
    //constructor that takes in all three parameters or name, number, and email
    phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email);
    //constructor for a direct phonebook entry
    phoneBookEntry(const phoneBookEntry &from);
    //accessor function for name of entry
    std::string name() const;
    //accessor function for phone number of entry
    std::string phoneNumber() const;
    //accessor function for email of entry
    std::string email() const;
    //modifier function for the phone number of an entry
    void phoneNumber(const std::string &newNumber);
    //modifier function for the email of an entry
    void email(const std::string &newEmail);

};
#endif //UNTITLED1_PHONEBOOKENTRY_H
