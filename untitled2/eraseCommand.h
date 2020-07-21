#include "undoRedo.h"
#include "command.h"
#include "bookCommand.h"
#include "phoneBook.h"
class eraseCommand : bookCommand{
public:
    eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject);
    void execute();
    phoneBook& book;

private:
    std::string enter;
    undoRedo& undoRedoRef;
};

#pragma once
