#ifndef ABC_H
#define ABC_H
using namespace std;
class Stopwatch
{
private:
	int hour;
	int minute;
	int second;
    void normalize();
public:
	Stopwatch(int h = 0, int m = 0, int s = 0)
	{
		hour = h;
		minute = m;
		second = s;
        normalize();
	};
	void setHour(int h)
	{
		hour=h;
		normalize();
	};
	void setSecond(int s)
	{
		second=s;
		normalize();
	};
	void setMinute(int m)
	{
		minute=m;
		normalize();
	};
	float getHour() const
	{
		return hour + (float)(minute)/60 + (float)(second) / 3600;
	};
	int getSecond() const
	{
		return hour * 3600 + minute * 60 + second;
	};
    
    void run(int x)
    {
        second+=5;
		normalize();
    };
	void print() const
	{
		if (hour < 10)
		cout<<"0";
		cout<<hour<<":";
		if (minute < 10)
		cout<<"0";
		cout<<minute<<":";
		if (second < 10)
		cout<<"0";
		cout<<second<<endl;
	};
	Stopwatch operator+(Stopwatch a)
	{
		int hmoi= hour + a.hour;
		int mmoi= minute + a.minute;
		int smoi= second + a.second;
		return Stopwatch(hmoi,mmoi,smoi);
	}
	
};

#endif

void Stopwatch::normalize()
{
	if(hour>100)
	{
		hour=hour%100;
	}
	if(minute>59)
	{
		int a= minute/60;
		minute=minute%60;
		hour= hour+a;
	}
	if(second>60)
	{
		int b= second/60;
		second=second%60;
		minute= minute+b;
	}
}

