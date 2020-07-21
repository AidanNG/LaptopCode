#include "undoCommand.h"

undoCommand::undoCommand(undoRedo &undoRedoObject) : undoRedoRef(undoRedoObject){}

void undoCommand::execute(){
    undoRedoRef.undo();
}

