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

    ll t, n, k, add = 0, dif;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        add = 0;

        vector<ll> p(n);
        vector<ll> dp(n);

        for (auto &i:p)
            cin >> i;

        dp[0] = p[0];
        for (int i = 1; i < n; i++)
            dp[i] = p[i] + dp[i - 1];

        for (int i = n - 1; i > 0; i--)
        {
            ll mins = (p[i] * 100 + k - 1) / k;
            //cout << mins << " " << dp[i - 1] << "\n";

            if (mins > dp[i - 1])
            {
                dif = mins - dp[i - 1];
                add = max(add, dif);
            }
        }

        cout << add << "\n";
    }
}
