#include <iostream>
#include <string>
using namespace std;
struct I4Customer
{
    string name,
           adress,
           phone;
    float money;
    int day;       
};
int main()
{
    int sua,a,chon,i=0;
    I4Customer Data[10];
    cout<<"Menu: "<<endl;
    cout<<"1. Nhap vao danh sach tai khoan.\n";
    cout<<"2. Sua thong tin. \n";
    cout<<"3. Hien thi danh sach tai khoan. \n";
    cout<<"4. Thoat. \n\n";
    
    do
    { 
        cout<<"Moi ban chon: ";
        cin>>chon;
        if(chon==1)
            {
            while (a!=0)
            {
                cout<<i+1<<"\nEnter the name: ";
                cin.ignore();
                getline(cin,Data[i].name);
                cout<<"Enter the adress: ";
                getline(cin,Data[i].adress);
                cout<<"Enter the number phone: ";
                getline(cin,Data[i].phone);
                cout<<"Enter the account balance: ";
                cin>>Data[i].money;
                cout<<"Enter the last payment date: ";
                cin>>Data[i].day;
                cout<<"Continue???: ";
                cin>>a;
                i++;
            }// while (a!=0);
            }
        else if(chon==2)
        {
            cout<<"Ban muon sua thong tin thu: ";
            cin>>sua;
            cout<<sua<<"\nEnter the name: ";
            cin.ignore();
            getline(cin,Data[sua-1].name);
            cout<<"Enter the adress: ";
            getline(cin,Data[sua-1].adress);
            cout<<"Enter the number phone: ";
            getline(cin,Data[sua-1].phone);
            cout<<"Enter the account balance: ";
            cin>>Data[sua-1].money;
            cout<<"Enter the last payment date: ";
            cin>>Data[sua-1].day;
        }
        else if(chon==3)
        {
            cout<<"STT       Name       Adress       Phone          Balance        Date       \n";
            for(int j=0; j<i; j++)
            {
                cout<<j+1<<":           "<<Data[j].name<<"             "<<Data[j].adress<<"            "<<Data[j].phone<<"                "<<Data[j].money<<"        "<<Data[j].day<<"\n";
            }
        }
        else
            cout<<"Vinhpro";
    }while(chon!=4);

    return 0;
}
