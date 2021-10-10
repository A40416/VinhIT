#ifndef CUSTORMERDATA_H
#define CUSTORMERDATA_H
#include "PersonData.h"
#include <string>
using namespace std;
class CustormerData : public PersonData
{
    private:
        int Id;
        int check;
    public:
       
        CustormerData(string ten, string adress, string ma, string phone, int id,int chec) : PersonData(ten,adress,ma,phone)
        {
            Id=id;
            check=chec;
        }
        int getID()
        {
            return Id;
        }
        int getCheck() const
        {
            return check;
        }
        void Print()
        {
            cout<<"Ten: "<<PersonData::getten()<<endl;
            cout<<"Dia chi: "<<PersonData::getAdress()<<endl;
            cout<<"Ma buu dien: "<<PersonData::getMa()<<endl;
            cout<<"SDT: "<<PersonData::getPhone()<<endl;
            cout<<"ID: "<<getID()<<endl;
            cout<<"Kiem tra: "<<getCheck()<<endl;
        }

};
#endif 
