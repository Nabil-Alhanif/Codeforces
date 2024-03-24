#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,x,ans=0;
        cin>>n>>x;
        vector<pair<ll,ll>>v;
        for (int i=0;i<n;i++)
        {
            ll tmp,tmpp;
            cin>>tmp;
            v.push_back({tmp,1});
        }
        bool lanjut=1;
        for (int i=0;i<n;i++)
        {
            ans+=v[i].first*v[i].second;
            //cout<<v[i].first<<":"<<v[i].second<<" ";
            if (lanjut)
            {
                if (v[i].first%x)
                    lanjut=0;
                else
                {
                    v.push_back({v[i].first/x,v[i].second*x});
                    n++;
                }
            }
        }
        //cout<<"\n";
        cout<<ans<<"\n";
    }
}