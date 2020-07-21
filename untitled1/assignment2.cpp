/*#include "addUpdateCommand.h"
#include "bookCommand.h"
#include "command.h"
#include "eraseCommand.h"
#include "menuList.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "printCommand.h"
#include <vector>
#include <iostream>
//This source file creates the main phone book
int main(){

    std::cout<<"Starting the Phone Book\n\n";
    phoneBook pB;
    //create main menu
    menuList menu("Phone book menu:");
    //create command update
    addUpdateCommand addUpdate(pB, std::cin, std::cout);
    menuItem menuUpdate('a',"add/update",addUpdate);
    //create command erase
    eraseCommand erase(pB, std::cin, std::cout);
    menuItem menuErase('e',"erase",erase);
    //create command print
    printCommand printC(pB, std::cin, std::cout);
    menuItem menuPrint('p',"print",printC);
    //add command update
    menu.add(menuUpdate);
    //add command erase
    menu.add(menuErase);
    //add command print
    menu.add(menuPrint);
    //start the main menu
    menu.start();
    return 0;

}*/

/*
 * assignment2.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Anthony Nguyen
 */
#include <string>
#include <vector>
#include "bookCommand.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "command.h"
#include "printCommand.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "menuList.h"

// main function
int main()
{
    // outputs opening statement
    std::cout<<"Starting the Phone Book\n\n";

    // initialize the objects that will be used
    phoneBook book;
    menuList menu("Phone book menu:");

    // creates elements of the menu
    char charAddUpdate = 'a';
    char charErase = 'e';
    char charPrint = 'p';
    std::string updateStr = "add/update";
    std::string eraseStr = "erase";
    std::string printStr = "print";

    // make objects for the commands
    addUpdateCommand updateCommand(book, std::cin, std::cout);
    menuItem update(charAddUpdate, updateStr, updateCommand);
    eraseCommand eraseCom(book, std::cin, std::cout);
    menuItem erase(charErase, eraseStr, eraseCom);
    printCommand printCom(book, std::cin, std::cout);
    menuItem print(charPrint, printStr, printCom);

    // creating a menuItem then adding it to the menuList
    menu.add(update);
    menu.add(erase);
    menu.add(print);

    menu.start();
    return 0;
}



