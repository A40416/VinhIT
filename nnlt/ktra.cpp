#include <iostream>
using namespace std;
int* TinhTong( int a, int b)
{
    int *c;
    int d=b-a;
    c= new int[d];
    for(int i=a; i<=b; i++)
        for(j=i; j>0; j--)
        {
            if(i%j==0)
            {
                c[i]+=1;
            }
        }
   
    return c;

}
int main()
{
    int a,b;
    int *c;
    cout<<"Moi ban nhap a,b,c: ";
    cin>>a>>b>>c;
    c=new int[b-a];
    int max=a[0];
    for(int i=0; i<sizeof(c); i++)
    {
        if(c[i]>max)
            max=c[i];
    }
    cout<<"So co nhieu uoc nhat trong khoang a->b la: "<<max<<endl;



    // int a,b,c;
    // cout<<"Moi ban nhap a,b,c: ";
    // cin>>a>>b>>c;
    // cout<<"Tong cac uoc cua c tu a->b la: "<< TinhTong(a,b,c)<<endl;
    return 0;
}
/* 
viet ham tinh tong all ước cua x, nam trong khoang a den b. (x,a,b) la do nguoi dung nhap)
*/