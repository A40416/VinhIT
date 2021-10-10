#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  float a,b,c,d,r;
  int chon;
  cout<<"Menu: \n";
  cout<<"1.Tinh S tron.\n";
  cout<<"2.Tinh S hcn.\n";
  cout<<"3.Tinh S tgv.\n";
  cout<<"4.Thoat\n";
  cout<<"\nMoi ban chon: ";
  cin>>chon;
  switch (chon)
  {
  case 1:
    {
        cout<<"Nhap r: ";
        cin>>r;
        cout<<"S tron la: "<< 3.14*pow(r,2)<<endl;
    }    
    break;
  case 2:
    {
        cout<<"Nhap chieu dai:";
        cin>>c;
        cout<<"Nhap chieu rong:";
        cin>>d;
        cout<<"S hcn la: "<<c*d<<endl;
    }
    break;
  case 3:
    {
        cout<<"Nhap 2 canh tam giac vuong: ";
        cin>>a>>b;
        cout<<"S tron la: "<< 0.5*a*b<<endl;
    }
    break;
  case 4:
    break;
  default:
      break;
  }

  return 0; 
}
