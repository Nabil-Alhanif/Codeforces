#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;string s;
  cin>>n>>k>>s;
  for (int i=0;i<n-1&&k<n;i++)
  {
    if (s[i]=='('&&s[i+1]==')')
    {
      s.erase(i,2);
      i-=2;
      n-=2;
    }
    if (i<-1)i=-1;
  }
  cout<<s<<"\n";
}
