// #include<iostream>
// using namespace std;
// int UCLN(int a, int b)
// {
//     if(a==b) return a;
//     if(a>b) 
//         UCLN(a-b,b);
//     else
//         UCLN(a,b-a);    
// }
// int BCNN(int a, int b)
// {
//     return (a*b/UCLN(a,b) );
// }
// int main()
// {
//     long int num;
//     num=BCNN(1,2);
//     for(int i=3; i<=20; i++)
//     {
//         num=BCNN(num,i);
//         cout<<i<<":"<<num<<endl;
//     }
//     return 0;
// }    


#include<iostream>
using namespace std;
int main()
{
    int i = 20;
    
    while (i %  2 != 0 || i %  3 != 0 || i %  4 != 0 || i %  5 != 0 ||
        i %  6 != 0 || i %  7 != 0 || i %  8 != 0 || i %  9 != 0 ||
        i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
        i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
        i % 18 != 0 || i % 19 != 0 || i % 20 != 0) 
    {
        i += 20;
    }
    cout<<i<<endl;
    return 0;
}