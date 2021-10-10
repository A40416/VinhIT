#ifndef MATH_H
#define MATH_H
#include "ucln.h"
using namespace std;
class Phanso
{
    private:
        int mau;
        int tu;
    public:
    Phanso()
    {
        tu=1;
        mau=1;
    }
    Phanso(int _tu, int _mau)
    {
        tu=_tu;
        mau=_mau;
    }
    Phanso operator+(Phanso a)
    {
        int tumoi= tu*a.mau+a.tu*mau;
        int maumoi= mau*a.mau;
        int u=UCLN(tumoi,maumoi);
        return Phanso(tumoi/u, maumoi/u);
    }
    Phanso operator-(Phanso a)
    {
        int tumoi= tu*a.mau-a.tu*mau;
        int maumoi= mau*a.mau;
        int u=UCLN(tumoi,maumoi);
        return Phanso(tumoi/u, maumoi/u);
    }
    Phanso operator*(Phanso a)
    {
        int tumoi= tu*a.tu;
        int maumoi= mau*a.mau;
        int u=UCLN(tumoi,maumoi);
        return Phanso(tumoi/u, maumoi/u);
    }
    Phanso operator/(Phanso a)
    {
        int tumoi= tu*a.mau;
        int maumoi= mau*a.tu;
        int u=UCLN(tumoi,maumoi);
        return Phanso(tumoi/u, maumoi/u);
    }
    friend ostream &operator<<(ostream &out, Phanso a)
    {
        out<<a.tu<<"/"<<a.mau<<endl;
        return out;
    }
};


#endif /* MATH_H */
