#include "bookCommand.h"
#include "phoneBook.h"
#ifndef UNTITLED1_ADDUPDATECOMMAND_H
#define UNTITLED1_ADDUPDATECOMMAND_H


//command to update/add an entry
class addUpdateCommand : public bookCommand{
public:
    //overridden constructor from the bookCommand class for specific insert command
    addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
//            :  bookCommand(inStream, outStream), book(bookIn);
//overridden execute command that inserts/updates the target
    void execute();
//pointer for the phonebook
    phoneBook& book;
private:
    // stores a string for output and input
    std::string enter;
};
#endif //UNTITLED1_ADDUPDATECOMMAND_H
