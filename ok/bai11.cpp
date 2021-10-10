#include <iostream>
#include <cstdlib>
#include "FeetInches.h"
#include "FeetInches.cpp"
using namespace std;
int main() 
{
  FeetInches tinh1(5, -2);
  FeetInches tinh2(6, 7);

	cout << "obj1: " << tinh1 << endl;
	cout << "obj2: " << tinh2 << endl;

	FeetInches tinh3 = tinh2;
    cout << "obj1: " << tinh1 << endl;
	cout << "obj2: " << tinh2 << endl;
	cout << "obj3: " << tinh3 << endl;

	tinh3 = tinh1.multiply(tinh2);

	cout << "obj1: " << tinh1 << endl;
	cout << "obj2: " << tinh2 << endl;
	cout << "obj3: " << tinh3 << endl;
	
	return 0;
}