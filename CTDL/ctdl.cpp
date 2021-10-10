#include <iostream>
using namespace std;
template <class T>
class list{
    private:
        struct node {
            T item;
            node *next;
        };
        node *head;
        int size;
        node* find(int index) const{
            node *t=head;
            for (int i=1;i< index; i++)
                t=t->next;
            return t;
            }
    public:
    list();
    void push_front(T anew);
    void pop_front();
    void push_back(T anew);
    void pop_back();
    void insert(int index,T anew);
    void remove(int index);
    bool isempty();
    int getsize();
    T truyxuat(int index);
};
// template<class T>
// node* list<T>::find(int index) const{
//     node *t=head;
//     for (int i=1;i< index; i++)
//         t=t->next;
//     return t;
// }
template<class T>
list<T>::list(){
    size=0;
    head=NULL;
}
template<class T>
void list<T>::push_front(T anew){
    node* newp;
    newp=new node; 
    newp->item=anew;
    // tao node moi
    newp->next=head;
    head=newp;
    size++;
}
template<class T>
void list<T>::pop_front(){
    if(!isempty()){
    node* d=head;
    head=head->next;
    delete d;
    size--;}
    else
        cout<<"ds trong"<<endl;
}
template<class T>
void list<T>::push_back(T anew){
    node* newp;
    newp=new node();
    newp->item=anew;
    // tao node moi
    node* prev=find(size);
    prev->next=newp;
    newp->next=NULL;
    size++;
}
template<class T>
void list<T>::pop_back(){
    if(!isempty())
    {
    node* p=find(size-1);
    node* d=p->next;
    delete d;
    size--;
    }
    else 
        cout<<"ds trong"<<endl;
}
template<class T>
void list<T>::insert(int index,T anew){
    if (index<0||index >size+1)
    cout<<"vi tri khong hop le "<<endl;
    else    
    {
        node* newp;
        newp=new node();
        newp->item=anew;
        // tao node moi
        if (index==1)
        {
            newp->next=head;
            head=newp;
        }
        else{
        node *p=head;
        p=find(index-1);
        newp->next=p->next;
        p->next=newp;
        }
        size++;
    }
}
template<class T>
void list<T>::remove(int index){
    if ((index<0||index>size)&& isempty())
        cout<<"vi tri khong hop le "<<endl;
    else{
        if(index==1)
        {
            node*d=head;
            head=head->next;
            d->next=NULL;
            delete d;
        }
        else{
            node* p=find(index-1);
            node*d=p->next;
            p->next=d->next;
            d->next=NULL;
            delete d;
        }
        size--;
    }
}
template<class T>
int list<T>::getsize(){
    return size;
}
template<class T>
bool list<T>::isempty(){
    if (size==0)
        return true;
    else
        return false;
}
template<class T>
T list<T>::truyxuat(int index){
if( index>0 && index<=size){

    node *tt=find(index);
    return tt->item;
}
else
    cout<<"vi tri can tim khong hop le"<<endl;
    return 0;
}
int main(){
    list<int> a;
    a.push_front(5);
    a.push_front(7);
    a.push_front(4);
    a.insert(3,55);

    cout<<a.truyxuat(3)<<endl;
    a.remove(3);
    cout<<a.truyxuat(3)<<endl;
    // a.push_back(58);
    // cout<<a.truyxuat(4)<<endl;
    // a.pop_back();
    // cout<<a.truyxuat(4)<<endl;
    // cout<<a.truyxuat(1)<<endl;
    // a.pop_front();
    // cout<<a.truyxuat(1)<<endl;
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.remove(1);
}
