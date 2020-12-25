#include<iostream>
#include<string.h>
using namespace std;
class Account{
	long long int acc_no;
	char name[100];
	float bal;
	public:
		Account(char n[100],long long int acc,float b)
		{
			strcpy(name,n);
			acc_no=acc;
			bal=b;
		}
		void deposit()
		{
			float amt;
			cout<<"Enter money to be deposited:";
			cin>>amt;
			bal+=amt;
		}
		void withdraw(float dec,int n)
		{
			float amt,calc=0;
			cout<<"Amount to be withdrawn:";
			cin>>amt;
			if(n==1)
			{
				calc=bal-amt;
				if(calc<dec)
				{
					cout<<"Amount can't be withdrawn"<<endl;
					
				}
				else
				{
					bal=-amt;
					cout<<"New Amount after withdrawl:"<<calc<<endl;
				}
				
			}
			else if(n==2)
			{
				bal-=dec;
				calc=bal-amt;
				if(calc>0)
				{
					bal=calc;
					cout<<"New Amount after withdrawl:"<<calc;
				}
				else
				{
					cout<<"Amount can't be withdrawn"<<endl;
				}
			}
		}
		void display()
		{
			cout<<"Name:"<<name<<endl;
			cout<<"Account Number:"<<acc_no<<endl;
			cout<<"Balance:"<<bal<<endl;
		}
};
class Savings:public Account{
	float min;
	public:
		Savings(float min_bal,char n[100],long long int acc,float b):Account(n,acc,b)
		{
			min=min_bal;
		}
};
class Current:public Account{
	float over;
	public:
		Current(float overdue,char n[100],long long int acc,float b):Account(n,acc,b)
		{
			over=overdue;
		}
};
int main()
{
	int n;
	long long int acc_no;
	float bal;
	char name[50];
	fflush(stdout);
	cout<<"Enter name:";
	fflush(stdin);
	gets(name);
	cout<<"Enter account no:";
	cin>>acc_no;
	cout<<"Enter current balance:";
	cin>>bal;
	cout<<"Enter 1 if your account is Savings and 2 if your account is Current:";
	cin>>n;
	if(n==1)
	{
		float min_bal;
		cout<<"Enter Minimum Balance to be kept:";
		cin>>min_bal;
		Savings s(min_bal,name,acc_no,bal);
		s.deposit();
		s.withdraw(min_bal,n);
		s.display();
	}
	else if(n==2)
	{
		float over;
		cout<<"Enter overdue ammount:";
		cin>>over;
		Current c(over,name,acc_no,bal);
		c.deposit();
		c.withdraw(over,n);
		c.display();
	}
	else
	cout<<"Wrong Input";
	return 0;
}
