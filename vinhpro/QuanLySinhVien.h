#ifndef QUANLISINHVIEN_H
#define QUANLISINHVIEN_H
#include <string>
#include "Sinhvien.h"
using namespace std;
class Quanlisinhvien : public Sinhvien
{
    private:
        int n;
        Sinhvien *sv;
    public:
        Quanlisinhvien() : Sinhvien()
        {

        }
        // Quanlisinhvien(int ssv)
        // {
        //     n=ssv;
        //     ssv= new string [n];
        // }
        Quanlisinhvien(int size)
        {
            n=size;
            sv=new Sinhvien[n];
        }
        Quanlisinhvien(int m,Sinhvien a[])
        {
            n=m;
            for(int i=0;i<n;i++)
            {
                sv[i]=a[i];
            }
        }
        void nhap()
        {
            for(int i=0;i<n;i++ )
            {
                cin>>sv[i];
            }
        }
        void xuat()
        {
            for(int i=0;i<n;i++)
            {
                cout<<sv[i];
            }
        }
        // friend istream& operator>>(istream& nhap, Sinhvien &a)
        // {
        //     for(int i=0; i<n; i++)
        //     { 
        //         cout<<"So cmt: ";
        //         nhap>>a.cmt;
        //         cout<<"ho ten : ";
        //         nhap>>a.hoten;
        //         cout<<"Que : ";
        //         nhap>>a.quequan;
        //         cout<<"nam: ";
        //         nhap>>a.namsinh;
        //         cout<<"Msv: ";
        //         nhap>>a.msv;
        //         cout<<"Nghanh: ";
        //         nhap>>a.nghanh;
        //         return nhap;
        //     }
        // }
        // friend ostream& operator<<(ostream& out, Sinhvien &a)
        // {
        //     for(int i=0; i<n; i++)
        //     { 
        //     out<<"so cmt: "<<a.cmt<<endl;
        //     out<<"ho ten: "<<a.hoten<<endl;
        //     out<<"que quan: "<<a.quequan<<endl;
        //     out<<"Nam sinh: "<<a.namsinh<<endl;
        //     out<<"Msv: "<<a.msv<<endl;
        //     out<<"Nghanh: "<<a.nghanh<<endl;
            
        //     return out;
        // }
        // void SapXep()
        // {
        //     string temp1;
        //     int temp2;
        //     for(int i= 0; i<n-1;i++){
        //         for(int j= i+1; j<n; j++){
        //         if (dt[i]<dt[j])
        //         {
        //             temp1=ten[i];
        //             ten[i]=ten[j];
        //             ten[j]=temp1;

        //             temp2=dt[i];
        //             dt[i]=dt[j];
        //             dt[j]=temp2;   
        //         }
        //         }
        //     }
        // }
};


#endif /* QUANLISINHVIEN_H */
