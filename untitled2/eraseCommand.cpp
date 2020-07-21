#include "eraseCommand.h"
#include "eraseUndoRedoCommand.h"

eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject) :  bookCommand(inStream, outStream), book(bookIn), undoRedoRef(undoRedoObject){}
void eraseCommand::execute() {
    std::string enter = "Enter name to erase";
    std::string newName = helperIn(enter);
    //determines if it was erased or not and outputs accordingly
    if(book.erase(newName)){
        eraseUndoRedoCommand* eraseUndoRedo = new eraseUndoRedoCommand(book, phoneBookEntry(newName, book.ptr->phoneNumber(),book.ptr->email()));
        undoRedoRef.addCommand(eraseUndoRedo);
        enter = "Phone book entry "+ newName+" was erased";
    }else{
        enter = "Phone book entry "+ newName+" was not erased";
    }
    helperOut(enter);
}

