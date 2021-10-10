#include <iostream>
using namespace std;
struct Weather {
    double totalRain;
    double highTemp;
    double lowTemp;
    double averageTemp;
};

const char* MONTH_NAME[12] = {"January", "February", "March", "April", "May", "June",

    "July", "August", "September", "October", "November", "December"};

double getTemp(const char* name) {
    double temp;
    cout << "Enter the " << name << ": ";
    do {
        cin >> temp;
    } while(temp < -73 || temp > 60);
    return temp;
}
int main() {
    Weather data[12];
    double yearRainfall = 0;
    unsigned char lowest = 0;
    unsigned char highest = 0;
    double sumAvgTemps = 0;
    for(int i = 0; i < 12; i++) {
        cout << "Import data for " << MONTH_NAME[i] << endl;
        cout << "Enter the Total Rainfall: ";
        do {
            cin >> data[i].totalRain;
        } while (data[i].totalRain < 0);
        data[i].highTemp = getTemp("Highest Temperature");
        data[i].lowTemp = getTemp("Lowest Temperature");
        data[i].averageTemp = getTemp("Average Temperature");
        cout << endl;
        yearRainfall += data[i].totalRain;
        if(data[highest].highTemp < data[i].highTemp) {
            highest = i;
        }
        if(data[lowest].lowTemp > data[i].lowTemp) {
            lowest = i;
        }
        sumAvgTemps += data[i].averageTemp;

    }
    cout << "\n === RESULTS === \n";
    cout << "Average Monthly Rainfall: " << (yearRainfall / 12) << endl;
    cout << "Total Yearly Rainfall: " << yearRainfall << endl;
    cout << "Highest Temperature: " << data[highest].highTemp << " (" << MONTH_NAME[highest] << ") " << endl;
    cout << "Lowest Temperature: " << data[lowest].lowTemp << " (" << MONTH_NAME[lowest] << ") " << endl;
    cout << "Average Monthly Temperature: " << (sumAvgTemps / 12) << endl;
    cout << endl;  
    return 0;

}