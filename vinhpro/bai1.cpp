#include <iostream>
#include <string>
#include "Nguoi.h"
using namespace std;
int main()
{
    Nguoi a;
    cin>>a;
    cout<<"-------------hi--------------\n";
    cout<<a;
    cout<<"Tuoi: "<<a.tinhTuoi()<<endl;
}