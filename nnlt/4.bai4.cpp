#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void SapXep(string *ten, int *dt, int n)
{
    
    string temp1;
    int temp2;
    for(int i= 0; i<n-1;i++){
            for(int j= i+1; j<n; j++){
            if (dt[i]<dt[j])
            {
                temp1=ten[i];
                ten[i]=ten[j];
                ten[j]=temp1;

                temp2=dt[i];
                dt[i]=dt[j];
                dt[j]=temp2;
                
            }
                }
            }
}
// void SapXep(string *ten, int *dt, int n)
// {
//     bool check;
//     string temp1;
//     int temp2;
//     do
//     {
//         check=false;
//         for (int i=0; i<n; i++)
//         {
//             if (dt[i]<dt[i+1])
//             {
//                 temp1=ten[i];
//                 ten[i]=ten[i+1];
//                 ten[i+1]=temp1;

//                 temp2=dt[i];
//                 dt[i]=dt[i+1];
//                 dt[i+1]=temp2;
//                 check=true;
//             }
//         }
//     } while (check); 
// }
int main()
{
    int n;
    ifstream f;
    f.open("Phim.txt");
    f>>n;
    string ten[n];
    int dt[n];
    string temp;
    cout<<"So bo phim la: "<<n<<endl;
    for(int i=0; i<n; i++)
    {
        getline(f, temp);
        getline(f,ten[i]);
        f>>dt[i];
        //getline(f, temp);
    }
    f.close();
    SapXep(ten,dt,n);
    cout<<"5film co doanh thu cao nhat la: \n";
    for(int i=0; i<5; i++)
    {
        cout<<"Film"<<i+1<<" : \n" <<"Ten: "<<ten[i]<<endl;
        cout<<"Doanh thu: "<<dt[i]<<endl;
    }
    return 0;
}

