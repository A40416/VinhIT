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
        node *tail;
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
    friend ostream& operator<<(ostream& out, list<T> h)
    {
        node *p=h.head;
        do
        {
            out<<p->item<<" ";
            p=p->next;
        }while(p!=h.head);
        return out;
    }
};
template<class T>
list<T>::list(){
    size=0;
    head=NULL;
    tail=NULL;
}
template<class T>
void list<T>::push_front(T anew){
    node* newp;
    newp=new node();
    newp->item=anew;
    // tao node moi
    if(head==NULL)
        head=tail=newp;
    else{    
        newp->next=head;
        head=newp;
    }
    tail->next=head;
    size++;
}
template<class T>
void list<T>::pop_front(){
    if(isempty())
        cout<<"ds trong"<<endl;
    else
    {
        node* p=head;
        head=head->next;
        delete p;
    }
    tail->next=head;
    size--;
}
template<class T>
void list<T>::push_back(T anew){
    node* newp=new node;
    newp->item=anew;
    if(isempty())
        push_front(anew);
    else{
        tail->next=newp;
        tail=newp;   
    }
    tail->next=head;
    size++;
}
template<class T>
void list<T>::pop_back(){
    if(isempty())
        cout<<"ds trong"<<endl;
    else
    {
        node* p=find(size-1);
        node* d=tail;
        delete d;
        p->next=head;
        tail=p;
        size--;
    }
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
        else
        {
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
            pop_front();
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

int main(){
    list<int> a;
    a.push_front(5);
    a.push_front(6);
    cout<<a<<endl;

    a.pop_front();
    cout<<a<<endl;

    a.push_back(10);
    a.push_back(22);
    cout<<a<<endl;

    a.pop_back();
    cout<<a<<endl;

    a.insert(3,17);
    cout<<a<<endl;

    a.remove(2);
    cout<<a<<endl;






}
