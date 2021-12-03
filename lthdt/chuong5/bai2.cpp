#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct MovieData
{
	string Title,
	       Director;
	int YrReleased;
	int RuningTime;
    int cost;
    int Revenue;
    int Check;

	MovieData(string T, string D, int YR, int RT, int C, int R)
	{	
		Title = T;
		Director = D;
		YrReleased = YR;
		RuningTime = RT;
        cost=C;
        Revenue=R;
        Check=R-C;
	}
};
void displayinfo(MovieData M)
{
	cout << "\n\n       Move information\n"
	     << "-----------------------------------\n";
	cout << "Title:                 " << M.Title << endl;
	cout << "Director:              " << M.Director << endl;
	cout << "Year Released:         " << M.YrReleased << endl;
	cout << "Runing Time (minutes): " << M.RuningTime << endl;
    cout << "Cost:                  $" << M.cost << endl;
    cout << "Revenue:               $" << M.Revenue <<endl;
    if(M.Check>0)
        cout << "Interest:              $" << M.Check << endl;
    else
        cout << "Hole                   $" << abs(M.Check) << endl; 
}
int main()
{
	MovieData VINH("Crash", "Thomas Ring", 2000, 130, 2000, 2500); 
	MovieData PRO("Die Hard 3", "Mark Pen", 2010, 140, 3000, 2000);

	displayinfo(VINH);
	displayinfo(PRO);

	return 0;
}
