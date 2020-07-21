#include "bookCommand.h"
#include "phoneBook.h"
#ifndef UNTITLED1_PRINTCOMMAND_H
#define UNTITLED1_PRINTCOMMAND_H
//command for printing the phonebook
class printCommand : public bookCommand{
public:
    //overridden constructor from the bookCommand class for specific print command
    printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
//            :  bookCommand(inStream, outStream), book(bookIn);
//overriden execute that simply prints out the phonebook
    void execute();
//pointer to the phonebook
    phoneBook& book;
private:
    // stores a string for output and input
    std::string enter;
};
#endif //UNTITLED1_PRINTCOMMAND_H
