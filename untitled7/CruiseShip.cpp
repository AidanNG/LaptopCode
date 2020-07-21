#include "CruiseShip.h"

CruiseShip::CruiseShip(string n, int y, int p):Ship(n,y){
passengers = p;
}
int CruiseShip::getPassengers() const{
    return passengers;
}
void CruiseShip::print(){
    cout<<"Cruise Ship Name : "<<getName()<<endl;
    cout<<"# of passengers : "<<passengers<<endl;
}

