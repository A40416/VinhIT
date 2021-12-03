#include <iostream>
#include <string>
using namespace std;

struct MovieData
{
	string Title,
	       Director;
	int YrReleased;
	int RuningTime;

	MovieData(string T, string D, int YR, int RT)
	{	
		Title = T;
		Director = D;
		YrReleased = YR;
		RuningTime = RT;
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
}
int main()
{
	MovieData VINH("Crash", "Thomas Ring", 2000, 130); 
	MovieData PRO("Die Hard 3", "Mark Pen", 2010, 140);

	displayinfo(VINH);
	displayinfo(PRO);

	return 0;
}
