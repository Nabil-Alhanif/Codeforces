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

    ll n, m, add, mul, l, r, tmp;
    cin >> n >> m;

    vector<ll> dp(n + 1), pref(n + 1);
    dp[1] = 1;
    pref[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        add = pref[i - 1];

        mul = 0;
        for (int j = 1; j * j <= i; j++)
        {
            l = i / (j + 1);
            r = i / j;
            mul += ((dp[j] * (r - l)) % m);

            if (j != 1)
            {
                tmp = i / j;

                if (tmp != j)
                {
                    l = i / (tmp + 1);
                    r = i / tmp;
                    mul += ((dp[tmp] * (r - l)) % m);
                }
            }
        }

        dp[i] = (add + mul) % m;
        pref[i] = (pref[i - 1] + dp[i]) % m;

        //cout << dp[i] << " " << pref[i] << "\n";
    }

    cout << dp[n] << "\n";
}
