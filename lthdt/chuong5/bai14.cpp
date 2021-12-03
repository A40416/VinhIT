#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Bins
{
    string part;
    int num_part;
    Bins( string p, int nb)
    {
        part=p;
        num_part=nb;
    }
};
void add(Bins thung[],int choice)
{
    int a;
    cout<<"nhap part muon them: "<<endl;
    cin>>a;
    while (a<0)
    {
        cout<<"moi nhap lai: "<<endl;
        cin>>a;
    }
    while (thung[choice-1].num_part+a > 30)
    {
        cout<<"so phai luon nho hon 30, moi nhap lai"<<endl;
        cin>>a;
    }
    if (thung[choice-1].num_part+a <= 30)
    {
        thung[choice-1].num_part+= a;
    }
}
void remove(Bins thung[],int choice)
{
    int a = 0;
    cout<<"so luong xoa: "<<endl;
    cin>>a;
    while (a < 0)
    {
        cout<<"moi nhap lai: "<<endl;
        cin>>a;
    }
    while (thung[choice-1].num_part - a < 0)
    {
        cout<<"moi nhap lai: "<<endl;
        cin>>a;
    }
    if (thung[choice-1].num_part-a >= 0)
    {
        thung[choice-1].num_part-= a;
    }
}
void Print(Bins a[])
{
    cout<<"STT"<<setw(15)<<"BINSNAME"<<setw(12)<<"NUMBINS"<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<i+1<<setw(17)<<a[i].part<<setw(10)<<a[i].num_part<<endl;
    }
}
int main()
{
    const int NUM=10;
    Bins vinh[NUM] ={{"Valve",10},{"Bearing",5},{"Bushing",15},{"Coupling",21 },{"Flange",7},{"Gear",5},{"Gear Housing",5},{"Vacuum Gripper", 25 },{"Cable",18},{"Rod",12}};
    Print(vinh);
    add(vinh,4);
    Print(vinh);
    remove(vinh,9);
    Print(vinh);

    return 0;
}