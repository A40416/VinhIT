#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    double total=0.0;
    cout<<"Nhap so nguyen n: ";
    cin>>n;
    for(int i=0; i<=n; i++)
    { 
        if(n%2==0)
        {
            total+=1.0/pow(2,i)*1.0;
            cout<<total<<endl;
        }
        else
        {
            int n2=pow(n,2);
            total+=(double)pow((n2+1), 1/2);
        }
        
    }
    cout<<"Tong day so: "<< fixed << setprecision(2)<<(double)total*1.0<<endl;
    return 0;
    
}
