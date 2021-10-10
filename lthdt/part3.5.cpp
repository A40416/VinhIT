#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct BookProfit
{
    string name;
    string tacgia;
    int year;
    double chiphi;
    double doanhthu;
};
int main()
{
    int n;
    cout<<"Nhap so luong sach: ";
    cin>>n;
    BookProfit a[n];
    for(int i=0; i<n; i++)
    {
        cout<<"--------"<<i<<"----------\n";
        cout<<"Nhap ten: ";
        cin.ignore();
        getline(cin,a[i].name);
        cout<<"Tac gia: ";
        getline(cin,a[i].tacgia);
        cout<<"Year: ";
        cin>>a[i].year;
        cout<<"Chi phi: ";
        cin>>a[i].chiphi;
        cout<<"Doanh thu: ";
        cin>>a[i].doanhthu;
    }
    
    double lai;
    cout<<"Nhap lai: ";
    cin>>lai;
    cout<<"Nhung sach co lai > lai vua nhap: \n";
    for(int i=0; i<n; i++)
    {
        if((a[i].doanhthu-a[i].chiphi)>lai)
            {
                cout<<"Name: "<<a[i].name<<endl;
                cout<<"Tac gia: "<<a[i].tacgia<<endl;
                cout<<"Nam xb: "<<a[i].year<<endl;
                cout<<"Chi phi: "<<a[i].chiphi<<endl;
                cout<<"Doanh thu: "<<a[i].doanhthu<<endl;
            }
    }
    cout<<"------------------\n";
    cout<<"------------------\n";
    cout<<"------------------\n";
    fstream f;
    f.open("ok.txt", ios::out | ios:: binary);
    f.write(reinterpret_cast<char*>(a),sizeof(a));
    f.close();

    BookProfit _a[n];
    f.open("ok.txt", ios::in | ios:: binary);
    f.read(reinterpret_cast<char*>(a),sizeof(a));
    f.close();

    for(int i=0; i<n; i++)
    {
        cout<<"Name: "<<a[i].name<<endl;
        cout<<"Tac gia: "<<a[i].tacgia<<endl;
        cout<<"Nam xb: "<<a[i].year<<endl;
        cout<<"Chi phi: "<<a[i].chiphi<<endl;
        cout<<"Doanh thu: "<<a[i].doanhthu<<endl;
    }
    return 0;

}