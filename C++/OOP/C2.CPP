#include<iostream.h>
class dist
{
private:
int feet;
float inches;  
public:
dist():feet(0),inches(0){}  
dist(int f, float in): feet(f),inches(in){}
    void getdist()
    {
        cout<<"feet=";cin>>feet;
        cout<<"inches=";cin>>inches;
    }
   friend bool operator <(dist d1) const;
};
bool dist::operator <(dist d2) const
{

  float dd1=d1.feet+d1.inches/12;
  float dd2=d2.feet+d2.inches/12;
  return (dd1<dd2)?true:false;
}

int main()
{
  dist d1(7,6.25);
  dist d2;
  d2.getdist();
  if(d1<d2)
    cout<<"d1 is smaller than d2"<<endl;
  else
    cout<<"d2 is smaller than d1"<<endl;
    return 0;
}