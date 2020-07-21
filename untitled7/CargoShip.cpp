#include "CargoShip.h"

CargoShip::CargoShip(string n, int y, int c):Ship(n,y){

capacity = c;
}
int CargoShip::getCapacity() const{
    return capacity;
}
void CargoShip::print(){
    cout<<"Cargo Ship Name : "<<getName()<<endl;
    cout<<"Capacity in tons : "<<capacity<<endl;
}

