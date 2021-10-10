#include <iostream>
using namespace std;
template <class T>
class list{
    private:
        struct node {
            T item;
            node *prev;
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
    void print_list();
    friend ostream& operator<<(ostream& out, list<T> h)
    {
        node *p=h.head;
        while (p!=NULL)
        {
            out<<p->item<<" ";
            p=p->next;
        }
        return out;
    }
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
    node* p;
    p=new node();
    p->item=anew;
    // tao node moi
    if(head==NULL)
        head=p;
    else
    {    
        p->prev=p;
        p->next= head;
        head=p;
    }
    size++;
}
template<class T>
void list<T>::pop_front(){
    if(!isempty()){
    node* d=head;
    head=head->next;
    d->prev=NULL;
    delete d;
    size--;
    }
    else
        cout<<"ds trong"<<endl;
}
template<class T>
void list<T>::push_back(T anew){
    node* newp;
    newp=new node();
    newp->item=anew;
    if(head==NULL)
        head=newp;
    else{
        node* p=find(size);
        //newp->next=NULL;
        p->next=newp;
        newp->prev= p;
    }
    size++;
}
template<class T>
void list<T>::pop_back(){
    if(!isempty())
    {
        node* p=find(size);
        node* d=p;
        p=p->prev;
        p->next=NULL;
        d->prev=NULL;
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
            push_front(anew);
        }
        else if (index==size)
        {
            push_back(anew);
        }
        else{
        node *p=head;
        p=find(index-1);
        newp->next=p->next;
        p->next=newp;
        size++;
        }
        
    }
}
template<class T>
void list<T>::remove(int index){
    if ((index<0||index>size)&& isempty())
        cout<<"vi tri khong hop le "<<endl;
    else{
        if(index==1)
        {
           pop_front();
        }
        // else if (index==size)
        // {
        //     pop_back();
        // }
        else{
            node* p=find(index-1);
            node*d=p->next;
            p->next=d->next;
            d->next=NULL;
            delete d;
            size--;
        }
        
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
template<class T>
void list<T>::print_list(){
    node*p;
    p=head;
    for(int i=1;i<=size;i++)
    {
        cout<<p->item<<", ";
        p=p->next;
    }
    cout<<endl;

}
int main(){
    list<int> a;
    a.push_front(5);
    a.push_front(6);
    cout<<a<<endl;

    a.pop_front();
    a.pop_front();
    a.pop_front();
    cout<<"size:"<<a.getsize()<<endl;



    a.push_back(10);
    a.push_back(22);
    a.push_back(23);
    a.push_back(33);
    cout<<a<<endl;

    a.pop_back();
    cout<<a<<endl;

    a.insert(2,17);
    cout<<a<<endl;

    a.remove(3);
    cout<<a<<endl;
}
