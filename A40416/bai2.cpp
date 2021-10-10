#include <iostream>
using namespace std;
template <class T>
void print(int N, T a)
{
    for(int i=0; i<N; i++)
    {
        cout<<a<<" ";
    }
}
int main()
{
    print(5,7);
    cout<<endl;
    print(8,9.5);
}