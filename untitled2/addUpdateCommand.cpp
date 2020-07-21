#include "addUpdateCommand.h"
#include "phoneBook.h"
#include "updateUndoRedoCommand.h"

addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject) :  bookCommand(inStream, outStream), book(bookIn), undoRedoRef(undoRedoObject){}

void addUpdateCommand::execute(){
    //asks and reading in name
    enter = "Enter name to add/update";
    std::string newName = helperIn(enter);
    //asks and reads in phone number
    enter = "Enter phone number";
    std::string newPhoneNumber = helperIn(enter);
    //asks and reads in email
    enter = "Enter e-mail address";
    std::string newEmail = helperIn(enter);
    //checks if the entry exists and updates if it does and adds if it doesn't
    if(book.find(newName)){
        updateUndoRedoCommand* updateUndoRedo = new updateUndoRedoCommand(book, phoneBookEntry(book.ptr->name(), book.ptr->phoneNumber(),book.ptr->email()), phoneBookEntry(newName, newPhoneNumber,newEmail));
        undoRedoRef.addCommand(updateUndoRedo);
        book.insert(newName,newPhoneNumber,newEmail);
        enter= "Updating phone book entry for "+ newName;

    }else{
        //decides which insert command to use
        if(newEmail.empty()){
            book.insert(newName,newPhoneNumber);
        }else{
            book.insert(newName,newPhoneNumber,newEmail);
        }
        enter = "Adding phone book entry for "+ newName;
    }
    helperOut(enter);
}

