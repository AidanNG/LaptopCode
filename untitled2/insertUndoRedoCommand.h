

#pragma once
#include "command.h"
#include "phoneBookEntry.h"
#include "phoneBook.h"

class insertUndoRedoCommand : public command{
public:
    //constructor
    insertUndoRedoCommand(phoneBook &book, phoneBookEntry newEntry);
    //execute and unexecute
    virtual void execute();
    virtual void unExecute();

private:
    //phoneBook ref
    phoneBook &bookRef;
    //new phoneBookEntry ref
    phoneBookEntry newEntryRef;
};