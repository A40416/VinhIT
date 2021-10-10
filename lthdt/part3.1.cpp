#include <iostream>
#include <string>
using namespace std;
class Pet
{
	private:
		string name;
		string dk;
	public:
		Pet()
		{
			
		}
		Pet(string n, string d)
		{
			name=n;
			dk=d;
		}	
		string getN() const
		{
			return name;
		}
		string getD() const
		{
			return dk;
		}
		virtual void print()
		{
			cout<<"-------Pet---------------\n";
			cout<<getN()<<endl;
			cout<<getD()<<endl;
		}
};
class Cat : public Pet
{
	private:
		string longg;
		string dat;
	public:
		Cat()
		{
			
		}
		Cat(  string lg, string d)
		{
			longg=lg;
			dat=d;
		}
		void setL(string lg)
		{
			longg=lg;
		}
		void setD(string d)
		{
			dat=d;
		}
		string getDK()
		{
			return dat;
		}
		string getLong() const
		{
			return longg;
		}
		virtual void print()
		{
			cout<<"--------CAT--------\n";
			cout<<"Long: "<<getLong()<<endl;
			cout<<"DK song: "<<getDK()<<endl;
		}

};
class Fish : public Pet
{
	private:
		string Ca;
		string nuoc;
	public:
		Fish()
		{
			
		}
	Fish(string c, string n)
	{
		Ca=c;
		nuoc=n;
	}	
	string getCa() const
	{
		return Ca;
	}
	string getN() const
	{
		return nuoc;
	}
	virtual void print()
	{
		cout<<"-----------FIsh------------\n";
		cout<<"Ten: "<<getCa()<<endl;
		cout<<"MTS: "<<getN()<<endl;
	}
};
int main()
{
	Pet *hi[3]={
				new Pet("vinh","tren troi"),
				new Cat("dai","song tren can.."),
				new Fish("Ca voi", "nuoc man")
	};
	for(int i=0; i<3; i++)
	{
		hi[i] -> print(); 
	}
}