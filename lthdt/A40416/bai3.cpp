#include <iostream>
#include "Stopwatch.h"
using namespace std;
int main()
{
    int h, m, s;
    do
    {
        cout<<"Nhap gio phut giay: ";
        cin>>h>>m>>s;
    }while(h<0&&h>1000000&&m<0&&m>1000000&&s<0&&s<1000000);
    Stopwatch time(h,m,s);
    time.print();

    cout<<"So giay = "<<time.getSecond()<<endl;

    int giay,gio,phut;
    cout<<"Nhap so giay: ";
    cin>>giay;
    gio=giay/3600;
    phut=(giay-(gio*3600))/60;
    giay=giay-(gio*3600)-(phut*60);
    Stopwatch time1(gio,phut, giay);
    time1.print();





}