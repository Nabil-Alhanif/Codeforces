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
        ll n,anss=0;
        cin>>n;
        vector<ll>ans(n);
        for (int i=0;i<n;i++)
            cin>>ans[i];
        for (int i=n-1;i>=0;i--)
        {
            ll tmp=i+ans[i];
            if (tmp<n)
                ans[i]+=ans[tmp];
            anss=max(anss,ans[i]);
        }
        cout<<anss<<"\n";
    }
}