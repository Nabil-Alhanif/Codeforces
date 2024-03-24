#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

vector<ll> f(400005);

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

ll inv(ll base, ll mod)
{
    if (base == 1)
        return 1;
    return inv(mod % base, mod) * (mod - (mod / base)) % mod;
}

ll comb(ll a, ll b)
{
    ll aa = f[a], bb = inv(f[b], MOD), cc = inv(f[a-b], MOD);
    aa *= bb;
    aa %= MOD;
    aa *= cc;
    aa %= MOD;
    return aa;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<ll> row1(n), row2(n), dp1(n + 1), dp2(n + 1);

    for (auto &i:row1)
        cin >> i;

    for (auto &i:row2)
        cin >> i;

    for (int i = n - 1; i >= 0; i--)
    {
        dp1[i] = max(dp1[i + 1], dp2[i + 1] + row1[i]);
        dp2[i] = max(dp2[i + 1], dp1[i + 1] + row2[i]);
    }

    cout << max(dp1[0], dp2[0]) << "\n";
}
