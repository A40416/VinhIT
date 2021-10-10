#include <iostream>
#include "SortableVector.h"

using namespace std;

int main() {
    const int SIZE = 10;
    SortableVector<int> intTable(SIZE);
    SortableVector<double> doubleTable(SIZE);

    int intArray[SIZE] = {4, 12, 1, 9, 5, 7, 16, 3, 8, 23};
    double doubleArray[SIZE] = {12.3, 13.1, 14.3, 15.7, 16.9, 1.4, 25.4, 8.4, 20.6, 11.7};

    for(int j = 0; j < SIZE; j++) {
        intTable[j] = intArray[j];
        doubleTable[j] = doubleArray[j];
    }
    
    cout << "Value is in intTable: \n";
    for(int j = 0; j < SIZE; j++) {
        cout << intTable[j] << " "; 
    }
    cout << endl;

    cout << "Value is in doubleTable: \n";
    for(int j = 0; j < SIZE; j++) {
        cout << doubleTable[j] << " ";
    }
    cout << endl;

    intTable.sortArray();
    doubleTable.sortArray();

    cout << "Display the value: ";

    cout << "Value is in intTable: \n";
    for(int j = 0; j < SIZE; j++) {
        cout << intTable[j] << " "; 
    }
    cout << endl;

    cout << "Value is in doubleTable: \n";
    for(int j = 0; j < SIZE; j++) {
        cout << doubleTable[j] << " ";
    }
    cout << endl;
    
    return 0;
}
