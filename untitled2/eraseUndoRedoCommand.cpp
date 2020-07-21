#include "eraseUndoRedoCommand.h"

eraseUndoRedoCommand::eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry): bookRef(book) {
    oldEntryRef = oldEntry;
}

void eraseUndoRedoCommand::execute() {
    //redo
    bookRef.erase(oldEntryRef.name());

}
void eraseUndoRedoCommand::unExecute() {
    //undo
    bookRef.insert(oldEntryRef);
}

