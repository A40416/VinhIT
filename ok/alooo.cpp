#include <iostream>
#include <string.h>
using namespace std;
class nguoi
{
public:
		char* ho= new char[100];
		char* ten= new char[100];
		nguoi()
		{

		}
		nguoi(char* ngay, char* h, char*t )
		{
			strcpy(ngaysinh,ngay);
			strcpy(ho,h);
			strcpy(ten,t);
		}
		~nguoi()
		{
			delete[] ho;
			delete[] ten;
			delete[] ngaysinh;
		}
protected:
	char* ngaysinh= new char[100];    
};
class giangvien : public nguoi
{
private:
	float sotiet;
	int chucvu;
public:
	static int soluong;
	float tongsotiet;  
	giangvien()
	{

	}
	giangvien(char* ngay, char* h, char*t, float s, int c ) : nguoi(ngay,h,t)
	{
		strcpy(ngaysinh,ngay);
		strcpy(ho,h);
		strcpy(ten,t);
		sotiet=s;
		chucvu=c;
	}
	~giangvien()
	{
		delete[] ho;
		delete[] ten;
		delete[] ngaysinh;
	}  
	friend istream & operator>>(istream &in, giangvien p)
	{
		cout<<"Nhap ho: ";
		in>>p.ho;
		cout<<"Nhap ten: ";
		in>>p.ten;
		cout<<"Nhap ngay sinh: ";
		in>>p.ngaysinh;
		cout<<"Nhap so tiet: ";
		in>>p.sotiet;
		cout<<"Nhap chuc vu: ";
		in>>p.chucvu;
		return in;
	}
	friend ostream & operator<<(ostream &out, giangvien p)
	{
		out<<"ho: "<<p.ho<<endl;
		out<<"ten: "<<p.ten<<endl;
		out<<"ngay sinh: "<<p.ngaysinh <<endl;
		out<<"so tiet: "<<p.sotiet<<endl;
		out<<"chuc vu: "<<p.chucvu<<endl;
		out<<"Tong so tiet: "<<p.tong()<<endl;
		return out;
	}
	float tong()
	{
		float total;
		if(chucvu==1)
			total=sotiet*1;
		if(chucvu==2)
			total=sotiet*1.4;
		if(chucvu==3)
			total=sotiet*1.6;
		if(chucvu==4)
			total=sotiet*2;
		return total;                
	}
};
int main()
{
	giangvien khoa[100];
	for(int i=0; i<10; i++)
	{
		cin>>khoa[i];
	}
	cout<<"-------------\n";
		for(int i=0; i<10; i++)
	{
		cout<<khoa[i];
	}
}