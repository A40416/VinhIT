#include <iostream>
#include <fstream>
using namespace std;
void NhapDiem(float &diem1,float &diem2,float &diem3,float &diem4,float &diem5)
{
    do{
        cout<<"Nhap diem1: ";
        cin>>diem1;
        cout<<"Nhap diem2: ";
        cin>>diem2;
        cout<<"Nhap diem3: ";
        cin>>diem3;
        cout<<"Nhap diem4: ";
        cin>>diem4;
        cout<<"Nhap diem5: ";
        cin>>diem5;
    }while((diem1<0||diem1>10)||(diem2<0||diem2>10)||(diem3<0||diem3>10)||(diem4<0||diem4>10)||(diem5<0||diem5>10));
}
float TimMin(float diem1,float diem2,float diem3,float diem4,float diem5)
{
    float min=diem1;
    if(diem2<min)
        min=diem2;
    if(diem3<min)
        min=diem3;
    if(diem4<min)
        min=diem4;
    if(diem5<min)
        min=diem5;        
    return min;
}
float TinhTB(float diem1,float diem2,float diem3,float diem4,float diem5)
{
    int min=TimMin(diem1,diem2,diem3,diem4,diem5);
    return (diem1+diem2+diem3+diem4+diem5-min)/4;
}
void InDiemTB(int n,float diem1,float diem2,float diem3,float diem4,float diem5 )
{

    float TB;
    ofstream f;
    f.open("DiemTB.txt");
    for(int i=0; i<n; i++)
    { 
        cout<<"SV "<<i+1<<endl;
        NhapDiem(diem1,diem2,diem3,diem4,diem5);
        TB= TinhTB(diem1,diem2,diem3,diem4,diem5);
        f<<TB<<endl;
    }
    f.close();
}
int main()
{
    float diem1,diem2,diem3,diem4,diem5;
    int n;
    cout<<"Nhap so SV: ";
    cin>>n;
    InDiemTB(n,diem1,diem2,diem3,diem4,diem5);
    return 0;
}