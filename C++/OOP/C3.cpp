#include<iostream.h>
#include<conio.h>
class square
{
   private:
        int n;
        static int b;
        public:
        void input();
        void calc();
        void display();
                
};
int square::b=0;
void square::input()
{
        cout<<"Enter an integer:";
        cin>>n;
        b++;
        
}
 void square::calc()
{
        r=n*n;
        r1=n1*n1;
        b++;
}
void square::display()
{
        cout<<"integer is:"<<n;
        cout<<"\nFunction is called "<<b<<" times by the objects";
}
int main()
{
        square s;
        s.input();
        s.calc();
        s.display();
  	getch();
}