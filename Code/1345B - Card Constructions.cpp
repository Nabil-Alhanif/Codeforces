#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll curSum=2,nextAdd=5;
    vector<ll>pyramid;
    while (curSum<=1e9)
    {
        pyramid.push_back(curSum);
        curSum+=nextAdd;
        nextAdd+=3;
    }
    ll size = pyramid.size();
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,ans=0;
        cin>>n;
        while (n>1)
        {
            ll l=0,r=size-1,mid,ret;
            while (l<=r)
            {
                mid = (l+r)/2;
                if (pyramid[mid]<=n)
                {
                    ret=pyramid[mid];
                    l=mid+1;
                }
                else r=mid-1;
            }
            ans++;
            n-=ret;
        }
        cout<<ans<<"\n";
    }
}