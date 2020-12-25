#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class student{
	char name[50];
	long int roll;
	int age;
	public:
		void accept()
		{
			cout<<"Enter Name:";
			gets(name);
			cout<<"Enter roll no:";
			cin>>roll;
			cout<<"Enter age:";
			cin>>age;
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
	public:
		void acceptm()
		{
			for(int i=0;i<5;i++)
			{
				cout<<"Enter marks:";
				cin>>m[i];
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
};
int main()
{
	test t;
	t.accept();
	t.acceptm();
	t.display();
	t.displaym();
	getch();
}