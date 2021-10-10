#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"
using namespace std;
class Essay : public GradedActivity
{
 private:
    int Nguphap;
    int Chinhta;
    int Dodai;
    int Noidung;
 public:
       Essay(): GradedActivity()
       {
           Nguphap=0;
           Chinhta=0;
           Dodai=0;
           Noidung=0;
       }
       Essay ( int s,int a, int b, int c, int d) : GradedActivity(s)
       {
           Nguphap=a;
           Chinhta=b;
           Dodai=c;
           Noidung=d;
       }
        int getNguphap() const
        {
            return Nguphap;
        }
        int getChinhta() const
        {
            return Chinhta;
        }
        int getDodai() const
        {
            return Dodai;
        }
        int getNoidung() const
        {
            return Noidung;
        }
       void Diem()
       {
           cout<<"Diem cua ban la: "<< Essay::getLetterGrade()<<endl;
           cout<<"Diem ngu phap :"<< getNguphap()<<endl;
           cout<<"Diem chinh ta : "<< getChinhta()<<endl;
           cout<<"Diem do dai: "<< getDodai()<<endl;
           cout<<"Diem noi dung: "<< getNoidung()<<endl;
       }

};
#endif /* ESSAY_H */
