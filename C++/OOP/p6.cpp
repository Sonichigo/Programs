#include <iostream.h>
#include <conio.h>
int increment(int var)
{
    var = var+1;
    return var;
}
void main()
{
   int num1=20;
   int num2 = increment(num1);
   cout<<"num1 value is: "<<num1;
   cout<<"\nnum2 value is: "<<num2;
   getch();
}
