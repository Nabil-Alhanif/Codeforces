#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;
    cin >> n;

    vector<ll> dp(n + 1), pref(n + 1);
    pref[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            //cout << j << " j\n";
            dp[j]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        //cout << i << " " << dp[i] << " " << pref[i - 1] << "\n";
        dp[i] += pref[i - 1];
        dp[i] %= MOD;

        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << "\n";
}
