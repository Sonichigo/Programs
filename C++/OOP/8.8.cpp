#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class item{
	private:
		long int code;
		int stock;
		char prod[100];
		float price;
		public:
			void accept()
			{
				fflush(stdout);
				cout<<"\nEnter name:";
				fflush(stdin);
				gets(prod);
				cout<<"Enter code:";
				cin>>code;
				cout<<"Enter Price:";
				cin>>price;
				cout<<"Enter stock:";
				cin>>stock;
			}
			void display()
			{
				cout<<"\nProduct:"<<prod;
				cout<<"\nCode:"<<code;
				cout<<"\nPrice:"<<price;
				cout<<"\nStock:"<<stock;
			}
};
class EA:public item{

	private:
	int power;
	public:
		void accept()
		{
			cout<<"Enter power consumed:";
			cin>>power;
		}
		void display()
		{
			cout<<"\nPower:"<<power;
		}
};
class FI:public item{
	char type[50];
	public:
		void accept()
		{
			fflush(stdout);
			cout<<"Enter type of food:";
			fflush(stdin);
			gets(type);
		}
		void display()
		{
			cout<<"\nType:"<<type;
		}
};
int main()
{
	EA e1,e2;
	e1.item::accept();
	e1.accept();
	e1.item::display();
	e1.display();
	e2.item::accept();
	e2.display();
	FI f;
	f.item::accept();
	f.accept();
	f.item::display();
	f.display();
}
