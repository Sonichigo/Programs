#include <bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;

/*ll power(ll a,ll b)
{
   ll result=1;
   while(b>0)
   {
      if(b&1)
      result=(result*a)%M;
      a=(a*a)%M;
      b>>=1;
   }
   return result;
}*/
int lpower(ll x,unsigned int y, int p)
{
   int res=1;
   while(y>0)
   {
      if(y&1)
      res=(res*x)%p;
      x=(x*x)%p;
      y>>=1;
   }
   return res;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	   long int n,m;
	   cin>>n>>m;
	   ll temp =lpower(2,n,M) - 1;
	   cout<<lpower(temp,m,M)<<endl;
	}
	return 0;
}
