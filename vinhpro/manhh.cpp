#include <bits/stdc++.h>
using namespace std;
struct hocvien
{ char holot[30],ten[30],ngaysinh[8];
 char noisinh[40],x_loai[20];
 int d_win,d_word,d_excel,tongdiem;
};
void Nhap1(hocvien *a)
{
    cout<<"Ho Lot: ";
    cin.getline(a->holot, 20);
    cout<<"Ten: ";
    cin>>a->ten;
    cout<<"Ngay Sinh: ";
    cin.getline(a->ngaysinh, 8);
    cout<<"Noi Sinh: ";
    cin.getline(a->noisinh , 40);
}
void Nhap2(hocvien *a)
{
    int i;
    char c;
    do
    {
        cout<<"\n 2 - Nhap diem cua hoc vien (win, word, excel).";
        cout<<"\n (Nhan <ESC> de thoat)\n";
        cout<<"\n a_Diem win.";
        cout<<"\n b_Diem word.";
        cout<<"\n c_Diem excel.";
        cout<<"Moi ban chon: ";
        cin>>c;
        for( i=0; i<sizeof(a); i++)
        { 

            cout<<"\n Hoc vien thu "<<i;
            cout<<"\n\n Ho lot : "<<a[i].holot;
            cout<<"\n Ten : "<<a[i].ten<<endl;
            if (c=='a')
            {
                cout<<"\n\n Diem win :";
                cin>>a[i].d_win;
            }
            else if (c=='b')
            { 
                cout<<"\n\n Diem word :"; 
                cin>>a[i].d_word;
            }
            else if (c=='c')
            { 
                cout<<"\n\n Diem excel :";
                cin>>a[i].d_excel;
            }
        }
        }while (c!=0);
}
void XepLoai(hocvien *a)
{
    for(int i=0; i<sizeof(a); i++)
    {
        a[i].tongdiem=a[i].d_excel+a[i].d_win+a[i].d_word;
        if(a[i].tongdiem>=24)
            strcpy(a[i].x_loai,"Gioi");
        else if(a[i].tongdiem>=18)
            strcpy(a[i].x_loai,"KHA");
        else
            strcpy(a[i].x_loai,"TRUNG BINH");
    }
}
void IN1(hocvien *a)
{
    cout<<"STT     HO VA TEN       NGAY SINH       NOI SINH       GHI CHU\n";
    for(int i=0; i<sizeof(a); i++)
    {
        cout<<i+1<<"     "<<a[i].holot<<" "<<a[i].ten<<"       "<<a[i].ngaysinh<<"        "<<a[i].noisinh<<"       ...........";
    }
}
void IN2(hocvien *a)
{
    cout<<"STT     HO VA TEN       TONGDIEM       XEPLOAI       GHI CHU\n";
    for(int i=0; i<sizeof(a); i++)
    {
        cout<<i+1<<"     "<<a[i].holot<<" "<<a[i].ten<<"       "<<a[i].tongdiem<<"        "<<a[i].x_loai<<"       ...........";
    }
}
int main()
{   
    int n;
    cout<<"\n CHUONG TRINH QUAN LY DIEM CUA LOP TIN HOC VAN PHONG ";
    cout<<"\n Nhap so hoc vien : ";
    cin>>n;
    hocvien *SV= new hocvien[n];
    do
    {
        char ch;
        cout<<"\n Chon cong viec :";
        cout<<"\n 1 - Nhap thong tin cua hoc vien (holot,ten,ngaysinh).";
        cout<<"\n 2 - Nhap diem cua hoc vien.";
        cout<<"\n 3 - In danh sach hoc sinh.";
        cout<<"\n 4 - Xu ly du lieu va xep loai.";
        cout<<"\n 5 - In danh sach hoc sinh va diem.";
        cout<<"\n Nhan <ESC> de thoat.";
        cout<<"\n Moi b chon: ";
        cin>>ch;
        if ( ch=='1') Nhap1(SV);
        else if (ch=='2') Nhap2(SV);
        else if (ch=='3') IN1(SV);
        else if (ch=='4') XepLoai(SV);
        else if (ch=='5') IN2(SV); 
    }while (ch!='0');

    return 0;
}