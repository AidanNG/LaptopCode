

#pragma once
#include "command.h"
#include "undoRedo.h"

class redoCommand : public command{
public:
    //constructor
    redoCommand(undoRedo &undoRedoObject);

    //execute
    virtual void execute();

private:
    //undoRedo ref
    undoRedo &undoRedoRef;
};