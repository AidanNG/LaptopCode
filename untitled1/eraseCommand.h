#include "bookCommand.h"
#include "phoneBook.h"

#ifndef UNTITLED1_ERASECOMMAND_H
#define UNTITLED1_ERASECOMMAND_H
//command to erase an entry
class eraseCommand : public bookCommand{

public:
    //overridden constructor from the bookCommand class for specific erase command
    eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
//            :  bookCommand(inStream, outStream), book(bookIn);
//overridden execute command that erases the target
    void execute();
//pointer for the phonebook
    phoneBook& book;
private:
    // stores a string for output and input
    std::string enter;
};
#endif //UNTITLED1_ERASECOMMAND_H
