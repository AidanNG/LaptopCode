

#pragma once

#include "command.h"
#include "undoRedo.h"

class undoCommand : public command{
public:
    //constructor
    undoCommand(undoRedo &undoRedoObject);

    //execute
    virtual void execute();

private:
    //undoRedo ref
    undoRedo &undoRedoRef;
};