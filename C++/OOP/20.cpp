#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define ll long long
#define mes(x,y) memset(x,y,sizeof(x))
#define maxn 2147483648+30
using namespace std;
ll gar(ll a,ll b){//the greatest common divisor 
return b==0?a:gar(b,a%b);
}
int main(){
	long n,m,x;
	cin>>x;
	while(x--){
	while(cin>>n>>m){
		cout<<n*m/2<<endl;
	}	
	}
	return 0;
}
