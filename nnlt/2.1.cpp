#include <iostream>
using namespace std;
int main()
{
    float a,b,r;
    int chon;
    cout<<"Menu : \n";
    cout<<"1.Tinh S tron.\n";
    cout<<"2.Tinh S hcn.\n";
    cout<<" Moi ban chon: " ;
    cin>>chon;
    switch(chon)
    {
        case 1:
        {
            cout<<"Moi bna nhap r: ";
            cin>>r;
            cout<<"S tron= "<< 3.14*r*r<<endl;
        }
        break;
        case 2:
        {
            cout<<"Nhap chieu dai: ";
            cin>>a;
            cout<<"Nhap chieu rong: ";
            cin>>b;
            cout<<"S hcn= "<< a*b<<endl;
        }
        break;
        default: 
        break;    
    }
}