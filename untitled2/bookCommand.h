#pragma once

#include "command.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
//bookCommand that inherits from command for creating commands in the phonebook menu
class bookCommand : public command{
protected:
    //input
    std::istream &in;
    //output
    std::ostream &out;
    //helps output the line in the derived class
    void helperOut(std::string line);
    //helps read in the line in the derived classes
    std::string helperIn(std::string line);
public:
    //constructor for creating commands
    bookCommand(std::istream &in, std::ostream &out);
    virtual void execute() =0;
    virtual ~bookCommand(){};

};


