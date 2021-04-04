#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,ans=LLONG_MAX;
        cin>>n;
        pair<ll,ll>ar[n];
        ll left[n], right[n];
        for (int i=0;i<n;i++)
        {
            cin>>ar[i].first>>ar[i].second;
            left[i]=ar[i].first;
            right[i]=ar[i].second;
        }
        sort(ar,ar+n);
        sort(left,left+n);
        sort(right,right+n);
        for (int i=0;i<n;i++)
        {
            ll r=upper_bound(left,left+n,ar[i].second)-left;
            ll l=lower_bound(right,right+n,ar[i].first)-right;
            ans=min(ans,n-(r-l));
        }
        cout<<ans<<"\n";
    }
}
