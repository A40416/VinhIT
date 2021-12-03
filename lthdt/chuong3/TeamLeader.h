#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <iostream>
#include <string>
#include "ProductionWorker.h"


class TeamLeader : public ProductionWorker{
private:
    double Bonusmonth;
    int hoursRequired;
    int hoursAttended;
public:
    TeamLeader() : ProductionWorker() {
        cout << "Default constructor of TeamLeader class...\n";

        Bonusmonth = 0.0;
        hoursRequired = 40;
        hoursAttended = 0;
    }

    TeamLeader(string a, int b, int c,int d, int e, double mb, int hr, int ha) : ProductionWorker(a,b,c,d,e){
        cout << "Overloaded constructor of TeamLeader class...\n";


        if(mb < 0){
            cout << "Error!\n";
        }
        if(hr < 0){
            cout << "Error!\n";
        }
        if(ha < 0){
            cout << "Error!\n";
        }

        if(mb < 0 || hr < 0 || ha < 0){
            cout << "End!\n";
            exit(EXIT_FAILURE);
        }

        Bonusmonth = mb;
        hoursRequired = hr;
        hoursAttended = ha;
    }

    double getBonus() const{
        return Bonusmonth;
    }

    int getHoursRequired() const{
        return hoursRequired;
    }

    int getHoursAttended(){
        return hoursAttended;
    }

    void setBonus(double mb){
        while(mb < 0){
            cout << "Error!";
            cout << " Enter again: ";
            cin >> mb;
        }

        Bonusmonth = mb;
    }

    void setHoursRequired(int hr) {
        while(hr < 0){
            cout << "Error!";
            cout << " Enter again: ";
            cin >> hr;
        }

        hoursRequired = hr;
    }

    void setHoursAttended(int ha) {
        while(ha < 0) {
            cout << "Error!";
            cout << " Enter again: ";
            cin >> ha;
        }

        hoursAttended = ha;
    }
    void Print()
    {
        cout<<"Ten: "<<getTen()<<endl;
		cout<<"Ma so: "<<getMaso()<<endl;
		cout<<"So ngay thue: "<<getNgay()<<endl;
		cout<<"Ca: "<<getCa()<<endl;
		cout<<"Luong/1h= "<<getLuong()<<endl;
        cout<<"Thuong: "<<getBonus()<<endl;
        cout<<"So gio min= "<<getHoursRequired()<<endl;
        cout<<"So gio thuc lam: "<< getHoursAttended()<<endl;
        cout<<"Tong Luong ="<<getBonus()+getLuong()<<endl;
    }
    
};

#endif
