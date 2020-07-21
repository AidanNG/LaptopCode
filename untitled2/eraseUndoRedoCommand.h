

#pragma once
#include "command.h"
#include "phoneBookEntry.h"
#include "phoneBook.h"
class eraseUndoRedoCommand : public command{
public:
    //constructor
    eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry);
    //execute and unExecute

    virtual void execute();
    virtual void unExecute();

private:
    //phoneBook ref
    phoneBook &bookRef;
    //old phoneBookEntry ref
    phoneBookEntry oldEntryRef;
};