#include "printCommand.h"
#include <iostream>
//command for printing the phonebook


//overridden constructor from the bookCommand class for specific print command
printCommand::printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
    :  bookCommand(inStream, outStream), book(bookIn) {}
    //overriden execute that simply prints out the phonebook
    void printCommand::execute(){
    book.print(out);
}



