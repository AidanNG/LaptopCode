#include "addUpdateCommand.h"
#include "bookCommand.h"
//overridden constructor from the bookCommand class for specific insert command
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
        :  bookCommand(inStream, outStream), book(bookIn)
{
    // any other code you may need
}
void addUpdateCommand::execute() {
    //asks and reading in name
    enter = "Enter name to add/update";
    std::string newName = helperIn(enter);
    //asks and reads in phone number
    enter = "Enter phone number";
    std::string newPhoneNumber = helperIn(enter);
    //asks and reads in email
    enter = "Enter e-mail address";
    std::string newEmail = helperIn(enter);
    //checks if the entry exists and updates if it does and adds if it doesn't
    if(book.find(newName)){
        book.insert(newName,newPhoneNumber,newEmail);
        enter= "Updating phone book entry for "+ newName;

    }else{
        //decides which insert command to use
        if(newEmail.empty()){
            book.insert(newName,newPhoneNumber);
        }else{
            book.insert(newName,newPhoneNumber,newEmail);
        }
        enter = "Adding phone book entry for "+ newName;
    }
    helperOut(enter);
}

