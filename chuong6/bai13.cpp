#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct Inventory{
    char morata[100];
    double amount;
    double buon;
    double le;
    char date[111];
    Inventory()
    {

    };
    Inventory(const char* m, double a, double b, double l, const char* d)
    {
        strcpy(morata,m);
        amount=a;
        buon=b;
        le=l;
        strcpy(date,d);
    };
};
// void add(fstream &f,Inventory *a, int num){
    
//     f.open("Kho.txt",ios::out| ios::binary);
//     cout<<"moi nhap mo ta:"<<endl;
//     getline(cin, a[num].morata);
//     //f<<a[num].morata<<endl;
//     f.write(reinterpret_cast<char*>(&a->morata),sizeof(a));
//     cout<<"moi nhap so luong: "<<endl;
//     cin>>a[num].amout;
//     //f<<a[num].amout<<endl;
//     f.write(reinterpret_cast<char*>(&a->amount),sizeof(a));
//     cout<<"moi nhap gia ban buon: "<<endl;
//     cin>>a[num].buon;
//     //f<<a[num].buon<<endl;
//     f.write(reinterpret_cast<char*>(&a->buon),sizeof(a));
//     cout<<"moi nhap gia ban le: "<<endl;
//     cin>>a[num].le;
//     //f<<a[num].le<<endl;
//     f.write(reinterpret_cast<char*>(&a->le),sizeof(a));
//     cout<<"moi nhap ngay thu: "<<endl;
//     getline(cin, a[num].date)
//     //f<<a[num].date<<endl; 
//     f.write(reinterpret_cast<char*>(&a->date),sizeof(a));
//     f.close();
// }
// void show(Inventory &a,int chon){
//     cout<<"Mo ta: "<<a[chon].morata;
//     cout<<"So luong"
// }
// void change(){}
// void menu(fstream &f,Inventory &a){
//     int chon;
//     do
//     {   cout<<"1.them bai ghi"<<endl;
//         cout<<"2.hien thi"<<endl;
//         cout<<"3.thay doi ban ghi"<<endl;
//         cin>>chon;
//         switch(chon)
//         {
//             case 1:
//             {
//                 add(a);
//             }
//             break;
//             case 2:
//             {
//                 cout<<"Moi ban chon ban ghi: "<<endl;
//                 int luachon;
//                 cin>>luachon;
//                 show(a,luachon);
//             }
//             break;
//             case 3:
//             {
//                 change();
//             }
//             break;
//         }
//     } while (chon!=3);
    

//}
void print(Inventory a)
{
    cout<<a.morata<<endl;
}
int main()
{
    Inventory a[3];
//    a[0]=Inventory("ok",5,5,5,"7/6");
//    a[1]=Inventory("ggg",5,5,5,"7/6");
//    a[2]=Inventory("hfhh",5,5,5,"7/6");
//    //fstream f("kho.txt",  ios::in | ios:: binary);
//    ofstream f("kho.txt", ios::out | ios:: binary);
//    //f.open("kho.txt", ios::out || ios:: binary);
//    f.write((char*)&a[0],sizeof(Inventory));
//    f.write((char*)&a[1],sizeof(Inventory));
//    f.write((char*)&a[2],sizeof(Inventory));
    
    ifstream f("kho.txt",  ios::in | ios:: binary);
    f.read((char*)&a[0],sizeof(Inventory));
    f.read((char*)&a[1],sizeof(Inventory));
    f.read((char*)&a[2],sizeof(Inventory));
    print(a[0]);
    print(a[1]);
    print(a[2]);
    for(int i=0; i<3; i++)
    {
        cout<<a[i].morata;
    }
f.close();
    


}