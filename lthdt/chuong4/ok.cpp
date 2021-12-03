#include <iostream>
#include <string>
using namespace std;

template < class T > 
class Array{
    protected:
        T a[100];
        int size;
    public:
        Array(){
            size= 0;
        }
        void add(T x){
            a[size]= x;
            size++;
        }

        T get(int id){
            return a[id];
        }

        void print(){
            for (int i=0; i< size; i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
};

// Ke thua 1 classs Template
template < class T > 
class SortArray : public Array< T > 
{
    public:
        void add(T x){
            this->a[this->size]= x;
            for(int i= this->size; i>=1; i--){
                if (this->a[i] < this->a[i-1]){
                    T t= this->a[i];
                    this->a[i]= this->a[i-1];
                    this->a[i-1]= t;
                }
            }
            this->size++;
        }
};


int main(){

    int n;
    SortArray < string > array;
    cin>>n;
    for(int i=0; i<n;i++) {
        string x;
        cin>>x;
        array.add(x);
    }

    array.print();

    cout<<array.get(0)<<endl;
    system("pause");
    return 0;
}