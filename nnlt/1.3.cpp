#include <iostream>
using namespace std;
int XacThuc(int a[], int num, int N)
{
    int check=-1;
    for(int i=0; i<num; i++)
    {
        if(a[i]==N)
        {
            check=i;
            break;
        }
    }
    return check;
}
void SapXep(int a[], int num)
{
    int temp;
    bool check;
    do{
        check=false;
        for(int i=0; i<(num-1); i++)
        {
            if(a[i]<a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                check=true;
            }
        }
    }while(check);
}
int main()
{
    int const num=12;
    int array[num]={565,452,789,877,845,130,808,456,555,505,782,125};
    int value;
    cout<<"Nhap so can tim: ";
    cin>>value;
    if(XacThuc(array,num,value)==-1)
        cout<<"Khong hop le!\n";
    else
        cout<<"Hop le?? Xuat hien tai vi tri "<<XacThuc(array,num,value)<<endl;
    SapXep(array,num);
    cout<<"Sap xep giam dan: \n";
    for(int i=0; i<num; i++)
    {
        cout<<array[i]<<"\t";
    }
    return 0;
}
