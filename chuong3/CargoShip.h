#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include <string>
#include "Ship.h"
using namespace std;
class CargoShip : public Ship {
private:
    int maxCapacity;
public:
    CargoShip(int maxCapacity) : Ship("UUU", "2020") {
        this->maxCapacity = maxCapacity;
    }

    void setCargoCapacity(int c) {
        maxCapacity = c;
    }

    int getCargoCapacity() const{
        return maxCapacity;
    }

    void print() const{
        cout << "Name: " << this->getName() << endl;
        cout << "Max Cargocity: " << this->getCargoCapacity() << endl;
    }
};

#endif


