#include "bookCommand.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

//helps output the line in the derived class
void bookCommand::helperOut(std::string line){
    out<< line<< "\n";
}
//helps read in the line in the derived classes
std::string bookCommand::helperIn(std::string line){
    std:: string input;
    std::cout<< line<< "\n";
    std::getline(in,input);
    return input;
}

//constructor for creating commands
bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream)
        :  in(inStream), out(outStream)
{

}

