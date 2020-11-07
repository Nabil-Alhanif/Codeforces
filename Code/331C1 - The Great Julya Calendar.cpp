#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
  ll n=0,tmp=0,ans=0,maks=0;
  cin>>n;
  while (n>0)
  {
    tmp=n,maks=0;ans++;
    while (tmp>0)
    {
      maks=max(maks,tmp%10);
      tmp/=10;
      //cout<<"tmp: "<<tmp<<"\n";
    }
    n-=maks;
    //cout<<"n: "<<n<<"\n";
  }
  cout<<ans<<"\n";
}
