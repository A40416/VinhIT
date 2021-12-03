#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

using namespace std;

class Ship {
private:
    string name;
    string year;
public:
    Ship(string n = "VVV", string y = "1980") {
        name = n;
        year = y;
    }

    void setName(string n) {
        name = n;
    }

    void setYear(string y) {
        year = y;
    }

    string getName() const{
        return name;
    }

    string getYear() const{
        return year;
    }

    virtual void print() const{
        cout << "Name: " << this->getName() << endl;
        cout << "Build year: " << this->getYear() << endl;
    }
};

#endif
