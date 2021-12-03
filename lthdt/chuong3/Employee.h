#ifndef C87FD53E_9B7E_4BEE_BE8C_B2533BA147AD
#define C87FD53E_9B7E_4BEE_BE8C_B2533BA147AD
#include <string> 
using namespace std;
class Employee
{
private:
	string ten;
	int maso;
	int ngaythue;
public:
	Employee()
	{
		ten="vinh";
		maso=2310;
		ngaythue=1;
	};
	Employee(string a, int b, int c)
	{
		ten=a;
		maso=b;
		ngaythue=c;
	};
	void setTen(string a)
	{
		ten=a;
	};
	void setMaso(int b)
	{
		maso=b;
	};
	void setNgay(int c)
	{
		ngaythue=c;
	};

	string getTen()
	{
		return ten;
	};
	int getMaso()
	{
		return maso;
	};
	int getNgay()
	{
		return ngaythue;
	};
};

#endif /* C87FD53E_9B7E_4BEE_BE8C_B2533BA147AD */
