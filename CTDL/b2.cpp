#include <iostream>
using namespace std;
//#ifndef __B2__H__
//#define __B2__H__
const int num=3;
///#endif  //!__B2__H__
int Total(int arr[][3], int m, int n)
{
    if(m==0 && n==0)
    {
        return 0;
    }
    if(n==0)
    {
        m-=1;
        n=num-1;
    }
    else
    {
        n-=1;
    }
    return arr[m][n]+Total(arr,m,n);
}
int main()
{
    int arr[num][num]={1,2,3,4,5,6,7,8,9};
    cout<<Total(arr,num-1,num)<<endl;
}
