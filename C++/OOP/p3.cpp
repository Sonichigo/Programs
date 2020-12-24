#include <iostream.h>
#include <conio.h>
#include <string.h>
void print(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
}

void print(char ch)
{
    for (int i = 0; i < 80; i++)
        cout << ch;
}

void print()
{
    for(int i=0;i<80;i++)
        cout<<"*";
}

void main()
{
    int n;
    char ch;
    print(n,ch);
    cout<<"\n";
    print(80,ch);
    cout<<"\n";
    print();
    getch();
}