#include <iostream>
using namespace std;
template<class T>
class list{
  private:

    struct node{
        T item;
        node* next;
        node* prev;
    };

    node* head;
    node* tail;
    int size;

    node* find(int index) const{
      node* cur = head;
      for(int i = 1; i < index ; i++){
        cur = cur -> next;
      }
      return cur;
    }
public:
    list() {head = NULL;
    tail=NULL; size = 0;};
    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    void remove(int index);
    void insert(int index, T val);
    T truyxuat(int index);
    int getsize()   const;
    bool isempty()  const;
    void print_list();
};

template<class T>
void list<T>::push_front(T val) {
    size++;
    node *p = new node();
    p->item = val;
    if(size==1)
        head=tail=p;
    else{
    p->next = head;
    head->prev=p;
    head = p;
    tail->next=head;
    head->prev=tail;
    }
}
template<class T>
void list<T>::push_back(T val) {
    size++;
    node* p = new node();
    p->item = val;
    //p->next = NULL;
    if(size==1)
        head=tail=p;
    else{
    tail->next=p;
    p->prev=tail;
    tail=p;
    }
    tail->next=NULL;
    head->prev=NULL;
}
template<class T>
void list<T>::pop_front() {
    if(!isempty()){
    node* d = head;
    head = head->next;
    d->prev=NULL;
    delete d;
    tail->next=head;
    head->prev=tail;
    size--;
    }
    else    
        cout<<"ds trong"<<endl;
}
template<class T>
void list<T>::pop_back(){
    if(!isempty())
    {
    node* p=tail;
    tail=tail->prev;
    tail->next=NULL;
    p->prev=NULL;
    delete p;
    head->prev=NULL;
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
        size++;
        node* newp;
        newp=new node();
        newp->item=anew;
        // tao node moi
        if (index==1)
        {
            push_front(anew);
        }
        else{
        node *p=head;
        p=find(index-1);
        newp->next=p->next;
        p->next=newp;
        }
    }
}
template<class T>
void list<T>::remove(int index){
    if ((index<=0||index>size))
        cout<<"vi tri khong hop le "<<endl;
    else{
        if(index==1)
            pop_front();
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
int list<T>::getsize() const{
    return size;
}
template<class T>
bool list<T>::isempty() const{
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
        cout<<p->item<<" ";
        p=p->next;
    }
    cout<<endl;
}


int main()
{
    list<int>l;
    l.push_front(24);
    l.push_front(23);
    l.push_back(10);
    l.pop_front();
    l.pop_back();
    // l.push_back(10);
    // l.push_back(30);
    //  l.pop_back();
    //       l.pop_back();
    //            l.pop_back();
    //                 l.pop_back();
 
    // l.pop_back();
        // l.pop_front();
        // l.pop_front();
        // l.pop_back();
        // l.push_front(6);
        // l.push_front(7);
        // l.push_front(8);
       // l.pop_front();
        // l.remove(1);
        //l.insert(1,3);
    //l.push_front(6);
    cout<<l.getsize()<<endl;
    l.print_list();
}