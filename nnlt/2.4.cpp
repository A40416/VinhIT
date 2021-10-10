#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cout<<"Nhap so nguoi tham gia: ";
    cin>>n;
    int Maso[n];
    int Time[n];
    int mamin;
    int temp;
    bool check;
    for(int i=0; i<n; i++)
    {
        Maso[i]=i+1;
        cout<<"Nhap time ht vdv"<<i+1<<": ";
        cin>>Time[i];
    }
    int min=Time[0];
    for(int i=1; i<n; i++)
    {
        if(Time[i]<min)
        { 
            min=Time[i];
            mamin=Maso[i];
        }
    }
    cout<<"VDV ve som nhat co ma so "<< Maso[mamin]<<" voi thanh tich "<< min<< " giay"<<endl;

    do{
        check=false;
        for(int i=0; i<n-1; i++)
        {
            if(Time[i]>Time[i+1])
            {
                temp=Time[i];
                Time[i]=Time[i+1];
                Time[i+1]=temp;

                temp=Maso[i];
                Maso[i]=Maso[i+1];
                Maso[i+1]=temp;
                check=true;
            }
        }
    }while(check);
    cout<<"Thu hang"<<setw(15)<<"Ma so"<<setw(15)<<"Thanh tich"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<setw(15)<<Maso[i]<<setw(15)<<Time[i]<<endl;
    }
     

    return 0;
}