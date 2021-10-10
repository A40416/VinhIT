#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string a[100];
    int i=0;
    fstream f;
    f.open("vinh.txt", ios::in);
    while(getline(f,a[i]))
    {
        i++;
    }
    for(int j=(i-10); j<i; j++)
    {
        cout<<a[j]<<endl;
    }
    cout<<a[i];
    f.close();
  
    return 0;
}