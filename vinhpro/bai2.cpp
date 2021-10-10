#include <iostream>
#include <string>
#include "Sinhvien.h"
using namespace std;
int main()
{
    Sinhvien a,b;
    cin>> a;    //nhấp tuổi = 18
    cout<<"-------------hi--------------\n";
    cout<<a;

    b=a+1;   
    cout<<b;// in ra all thông tin như a nhưng tuổi = 19
    
    cout<< ++a;   // in ra all thông tin như a nhưng tuổi = 20
}

