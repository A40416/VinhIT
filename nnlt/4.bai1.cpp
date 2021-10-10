#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a,b;
    int chon;
    cout<<"Nhap a: ";
    cin>>a;
    cout<<"Nhap b: ";
    cin>>b;
    cout<<"Menu: \n 1. Tinh thuong a chia b. \n 2. Tinh can bac b cua a\n";
    cout<<"Moi ban chon: ";
    cin>>chon;
    cout<< setprecision(2)<<fixed;
    switch (chon)
    {
        case 1: cout<<"a/b= "<<a/b<<endl;
                break;
        case 2: cout<<"can b cua a= "<< pow (a,1/b)<<endl;
                break;
        default: cout<<"LOI!!!!!!! \n";               
    }
    return 0;
}