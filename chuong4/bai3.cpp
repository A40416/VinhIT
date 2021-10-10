#include <iostream>
#include <string>
using namespace std;

template<class T>
T minimum(T a, T b)
{
    if(a < b)
        return a;
    return b;
}

template<class T>
T maximum(T a, T b){
    if(a > b)
        return a;
    return b;
}


int main()
{
    int a1 = 5, a2 = 20;
    cout << "nho hon: " << minimum(a1, a2) << endl;
    cout << "lon hon: " << maximum(a1, a2) << endl;
    cout << "nho hon: " << minimum('A', 'Z') << endl;
    cout << "lon hon: " << maximum('A', 'Z') << endl;
    cout << "nho hon: " << minimum(5.4, 9.8) << endl;
    cout << "lon hon: " << maximum(9.8, 5.4) << endl;
    return 0;
}
