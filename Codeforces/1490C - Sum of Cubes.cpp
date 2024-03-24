#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

vector<ll> f(400005);

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

    int t;
    cin >> t;

    while (t--)
    {
        ll x;
        cin >> x;

        bool flag = 0;

        for (ll i = 1; i <= cbrt(x) && !flag; i++)
        {
            ll dif = x - pow(i, 3);
            if (dif <= 0)
                continue;

            flag |= (pow(((ll)cbrt(dif)), 3) == dif);
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}
