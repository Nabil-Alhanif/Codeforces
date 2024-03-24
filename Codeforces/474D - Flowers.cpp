#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, k, left, right;
    cin >> t >> k;

    vector<ll> dp(1e5+1);
    vector<ll> pref(1e5+1);
    vector<int> mod_count(1e5+1);

    dp[0] = 1;
    pref[0] = 1;
    for (int i = 1; i <= 1e5; i++)
    {
        dp[i] = dp[i-1];
        mod_count[i]  = mod_count[i-1];

        if (i >= k)
            dp[i] += dp[i-k];

        pref[i] = pref[i-1] + dp[i];
        dp[i] %= MOD;
        if (pref[i] >= MOD)
        {
            mod_count[i]++;
            pref[i] %= MOD;
        }
    }

    while (t--)
    {
        cin >> left >> right;
        if (pref[right] < pref[left - 1])
            cout << (pref[right] - pref[left - 1]) + MOD << "\n";
        else cout << pref[right] - pref[left - 1] << "\n";
    }
}
