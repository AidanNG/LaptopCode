#include"addUpdateCommand.h"
#include"bookCommand.h"
#include"command.h"
#include"eraseCommand.h"
#include"eraseUndoRedoCommand.h"
#include"insertUndoRedoCommand.h"
#include"menuList.h"
#include"phoneBook.h"
#include"phoneBookEntry.h"
#include"printCommand.h"
#include"redoCommand.h"
#include"stack.h"
#include"undoCommand.h"
#include"undoRedo.h"
#include <ios>
#include <cstddef>
#include <iomanip>
#include <iostream>

int main(){/*
    // outputs opening statement
    std::cout<<"Starting the Phone Book\n\n";

    // initialize the objects that will be used
    phoneBook book;
    menuList menu("Phone book menu:");

    //Initialize a undoRedo object
    undoRedo undoRedoObject;

    // creates elements of the menu
    char charAddUpdate = 'a';
    char charErase = 'e';
    char charPrint = 'p';
    char charUndo = 'u';
    char charRedo = 'r';
    std::string updateStr = "add/update";
    std::string eraseStr = "erase";
    std::string printStr = "print";
    std::string undoStr = "undo";
    std::string redoStr = "redo";

    // make objects for the commands
    addUpdateCommand updateCommand(book, std::cin, std::cout, undoRedoObject);
    menuItem update(charAddUpdate, updateStr, updateCommand);
    eraseCommand eraseCom(book, std::cin, std::cout, undoRedoObject);
    menuItem erase(charErase, eraseStr, eraseCom);
    printCommand printCom(book, std::cin, std::cout);
    menuItem print(charPrint, printStr, printCom);
    undoCommand undoCom(undoRedoObject);
    menuItem undo(charUndo, undoStr, undoCom);
    redoCommand redoCom(undoRedoObject);
    menuItem redo(charRedo, redoStr, redoCom);

    // creating a menuItem then adding it to the menuList
    menu.add(update);
    menu.add(erase);
    menu.add(print);
    menu.add(undo);
    menu.add(redo);
    menu.start();*/

    return 0;


 };