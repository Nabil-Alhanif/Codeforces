#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  string s;
  cin>>s;
  int size=s.size(),ans=INT_MAX;
  int pref[size],suff[size];
  pref[0]=0;suff[size-1]=0;
  for (int i=1;i<size;i++)
    pref[i]=pref[i-1]+(s[i-1]>='a'?1:0);
  for (int i=size-2;i>=0;i--)
    suff[i]=suff[i+1]+(s[i+1]<'a'?1:0);
  /*
  for (int i=0;i<size;i++)
    cout<<pref[i]<<" ";
  cout<<"\n";
  for (int i=0;i<size;i++)
    cout<<suff[i]<<" ";
  cout<<"\n";
  */
  for (int i=0;i<size;i++)
    ans=min(ans,pref[i]+suff[i]);
  cout<<ans<<"\n";
}
