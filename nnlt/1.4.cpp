#include <iostream>
using namespace std;
int main()
{
    int n;
    float *diem;
    float sum;
    cout<<"Nhap so so diem muon tinh TB: ";
    cin>>n;
    diem = new float[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap diem "<<i+1<<": ";
        cin>>diem[i];
        sum+=diem[i];
    }
    cout<<"Diem TB la:  "<< sum/n<<endl;
    return 0;
}