#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
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

    int n, q, l, r;
    cin >> n >> q;

    vector<int> ar(n + 1), dp(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    sort(ar.begin(), ar.end());

    while (q--)
    {
        cin >> l >> r;
        dp[l]++;

        if (r < n)
            dp[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
        dp[i] += dp[i - 1];
    sort(dp.begin(), dp.end());

    ll ans = 0;
    for (int i = 0; i <= n; i++)
        ans += (ll)(((ll)ar[i]) * ((ll)dp[i]));

    cout << ans << "\n";
}
