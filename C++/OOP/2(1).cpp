#include<iostream>
using namespace std;
class A{
	public:
		A()
		{
			cout<<"Constructor of A"<<endl;
		}
		~A()
		{
			cout<<"Destructor of A"<<endl;
		}
};
class B:public A{
	public:
		B()
		{
			cout<<"Constructor of B"<<endl;
		}
		~B()
		{
			cout<<"Destructor of B"<<endl;
		}
};
class C:public B{
	public:
		C()
		{
			cout<<"Constructor of C"<<endl;
		}
		~C()
		{
			cout<<"Destructor of C"<<endl;
		}
};
int main()
{
	C c;
	return 0;
}
