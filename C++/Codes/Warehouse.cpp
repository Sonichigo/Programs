#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(s.size()<n)
  {
    string t;
    cin>>t;
    s=s+t;
  }
  int t;
  cin>>t;
  vector<int> v;
  while(t--)
  {
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    string a = s.substr(a1,a2-a1+1);
    string b = s.substr(b1,b2-b1+1);
    int sl = min(a.size(),b.size());
    if(a.size()>b.size())swap(a,b);
    int f=0;string ans="";
    for(int i=sl;sl>0;sl--)
    {
      for(int i=0;i+sl<=a.size();i++)
      {
        for(int j=0;j+sl<=b.size();j++)
        {
          if(a.substr(i,sl)==b.substr(j,sl))
          {
            ans = a.substr(i,sl);
            f=1;
            break;
          }
        }
        if(f==1)break;
      }
      if(f==1)break;
    }
    int w=0;
    for(int i=0;i<ans.size();i++)
    {
      w+=ans[i]-'a'+1;
    }
    v.push_back(w);
  }
  int N = *max_element(v.begin(),v.end());
  int E = *min_element(v.begin(),v.end());
  cout<<N%180<<" "<<E%180<<endl;
  return 0;
}
