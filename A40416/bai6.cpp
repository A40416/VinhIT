#include <iostream>
#include <fstream>
#include <cstdio>
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
    int tong=0;
    double trungbinh;
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    SinhVien a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma sinh vien: ";
        cin >> a[i].MaSinhVien;
        cout << "Nhap ho ten: ";
        cin.ignore();
        //gets(a[i].HoTen);
        cin.getline(a[i].HoTen,30);
        cout << "Nhap so tin chi tich luy: ";
        cin >> a[i].SoTinChi;
        cout << "Nhap diem trung binh : ";
        cin >> a[i].DiemTB;
        tong += a[i].SoTinChi;
    }
    trungbinh = tong / n;
    cout << "----------HIEN THI-----------------\n";
    cout << "So tin chi trung binh cua tat ca sinh vien la: " << trungbinh << endl;
    cout << "Sinh vien co so tin <20 la: \n";
    for (int i = 0; i < n; i++)
    {
        if (a[i].SoTinChi < 20)
        {
            cout << "Ma snh vien: " << a[i].MaSinhVien << endl;
            cout << "Ho Ten: " << a[i].HoTen << endl;
            cout << "So tin chi: " << a[i].SoTinChi << endl;
            cout << "Diem trung binh: " << a[i].DiemTB << endl;
        }
    }

    fstream f;
    f.open("SinhVien.dat", ios::out | ios::binary);
    f.write(reinterpret_cast<char*>(&a), sizeof(a));
    f.close();
}