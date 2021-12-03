#include <iostream>
using namespace std;
template <class T>
class Tree
{
	private:
		struct node
		{
			T data;
			node *pLeft;
			node *pRight;
		};
		node *root;
		void Add(node* t, int x)
		{
			if(t==NULL)
			{
				node *p= new node;
				p->data =x;
				p->pLeft =NULL;
				p->pRight=NULL;
				t=p;
			}
			else
			{
				if(t->data > x)
				{
					Add(t->pLeft,x);
				}
				else if(t->data<x)
				{
					Add(t->pRight,x);
				}
			}
		}
		node* search(int x, node *t)
		{
			if(t!=NULL)
			{
				if(x==t->data)
					return t;
				if(x<t->data)
					return search(x, t->pLeft);
				else
					return search(x, t->pRight);
			}
			return NULL;
		}
	public:
		Tree()
		{
			root=NULL;
		}	
		bool Search(T x)
		{
			return search(x, root);
		}
		bool Add(T x)
		{
			if(root==NULL)
			{
				node *p= new node;
				p->data =x;
				p->pLeft =NULL;
				p->pRight=NULL;
				root=p;
			}
			else
			{
				if(search(x,root)==NULL)
				{
					Add(root, x);
					return true;
				}
				else 
					return false;	
			}

		}

};
int main() {
  Tree <int> bt;
	cout<<bt.Add(10);
	cout<<bt.Add(15);
	cout<<bt.Add(17);
	cout<<bt.Add(5);
	cout<<bt.Add(8);
	cout<<bt.Add(9);
	cout<<bt.Add(17);

}