#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class cricketer{
	private:
		char name[100];
		int match;
		int runs;
		int wickets;
		public:
			cricketer(char n[100],int m,int r,int w)
			{
				strcpy(name,n);
				match=m;
				runs=r;
				wickets=w;
			}
			void display()
			{
				cout<<"Name:"<<name<<endl;
				cout<<"Matches played:"<<match<<endl;
				cout<<"Runs scored:"<<runs<<endl;
				cout<<"Wickets:"<<wickets<<endl;
			}
};
class Batsman:public cricketer{
	public:
		Batsman(char n[100],int m,int r,int w):cricketer(n,m,r,w)
		{
		}
};
class Bowler:public cricketer{
	public:
		Bowler(char n[100],int m,int r,int w):cricketer(n,m,r,w)
		{
		}
};
class All_Rounder:virtual public Batsman,virtual public Bowler{
	float bat_avg;
	float bowl_avg;
	public:
		All_Rounder(char n[100],int m,int r,int w):Batsman(n,m,r,w)
		{
			bat_avg=r/m;
			bowl_avg=r/w;
		}
		void dis()
		{
			cout<<"Batting average:"<<bat_avg<<endl;
			cout<<"Bowling average:"<<bowl_avg<<endl;
		}
};
int main()
{
	char c,name[100];
	cout<<"Enter 1 if you are a Batsman\nEnter 2 for you are a Blower\nEnter 3 if you are an All Rounder:";
	cin>>c;
	fflush(stdout);
	cout<<"Enter your name:";
	fflush(stdin);
	gets(name);
	int runs,matches,wickets;
	cout<<"Enter no of matches played:";
	cin>>matches;
	cout<<"Enter the no of runs scored:";
	cin>>runs;
	cout<<"Enter the no of wickets taken:";
	cin>>wickets;
	if(c=='1')
	{
		Batsman b(name,matches,runs,wickets);	
		b.display();
	}
	else if(c=='2')
	{
		Bowler b(name,matches,runs,wickets);	
		b.display();
	}
	else if(c=='3')
	{
		All_Rounder a(name,matches,runs,wickets);
		a.Batsman::display();
		a.dis();
	}
	return 0;
}
