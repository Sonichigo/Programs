#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class check{
	private:
	char *name;
	int *age;
	public:
		check(char n[50],int a)
		{
			age=new int();
			*age=a;
			name=new char[50];
			strcpy(name,n);
		}
		void display()
		{
			cout<<"Name:"<<name;
			cout<<"\nAge:"<<age;
		}
};
int main()
{
	int a;
	char n[50];
	fflush(stdout);
	cout<<"Enter Name:";
	gets(n);
	cout<<"Enter age:";
	cin>>a;
	check(n,a);
}
