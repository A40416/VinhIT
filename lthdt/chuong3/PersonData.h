#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <string>
using namespace std; 
class PersonData
{
    private:
        string hoten;
        string diachi;
        string mabuudien;
        string sdt;
    public:
       
        PersonData (string ten, string adress, string ma, string phone)
        {
            hoten=ten;
            diachi=adress;
            mabuudien=ma;
            sdt=phone;
        }
        void setten(string ten)
        {
            hoten=ten;
        }
        void setAdress(string adress)
        {
            diachi=adress;
        }
        void setMa(int ma)
        {
            mabuudien=ma;
        }
        void setSdt(string phone)
        {
            sdt=phone;
        }
        string getten()
        {
            return hoten;
        }
        string getAdress()
        {
            return diachi;
        }
        string getMa()
        {
            return mabuudien;
        } 
        string getPhone()
        {
            return sdt;
        }
};

#endif 

