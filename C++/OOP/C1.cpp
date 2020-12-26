#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class second;
class first
{
int a;
public:
friend void swap(first,second);
}f;
class second
{
int b;
public:
friend void swap(first,second);
}s;
void swap(first f,second s)
{
int temp;
f.a=10;
s.b=20;
cout<<"\nThe default value of";
cout<<"\na="<<f.a;
cout<<"\nb="<<s.b;
 
//swaping
temp=f.a;
f.a=s.b;
s.b=temp;
cout<<"\nNow the changed value of";
cout<<"\na="<<f.a;
cout<<"\nb="<<s.b;
 
}
void main()
{
swap(f,s);
getch();
}