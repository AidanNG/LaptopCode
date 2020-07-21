#include "redoCommand.h"

redoCommand::redoCommand(undoRedo &undoRedoObject) : undoRedoRef(undoRedoObject){}

void redoCommand::execute(){
    undoRedoRef.redo();
}

