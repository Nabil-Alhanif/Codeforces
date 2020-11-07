#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t;
  cin>>t;
  while (t--)
  {
    ll n,q;
    cin>>n>>q;
    ll ar[n+1];
    ar[n]=0;
    for (int i=0;i<n;i++)
      cin>>ar[i];
    ll index=-1,ans=0,cnt=0;
    while (1)
    {
      ll locIndex=index;
      if (cnt%2)
      {
        for (int i=index+1;i<n;i++)
        {
          if (ar[i]<ar[i+1]||i==n-1)
          {
            locIndex=i;
            //cout<<"MinSearch -> cnt: "<<cnt<<" locIndex: "<<locIndex<<"\n";
            break;
          }
        }
        ans-=ar[locIndex];
        index=locIndex;
      }
      else
      {
        for (int i=index+1;i<n;i++)
        {
          if (ar[i]>ar[i+1]||i==n-1)
          {
            locIndex=i;
            //cout<<"MaxSearch -> cnt: "<<cnt<<" locIndex: "<<locIndex<<"\n";
            break;
          }
        }
        ans+=ar[locIndex];
        index=locIndex;
      }
      //cout<<"Cur -> cnt: "<<cnt<<" index: "<<index<<"\n";
      if (index==n-1)
      {
        if (cnt%2)
          ans+=ar[index];
        break;
      }
      cnt++;
    }
    cout<<ans<<"\n";
  }
}
