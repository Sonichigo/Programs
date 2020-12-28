#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class staff{
	private:
		long int code;
		char name[50];
		public:
			void accept()
			{
				cout<<"Enter Staff Code:";
				cin>>code;
				fflush(stdout);
				cout<<"Enter Name of Staff:";
				fflush(stdin);
				gets(name);
			}
			void display()
			{
				cout<<"\nStaff Code:"<<code;
				cout<<"\nStaff Name:"<<name;
			}
};
class teacher:public staff{
	private:
		char sub[50];
		char pub[50];
		public:
			void accept()
			{
				fflush(stdout);
				cout<<"Enter subject:";
				fflush(stdin);
				gets(sub);
				fflush(stdout);
				cout<<"Enter Publication:";
				fflush(stdin);
				gets(pub);
			}
			void display()
			{
				cout<<"\nSubject:"<<sub;
				cout<<"\nPublication:"<<pub;
		}
};
class officer:public staff{
		private:
			char grade[10];
			public:
				void accept()
				{
					cout<<"Enter grade:";
					gets(grade);
				}
				void display()
				{
					cout<<"\nGrade:"<<grade;
				}
};
class typist:public staff{
	private:
		int speed;
		public:
			void accept()
			{
				cout<<"Enter Speed:";
				cin>>speed;
			}
			void display()
			{
				cout<<"\nSpeed:"<<speed;
			}
};
class casual:public typist{
	private:
		int daily_wages;
		public:
			void accept()
			{
				cout<<"Enter daily wages:";
				cin>>daily_wages;
			}
			void display()
			{
				cout<<"\nDaily Wages:"<<daily_wages;
			}
};
class regular:public typist{
};
int main()
{
	int n;
	cout<<"Enter staff category:\n1.1 for teacher\n2.2 for typist\n3.3 for officer\n";
	cin>>n;
	switch(n)
	{
		case 1:
			teacher t;
			t.staff::accept();
			t.accept();
			t.staff::display();
			t.display();
			break;
			case 2:
				int c;
				cout<<"\nEnter 1 for casual and 2 for regular:";
				cin>>c;
				if(c==1)
				{
					casual c;
				c.staff::accept();
				c.typist::accept();
				c.accept();
				c.staff::display();
				c.typist::display();
				c.display();
				}	
				else {
				regular r;
				r.staff::accept();
				r.typist::accept();
				r.staff::display();
				r.typist::display();
				}
				break;
				case 3:
					officer o;
					o.staff::accept();
					o.accept();
					o.staff::display();
					o.display();
					break;
					
	}
	return 0;
}
