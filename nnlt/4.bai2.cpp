#include <iostream>
using namespace std;
void NhapDiem(float &a)
{
    do
    {
        cout<<"Nhap diem: ";
        cin>>a;
    } while (a<0||a>10);
}    
float TrungBinh(float d1, float d2, float d3, float d4)
{
    float Total=d1+d2+d3+d4;
    float min = d1;
    if (d2 < min)
        min = d2;
    if (d3 < min)
        min = d3;
    if (d4 < min)
        min = d4;
    return (Total-min)/3;
}
int main()
{
    float diem1,diem2,diem3,diem4;
    NhapDiem(diem1);
    NhapDiem(diem2);
    NhapDiem(diem3);
    NhapDiem(diem4);
    cout<<"Diem trung binh hoc sinh nay la: "<< TrungBinh(diem1,diem2,diem3,diem4)<<endl;

}