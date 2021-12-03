#include <iostream>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

using namespace std;

int main() {
    const int NUM_SHIPS = 3;
    Ship *ships[NUM_SHIPS] = {
        new Ship,
        new CruiseShip(2000),
        new CargoShip(900)
    };

    for(int i = 0; i < 3; i++) {
        ships[i]->print();
        cout << endl;
    }
    for(int i = 0; i < 3; i++) {
        delete ships[i];
    }
    system("pause");
    return 0;
}
