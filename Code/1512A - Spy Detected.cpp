#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> ar(n);
        map<ll, pair<ll,ll>> m;
        for (int i=0; i<n; i++)
        {
            cin >> ar[i];
            m[ar[i]] = {i, m[ar[i]].second+1};
        }
        for (auto i:m)
        {
            if (i.second.second==1)
                cout << i.second.first+1 << "\n";
        }
    }
}
