#include <iostream>
#include <fstream>
using namespace std;
struct BookData
{
string name;
string author;
int year_publish;
int pageNums;
string company_pub;
};



int main()
{
int n;
cout<<" n: ";
cin>>n;
BookData list[n];
for(int i=0; i<n;i++)
{
cout <<"Name: ";
cin>>list[i].name;
cout<<"author: ";
cin>>list[i].author;
cout<<"year publish: ";
cin>>list[i].year_publish;
cout<<"page nums: ";
cin>>list[i].pageNums;
cout<<"company publish : ";
cin>>list[i].company_pub;
}
int year;
cout<<" enter year: ";
cin>>year;
for(int i=0;i<n;i++)
{
if(list[i].year_publish==year)
{
cout <<"Name: "<<list[i].name<<endl;
cout<<"author: " <<list[i].author<<endl;
cout<<"year publish: "<<list[i].year_publish<<endl;
cout<<"page nums: "<<list[i].pageNums<<endl;
cout<<"company publish : "<<list[i].company_pub<<endl;
}
}
BookData obj[n];
fstream f("book.dat", ios::out | ios::binary );
f.write(reinterpret_cast<char *> (&list),sizeof(list));
f.close();
fstream fa("book.dat", ios::in | ios::binary );
fa.read(reinterpret_cast<char *> (&obj),sizeof(obj));
fa.close();
for(int i=0;i<n;i++)
{
cout <<"Name: "<<obj[i].name<<endl;
cout<<"author: " <<obj[i].author<<endl;
cout<<"year publish: "<<obj[i].year_publish<<endl;
cout<<"page nums: "<<obj[i].pageNums<<endl;
cout<<"company publish : "<<obj[i].company_pub<<endl;
}
}