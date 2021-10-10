#include <iostream>
using namespace std;
int main()
{
    float monney=100;

    for(int i=0; monney<=200; i++)
    {
        monney*=1.07;
        cout<<"Sau "<<i+1<<" nam, so tien hien co: "<< monney<<endl; 
    }
}