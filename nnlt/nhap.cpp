#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Q
{
    private:
        string Que;
        string tl[4];
        int correct;
    public:
        Q(){};
        Q(string Que,string tl1,string tl2,string tl3,string tl4,int correct){
            this->Que=Que;
            tl[0]=tl1;
            tl[1]=tl2;
            tl[2]=tl3;
            tl[3]=tl4;
            this->correct=correct;
        }
        void setque(string Que){
            this->Que=Que;
        }
        string getque(){
            return Que;
        }
        void settl(string tl,int i){
            this->tl[i]=tl;
        }
        string gettl(int i){
            return tl[i];
        }
        void setcorrect(int correct){
            this->correct=correct;
        }
        int getcorrect(){
            return correct;
        }
};
int main(){
    Q a[10];
    Q ab("cauhoi","1","2","3","4",1);
    cout<<ab.getque()<<endl;
    // fstream f;
    // int diem1=0;
    // int diem2=0;
    // string chuoi;
    // string tl;
    // f.open("doc.txt",ios::in);
    // for(int i=0;i<10;i++){
    //     getline(f,chuoi);
    //     a[i].setque(chuoi);
    //     for(int j=0;j<4;j++){
    //         getline(f,tl);
    //         a[i].settl(tl,j);;
    //     }
    // }
    // f.close();
    // for(int i=0;i<10;i++){
    //     a[i].setcorrect(3);
    // }
    // int chon;
    // cout<<"nguoi choi 1:"<<endl;
    // cout<<"ban phai tra loi 5 cau hoi dau: "<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<"cau hoi"<<i+1<<endl;
    //     cout<<a[i].getque()<<endl;
    //     for(int j=0;j<4;j++){
    //         cout<<j+1<<"."<<a[i].gettl(j)<<endl;
    //     }
    //     cout<<"moi chon dap an: "<<endl;
    //     cin>>chon;
    //     if(chon==a[i].getcorrect())
    //         diem1++;       
    // }
    // cout<<"diem cua nguoi choi 1 la:"<<diem1<<endl;
}