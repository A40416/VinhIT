#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    vector <int> A;
    int a, i=0;
    ifstream f;
    
    f.open("SoNguyen.txt");
    while (f>>a)
    {
        A.push_back(a);
        if(A[i]%2==0)
            cout<<A[i]<<endl;
        i++;    
    }
    f.close();
    return 0;
}