#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,m,k,ans=0;
  cin>>n>>m>>k;
  ll ar[n],con[n-1];
  for (int i=0;i<n;i++)
    cin>>ar[i];
  for (int i=1;i<n;i++)
    con[i-1]=ar[i]-ar[i-1];
  sort(con,con+n-1,greater<int>());
  /*
  for (int i=0;i<n-1;i++)
    cout<<con[i]<<" ";
  cout<<"\n";
  */
  for (int i=k-1;i<n-1;i++)
  {
    ans+=con[i];
    //cout<<con[i]<<"\n";
  }
  cout<<ans+k<<"\n";
}
