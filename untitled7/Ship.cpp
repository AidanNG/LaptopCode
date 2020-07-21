#include "Ship.h"

Ship::Ship(string n, int y){
    name= n;
    year = y;
}

Ship::~Ship(){}

int Ship::getYear() const{
    return year;
}
string Ship::getName() const{
    return name;
}
void Ship::print(){
    cout<<"Ship's Name:"<<Ship::getName()<<" and Year built:"<<Ship::getYear()<<endl;
}

