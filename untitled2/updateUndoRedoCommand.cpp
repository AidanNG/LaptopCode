//
// Created by aidan on 10/29/18.
//
#include "updateUndoRedoCommand.h"
updateUndoRedoCommand::updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry):bookRef(book){
    oldEntryRef = oldEntry;
    newEntryRef = newEntry;
}
//execute and unExecute
void updateUndoRedoCommand::execute(){
    //redo
    bookRef.insert(newEntryRef);

}
void updateUndoRedoCommand::unExecute(){
    //undo
    bookRef.insert(oldEntryRef);
}