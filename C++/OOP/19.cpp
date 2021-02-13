#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
int arr[10000001];
void precompute()
{
	int n = 0;
	int count = 0;
	int temp = 0;
	for(int i=0;i<10000001;i++)
	{
		n=i;
		while(n>0)
		{
			if(n%10==7)
			{
				count++;
			}
			n/=10;
		}
		arr[i] = count;
	}
}
int  main()
{
	precompute();
	 ll test;
	 cin>>test;
	 while(test--)
	 {
	 	ll l,r;
	 	cin>>l>>r;
	 	cout<<abs(arr[r]-arr[l-1])<<endl<<endl;
	 }
}
