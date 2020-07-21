//
// Created by aidan on 10/29/18.
//

#pragma once
#include "command.h"
#include "phoneBookEntry.h"
#include "phoneBook.h"

class updateUndoRedoCommand : public command{
public:
    //constructor
    updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry);
    //execute and unExecute
    virtual void execute();
    virtual void unExecute();

private:
    //phoneBook ref
    phoneBook &bookRef;
    //old phoneBookEntry ref
    phoneBookEntry oldEntryRef;
    //new phoneBookEntry ref
    phoneBookEntry newEntryRef;
};
