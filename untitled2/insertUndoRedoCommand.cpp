#include "insertUndoRedoCommand.h"

insertUndoRedoCommand::insertUndoRedoCommand(phoneBook &book, phoneBookEntry newEntry) : bookRef(book){
    newEntryRef = newEntry;
}

void insertUndoRedoCommand::execute() {
    //redo
    bookRef.insert(newEntryRef);
}
void insertUndoRedoCommand::unExecute() {
    //undo
    bookRef.erase(newEntryRef.name());
}

