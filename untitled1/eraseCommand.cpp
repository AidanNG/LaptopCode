#include "eraseCommand.h"
//overridden constructor from the bookCommand class for specific erase command
eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
           :  bookCommand(inStream, outStream), book(bookIn){}
//overridden execute command that erases the target
void eraseCommand::execute(){
    std::string enter = "Enter name to erase";
    std::string newName = helperIn(enter);
    //determines if it was erased or not and outputs accordingly
    if(book.erase(newName)){

        enter = "Phone book entry "+ newName+" was erased";
    }else{
        enter = "Phone book entry "+ newName+" was not erased";
    }
    helperOut(enter);
}

