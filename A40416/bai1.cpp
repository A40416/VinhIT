#include <iostream>
#include <fstream>
#include<cstdio>
using namespace std;
struct SinhVien
{
    char MaSinhVien[6];
    char HoTen[30];
    int SoTinChi;
    float DiemTB;
};
int main()
{
    int Tong=0;
    int n;
    cout<<"Nhap so sinh vien: ";
    cin>>n;
    SinhVien sv[n];
    for(int i=0; i<n; i++)
    {
        cout<<"--------SV"<<i+1<<"----------\n";
        cout<<"Nhap ma sv: ";
        cin>>sv[i].MaSinhVien;
        cout<<"Nhap ho ten: ";
        cin.ignore();
        gets(sv[i].HoTen);
        cout<<"Nhap so tin chi: ";
        cin>>sv[i].SoTinChi;
        cout<<"Nhap diem trung binh : ";
        cin>>sv[i].DiemTB;

        Tong+=sv[i].SoTinChi;

    }
    cout<<"----------HIEN THI-----------------\n";
    cout<<"So tin chi trung binh cua tat ca sinh vien la: "<<Tong/n<<endl;
    cout<<"Sinh vien co so tin <20 la: \n";
    for(int i=0; i<n; i++)
    {
        if(sv[i].SoTinChi<20)
        {
            cout<<"MSV: "<<sv[i].MaSinhVien<<endl;
            cout<<"Ho Ten: "<<sv[i].HoTen<<endl;
            cout<<"So tin chi: "<<sv[i].SoTinChi<<endl;
            cout<<"Dien trung binh: "<<sv[i].DiemTB<<endl;
        }
    }

    fstream f;
    f.open("SinhVien.dat", ios:: out | ios:: binary );
    f.write(reinterpret_cast<char*>(&sv), sizeof(sv));
    f.close();
}