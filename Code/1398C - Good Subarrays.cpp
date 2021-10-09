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

    ll t, n, ans;
    char c;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ans = 0;

        map<ll, ll> m;
        vector<ll> ar(n + 1), dp(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> c;
            ar[i] = c - '0';
            dp[i] = dp[i - 1] + ar[i];

            m[dp[i - 1] - i + 1]++;

            ans += m[dp[i] - i];

            //cout << t << " " << n << " " << i << "\n";
        }

        /*
        for (auto i:dp)
            cout << i << " ";
        cout << "\n";
        */

        cout << ans << "\n";
    }
}
