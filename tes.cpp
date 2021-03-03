#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const inf = 1e15, MOD = 1e9+7;

ll cnt(ll mod, vector<ll>ar)
{
    ll n = ar.size();
    vector<vector<ll>>dp(n, vector<ll>(mod, 0));
    dp[0][ar[0]%mod]++;
    for (ll i=1; i<n; i++)
    {
        ll curRem = ar[i]%mod;
        dp[i][curRem]++;
        for (ll oldRem=0; oldRem<mod; oldRem++)
        {
            ll newRem = (curRem*oldRem)%mod;
            dp[i][newRem] += dp[i-1][oldRem];
        }
    }
    ll ret = 0;
    for (ll i=0; i<n; i++)
        ret += dp[i][0];
    return ret;
}

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
        for (ll i=0; i<n; i++)
        {
            cin >> ar[i];
            ar[i] = abs(ar[i]);
        }
        ll ans = (n*(n+1))/2 - cnt(2, ar) + cnt(4, ar);
        cout << ans << "\n";
    }
}