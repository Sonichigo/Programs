#include<iostream>
#include<string.h>
using namespace std;
class student{
	char name[50];
	long int roll;
	int age;
	public:
		student(char n[50],long int r,int a)
		{
			strcpy(name,n);
			roll=r;
			age=a;
		}
		void display()
		{
			cout<<"Name:"<<name<<endl;
			cout<<"Roll:"<<roll<<endl;
			cout<<"Age:"<<age<<endl;
		}
};
class test:public student
{
	int m[5];
	int total=0;
	public:
		test(char name[50],long int roll,int age):student(name,roll,age)
		{
		}
		void acceptm()
		{
			for(int i=0;i<5;i++)
			{
				cout<<"Enter marks:";
				cin>>m[i];
				total+=m[i];
			}
		}
		void displaym()
		{
			cout<<"Marks in 5 subjects:"<<endl;
			for(int i=0;i<5;i++)
			{
				cout<<m[i]<<endl;
			}
		}
		int rettot()
		{
			return total;
		}
};
class sports
{
	int marks;
	public:
		int acceptsm()
		{
			cout<<"Enter marks in sports:";
			cin>>marks;
			return marks;
		}
		void displaysm()
		{
			cout<<"Marks in sports:"<<marks<<endl;
		}
};
class result:public test,public sports
{
	int total;
	float per;
	public:
		result(char name[50],long int roll,int age):test(name,roll,age)
		{
		}
		void calc(int tot,int sm)
		{
			total=tot+sm;
			per=total/6.0;
		}
		void displayres()
		{
			cout<<"Total:"<<total<<endl;
			cout<<"Average:"<<per;
		}
};
int main()
{
	char name[50];
	long int roll;
	int age;
	fflush(stdout);
	cout<<"Enter Name:";
	fflush(stdin);
	gets(name);
	cout<<"Enter roll no:";
	cin>>roll;
	cout<<"Enter age:";
	cin>>age;
	result r(name,roll,age);
	r.acceptm();
	int sm=r.acceptsm();
	cout<<"\nResult:"<<endl;
	r.display();
	r.displaym();
	r.displaysm();
	int tot=r.rettot();
	r.calc(tot,sm);
	r.displayres();
	return 0;
}
