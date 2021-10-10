#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "Nguoi.h"
#include <string>
using namespace std;
class Sinhvien : public Nguoi
{
    private:
        string msv;
        string nghanh;
    public:
        Sinhvien() 
        {
           
        }
        Sinhvien(string _cmt, string ten, string que, int nam, string ma, string nganh): Nguoi(_cmt,ten,que,nam)
        {
            msv=ma;
            nghanh=nganh;
        }
        friend istream& operator>>(istream& nhap, Sinhvien &a)
        {
            cout<<"So cmt: ";
            nhap>>a.cmt;
            cout<<"ho ten : ";
            nhap>>a.hoten;
            cout<<"Que : ";
            nhap>>a.quequan;
            cout<<"nam: ";
            nhap>>a.namsinh;
            cout<<"Msv: ";
            nhap>>a.msv;
            cout<<"Nghanh: ";
            nhap>>a.nghanh;
            return nhap;
        }
        friend ostream& operator<<(ostream& out, Sinhvien &a)
        {
            out<<"so cmt: "<<a.cmt<<endl;
            out<<"ho ten: "<<a.hoten<<endl;
            out<<"que quan: "<<a.quequan<<endl;
            out<<"Nam sinh: "<<a.namsinh<<endl;
            out<<"Msv: "<<a.msv<<endl;
            out<<"Nghanh: "<<a.nghanh<<endl;
            
            return out;
        }

};
#endif /* SINHVIEN_H */
