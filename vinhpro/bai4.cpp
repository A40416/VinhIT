#include<iostream>
#include<string>
using namespace std;
class Nguoi{
    protected:
        string cmt;
        string hoten;
        string quequan;
        int namsinh;
    public:
        Nguoi(){
        };
        Nguoi(string a,string b,string c,int d){
            cmt=a;
            hoten=b;
            quequan=c;
            namsinh=d;
        }
        void setcmt(string a){
            cmt=a;
        }
        void sethoten(string b){
            hoten=b;
        }
        void setquequan(string c){
            quequan=c;
        }
        void setnamsinh(int d){
            namsinh=d;
        }
        string getcmt(){
            return cmt;
        }
        string gethoten(){
            return hoten;
        }
        string getquequan(){
            return quequan;
        }
        int getnamsinh(){
            return namsinh;
        }
        friend istream& operator >>(istream &in,Nguoi &t){
            cout<<"Moi nhap cmt: "<<endl;
            in>>t.cmt;
            cout<<"Moi nhap ten: "<<endl;
            in>>t.hoten;
            cout<<"Moi nhap que quan: "<<endl;
            in>>t.quequan;
            cout<<"Moi nhap nam sinh: "<<endl;
            in>>t.namsinh;
            return in;
        }
        friend ostream& operator <<(ostream &out,Nguoi &t){
            out<<"CMT: "<<t.cmt<<endl;
            out<<"Ten: "<<t.hoten<<endl;
            out<<"Que quan: "<<t.quequan<<endl;
            out<<"Namsinh: "<<t.namsinh<<endl;
            return out;
        }
};
class sinhvien:public Nguoi{
    protected:
        string msv;
        string nganhhoc;
    public:
        sinhvien(){};
        sinhvien(string a,string b,string c,int d,string e,string f):Nguoi(a,b,c,d){
            msv=e;
            nganhhoc=f;
        }
        void setmsv(string k){
            msv=k;
        }
        void setnganhoc(string k1){
            nganhhoc=k1;
        }
        string getmsv(){
            return msv;
        }
        string getnganhhoc(){
            return nganhhoc;
        }
        friend istream& operator>>(istream &in,sinhvien &t){
            cout<<"Moi nhap cmt: "<<endl;
            in>>t.cmt;
            cout<<"Moi nhap ten: "<<endl;
            in>>t.hoten;
            cout<<"Moi nhap que quan: "<<endl;
            in>>t.quequan;
            cout<<"Moi nhap nam sinh: "<<endl;
            in>>t.namsinh;
            cout<<"Moi nhap msv: "<<endl;
            in>>t.msv;
            cout<<"Moi nhap nganh hoc: "<<endl;
            in>>t.nganhhoc;
            return in;
        }
        friend ostream& operator<<(ostream &out,sinhvien &t){
            out<<"CMT: "<<t.cmt<<endl;
            out<<"Ten: "<<t.hoten<<endl;
            out<<"Que quan: "<<t.quequan<<endl;
            out<<"Namsinh: "<<t.namsinh<<endl;
            out<<"MSV: "<<t.msv<<endl;
            out<<"Nganhhoc: "<<t.nganhhoc<<endl;
            return out;
        }

};
class quanlysinhvien:public sinhvien{
    private:
        int n;
        sinhvien *sv;
    public:
        quanlysinhvien(int ssv){
            n=ssv;
            sv=new sinhvien [n];
        }
        // quanlysinhvien(int m,sinhvien a[]){
        //     n=m;
        //     sv=new sinhvien [n];
        //     for(int i=0;i<n;i++){
        //         sv[i]=a[i];
        //     }
        // }
        void nhap(){
            for(int i=0;i<n;i++){
                cout<<"sinh vien "<<i<<endl;
                cin>>sv[i];
                }
        }
        void xuat(){
            for(int i=0;i<n;i++){
                cout<<sv[i];
            }
        }
        void sapxep(){
            for(int i= 0; i<n-1;i++){
                for(int j= i+1; j<n; j++){
                    if ( sv[i].gethoten()> sv[j].gethoten()){
                        sinhvien temp= sv[i];
                        sv[i]= sv[j];
                        sv[j]= temp;
                    }
                }
            }
        }
};
int main(){
    quanlysinhvien a(3);
    a.nhap();
    a.sapxep();
    a.xuat();
}