#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;
class CargoShip: public Ship
{
private:
    int capacity;
public:
    CargoShip(string n, int y, int c);
    int getCapacity() const;
    virtual void print();
};
