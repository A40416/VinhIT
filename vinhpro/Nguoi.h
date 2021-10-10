#ifndef NGUOI_H
#define NGUOI_H
#include <string>
using namespace std;
class Nguoi
{
    protected:
        string cmt;
        string hoten;
        string quequan;
        int namsinh;
    public:
    Nguoi()
    {
       
    }   
    Nguoi(string _cmt, string ten, string que, int nam) 
    {
        cmt=_cmt;
        hoten=ten;
        quequan=que;
        namsinh=nam;
    }
    friend istream& operator>>(istream& nhap, Nguoi &a)
    {
        cout<<"So cmt: ";
        nhap>>a.cmt;
        cout<<"ho ten : ";
        nhap>>a.hoten;
        cout<<"Que : ";
        nhap>>a.quequan;
        cout<<"nam: ";
        nhap>>a.namsinh;
        
        return nhap;
    }
    friend ostream& operator<<(ostream& out, Nguoi &a)
    {
        out<<"so cmt: "<<a.cmt<<endl;
        out<<"ho ten: "<<a.hoten<<endl;
        out<<"que quan: "<<a.quequan<<endl;
        out<<"Nam sinh: "<<a.namsinh<<endl;
        return out;
    }
    int tinhTuoi()
    {
        int tuoi;
        tuoi=2022-namsinh;
        return tuoi;
    }
};

#endif /* NGUOI_H */
