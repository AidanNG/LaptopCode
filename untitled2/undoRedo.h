

#pragma once

#include "command.h"
#include "stack.h"

class undoRedo {
public:
    undoRedo();
    virtual ~undoRedo();
    virtual void addCommand(command *newCommand);
    // note that undoRedo will delete the command in its destructor
    virtual void undo();
    virtual void redo();
private:
    stack *re;
    stack *un;
};
