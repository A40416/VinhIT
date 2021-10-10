#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Data
{
    string name;
    int precious;
    int sales;
};
int main()
{
    Data vinh[4];
    fstream f1,f2,f3,f4;
    f1.open("Quy1.txt", ios::out);
    f2.open("Quy2.txt", ios::out);
    f3.open("Quy3.txt", ios::out);
    f4.open("Quy4.txt", ios::out);
    for(int i=0; i<4; i++)
    {
        cout<<"Nhap doanh thu kv ";
        cin>> vinh[i].name;
        for(int j=0; j<4;j++)
        { 
            cout<<"Quy "<<j+1<<endl;
            cout<<"Doanh thu: ";
            cin>> vinh[j].sales;
            if(j==0)
                f1<<vinh[j].sales<<endl;
            else if(j==1)
                f2<<vinh[j].sales<<endl;  
            else if(j==3)
                f3<<vinh[j].sales<<endl;  
            else
                f4<<vinh[j].sales<<endl;        
        }
    }
    f1.close();
    f2.close();
    f3.close();
    f4.close();
    return 0;
}