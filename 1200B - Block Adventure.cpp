#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t;
  cin>>t;
  while (t--)
  {
    ll n,m,k;
    cin>>n>>m>>k;
    ll stair[n];
    for (int i=0;i<n;i++)
      cin>>stair[i];
    for (int i=0;i<n-1;i++)
    {
      ll tmp=max(stair[i+1]-k,0ll);
      //cout<<tmp<<" ";
      m+=stair[i]-tmp;
      if (m<0)
        break;
    }
    //cout<<"\n";
    if (m>=0)
      cout<<"YES\n";
    else cout<<"NO\n";
  }
}
