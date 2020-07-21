#include <iostream>
#include <string>
using namespace std;
class Ship{
private:
    string name;
    int year;
public:
    //Constructor
    Ship(string n, int y);
    //Deconstructor
    ~Ship();
    int getYear() const;
    string getName() const;
    virtual void print();

};
#pragma once
