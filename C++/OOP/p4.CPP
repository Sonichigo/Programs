#include<iostream.h>
#include<conio.h>
class power
{
public:
inline int square(int n)
{
return n*n;
}
inline int cube(int n)
{
return n*n*n;
}
};
void main()
{
clrscr();
int n,r;
power p;
clrscr();
cout<<"\nEnter the Number: " ;
cin>>n;
r=p.square(n);
cout<<"\nSquare of "<<n<<" = "<<r<<endl;
r=p.cube(n);
cout<<"\nCube of "<<n<<" = "<<r<<endl;
getch();
}
