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
        ll n,ans=0;
        cin>>n;
        map<ll,ll>m;
        ll val[n+1];
        for (int i=1;i<=n;i++)
            cin>>val[i];
        for (int i=1;i<n;i++)
        {
            ll l, r;
            cin>>l>>r;
            m[l]++;
            m[r]++;
        }
        vector<pair<ll,ll>>node;
        for (auto i:m)
        {
            if (i.second>1)
                node.push_back({val[i.first],i.second-1});
            ans+=val[i.first];
        }
        sort(node.begin(),node.end(),greater<pair<ll,ll>>());
        cout<<ans;
        for (auto i:node)
        {
            while (i.second--)
            {
                ans+=i.first;
                cout<<" "<<ans;
            }
        }
        cout<<"\n";
    }
}