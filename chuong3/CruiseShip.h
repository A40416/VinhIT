#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include <string>
#include "Ship.h"

using namespace std;

class CruiseShip : public Ship {
private:
    int maxPass;
public:
    CruiseShip(int maxPass) : Ship("TTT", "1999") {
        this->maxPass = maxPass;   
    } 

    void setMaxPass(int max) {
        maxPass = max;
    }

    int getMaxPass() const{
        return maxPass;
    }

    void print() const {
        cout << "Name: " << this->getName() << endl; 
        cout << "Max Passenger: " << this->getMaxPass() << endl;
    }
};

#endif

