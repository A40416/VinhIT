#include <iostream>
#include <fstream>
using namespace std;
int dem = 0;
struct node
{
	int data;
	node *pLeft;
	node *pRight;
};
void KhoiTao(node* &t)
{
	t=NULL;
}
void Add(node* &t, int x)
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
void Xuat_NLR(node* t)
{
	if(t!=NULL)
	{
		cout<< t->data<<" ";
		Xuat_NLR(t->pLeft);
		Xuat_NLR(t->pRight);

	}
}
void Xuat_NRL(node* t)
{
	if(t!=NULL)
	{
		cout<< t->data<<" ";
		Xuat_NRL(t->pRight);
		Xuat_NRL(t->pLeft);

	}
}
void Xuat_LNR(node* t)
{
	if(t!=NULL)
	{
		Xuat_LNR(t->pLeft);
		cout<< t->data<<" ";
		Xuat_LNR(t->pRight);

	}
}
void Xuat_RNL(node* t)
{
	if(t!=NULL)
	{
		Xuat_RNL(t->pRight);
		cout<< t->data<<" ";
		Xuat_RNL(t->pLeft);

	}
}
void Xuat_RLN(node* t)
{
	if(t!=NULL)
	{
		Xuat_RLN(t->pRight);
		Xuat_RLN(t->pLeft);
		cout<< t->data<<" ";

	}
}
void Xuat_LRN(node* t)
{
	if(t!=NULL)
	{
		Xuat_LRN(t->pLeft);
		Xuat_LRN(t->pRight);
		cout<< t->data<<" ";
	}
}
bool Ktra_PRIME(int x)
{
	if(x<2)
	{
		return false;
	}
	else{
		if(x%2==0)
			return false;
		else{
			for(int i=2; i<x; i++)
			{
				if(x%i==0)
					return false;
			}
		}	
	}
	return true;
}
//dem soluong so nguyen to

void SL_PRIME(node* &t)
{
	if(t!=NULL)
	{
		if(Ktra_PRIME(t->data)==1)
		{
			dem++;
		}
		SL_PRIME(t->pLeft);
		SL_PRIME(t->pRight);
	}
}
//Tim kiem
void TimKiem(node* t, int x)
{
	if(t==NULL)
		return;
	if(x < t->data){
		TimKiem(t->pLeft,x);
	}
	else if(x > t->data){
		TimKiem(t->pRight,x);
	}
	else if( x== t->data)
		cout<<"Co ton tai"<<endl;
	else
	{
		cout<<"Khong ton tai\n";
	}	
	
}
void Node_2con(node *t)
{
	if(t!=0)
	{
		if(t->pLeft!=NULL&& t->pRight!=NULL)
			cout<<t->data<<" ";

		Node_2con(t->pLeft);
		Node_2con(t->pRight);
	}
}
void Node_1con(node *t)
{
	if(t!=0)
	{
		if(t->pLeft!=NULL&& t->pRight==NULL)
			cout<<t->data<<" ";
		if(t->pLeft==NULL&& t->pRight!=NULL)
			cout<<t->data<<" ";
		Node_1con(t->pLeft);
		Node_1con(t->pRight);
	}
}
void Node_la(node *t)
{
	if(t!=0)
	{
		if(t->pLeft==NULL&& t->pRight==NULL)
			cout<<t->data<<" ";
		Node_la(t->pLeft);
		Node_la(t->pRight);
	}
}
int Max(node *t)
{
	// if(t->pLeft == NULL && t-> pRight==NULL)
	// 	return t->data;
	//int max= t->data;

	// if(t->pLeft != NULL)
	// {
	// 	int left=Max(t->pLeft); 
	// 	if(max<left)
	// 		max=left;
	// }	
	// if(t->pRight != NULL)
	// {
	// 	int right=Max(t->pRight); 
	// 	if(max<right)
	// 		max=right;
	// }	
	// return max;
	if(t-> pRight==NULL)
		return t->data;
	return Max(t->pRight);
}
int Min(node *t)
{
	// if(t->pLeft == NULL && t-> pRight==NULL)
	// 	return t->data;
	// int min= t->data;

	// if(t->pLeft != NULL)
	// {
	// 	int left=Min(t->pLeft); 
	// 	if(min>left)
	// 		min=left;
	// }	
	// if(t->pRight != NULL)
	// {
	// 	int right=min(t->pRight); 
	// 	if(min>right)
	// 		min=right;
	// }	
	// return min;
	if(t->pLeft == NULL)
		return t->data;
	return Min(t->pLeft);
}
void TimNodeTheMang(node* &X, node* &Y)
{
	if(Y->pRight != NULL)
	{
		TimNodeTheMang(X, Y->pRight);
	}
	else
	{
		X->data= Y->data;
		X=Y;
		Y=Y->pLeft;
	}
}
//Xoa node bat ki
void Delete(node* &t, int x)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		if(t->data > x)
		{
			Delete(t->pLeft,x);
		}
		else if(t->data < x)
		{
			Delete(t->pRight,x);
		}
		else 
		{
			node* X=t;
			if(t->pLeft==NULL)
			{
				t=t->pRight;
			}
			else if(t->pRight==NULL)
			{
				t=t->pLeft;
			}
			else if(t->pLeft != NULL && t-> pRight!=NULL)
			{
				node* Y= t->pLeft;
				TimNodeTheMang(X,Y);
			}
			delete X;
		}
	}
}
void Doc_file(node* &t)
{
	ifstream f;
	f.open("vinh.txt");
	int n;
	f>>n;
	for(int i=0; i<n; i++)
	{
		int x;
		f>>x;
		Add(t,x);
	}
	f.close();
}
void Doc_file1(node* &t)
{
	ifstream f;
	f.open("vinh1.txt");
	while(true)
	{
		int x;
		f>>x;
		Add(t,x);
		char c;
		f>>c;
		if(f.eof()==true)
		{
			break;
		}
		
	}
	f.close();
}

void Menu(node* &t)
{
	while(true)
	{
		cout<<"\n------------Menu--------------\n";
		cout<<"1. Nhap du lieu\n";
		cout<<"2. Xuat NLR du lieu\n";
		cout<<"3. Xuat NRL du lieu\n";
		cout<<"4. Xuat LNR du lieu\n";
		cout<<"5. Xuat RNL du lieu\n";
		cout<<"6. Xuat RLN du lieu\n";
		cout<<"7. Xuat LRN du lieu\n";
		cout<<"8. Dem so nguyen to trong day\n";
		cout<<"9. Tim Kiem\n";
		cout<<"10. Xuat node co 2 con\n";
		cout<<"11. Xuat node co 1 con\n";
		cout<<"12. Xuat node la\n";
		cout<<"13. Tim Max\n";
		cout<<"14. Tim Min\n";
		cout<<"15. Xoa node co gt\n";
		cout<<"16. Doc tu file\n";
		cout<<"16. Doc tu file I\n";
		cout<<"0. End\n";

		int chon;
		cout<<"Moi ban chon: ";
		cin>>chon;
		if(chon<0||chon>50)
		{
			cout<<"khong hop le\n";
		}
		else if(chon==1)
		{
			int x;
			cout<<"Nhap so nguyen x: ";
			cin>>x;
			Add(t,x);
		}
		else if(chon==2)
		{
			cout<<"Duyet cay theo NLR: \n";
			Xuat_NLR(t);
		}
		else if(chon==3)
		{
			cout<<"Duyet cay theo NRL: \n";
			Xuat_NRL(t);
		}
		else if(chon==4)
		{
			cout<<"Duyet cay theo LNR (be->lon): \n";
			Xuat_LNR(t);
		}
		else if(chon==5)
		{
			cout<<"Duyet cay theo RNL (lon->be): \n";
			Xuat_RNL(t);
		}
		else if(chon==6)
		{
			cout<<"Duyet cay theo RLN: \n";
			Xuat_RLN(t);
		}
		else if(chon==7)
		{
			cout<<"Duyet cay theo LRN: \n";
			Xuat_LRN(t);
		}
		else if(chon==8)
		{
			// int dem=0;
			SL_PRIME(t);
			cout<<"So luong so nguyen to: "<<dem<<endl;
		}
		else if(chon==9)
		{
			int a;
			cout<<"Nhap ptu can tim kiem: ";
			cin>>a;
			TimKiem(t,a);
				
		}
		else if(chon==10)
		{
			cout<<"Node co 2 con: ";
			Node_2con(t);
		}
		else if(chon==11)
		{
			cout<<"Node co 1 con: ";
			Node_1con(t);
		}
		else if(chon==12)
		{
			cout<<"Node la: ";
			Node_la(t);
		}
		else if(chon==13)
		{
			cout<<"Max la: "<<Max(t)<<endl;
		}
		else if(chon==14)
		{
			cout<<"Min la: "<<Min(t)<<endl;
		}
		else if(chon==15)
		{
			int v;
			cout<<"Moi ban nhap gt can xoa: ";
			cin>>v;
			Delete(t,v);
		}
		else if(chon==16)
		{
			Doc_file(t);
		}
		else if(chon==17)
		{
			Doc_file1(t);
		}
		else
		{
			break;
		}
		cout<<"\nNhan phim bat ky roi enter de tiep tuc\n";
		char ch;
		cin>>ch;
		system("clear");
	}
}

int main() {
  node* t;
	KhoiTao(t);
	// Add(t,2);
	// Add(t,5);
	// Add(t,6);
	// //Add(t,4);
	// Add(t,-3);
	// Add(t,0);
	// Add(t,1);
	// Add(t,8);
	// Add(t,-5);
	Menu(t);


}