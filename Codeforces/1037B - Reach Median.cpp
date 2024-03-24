#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,s;
  cin>>n>>s;
  ll ar[n];
  for (int i=0;i<n;i++)
    cin>>ar[i];
  sort(ar,ar+n);
  ll med=n/2;
  //cout<<ar[med]<<"\n";
  if (ar[med]==s)
    return cout<<"0\n",0;
  if (ar[med]>s)
  {
    ll ans=0;
    for (int i=med;i>=0;i--)
    {
      if (ar[i]>s)
        ans+=ar[i]-s;
      else
        break;
    }
    return cout<<""<<ans<<"\n",0;
  }
  if (ar[med]<s)
  {
    ll ans=0;
    for (int i=med;i<n;i++)
    {
      if (ar[i]<s)
        ans+=s-ar[i];
      else
        break;
    }
    return cout<<""<<ans<<"\n",0;
  }
}
