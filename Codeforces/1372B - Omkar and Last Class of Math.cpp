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
        ll n, n2, dif = 1;
        cin >> n;
        n2 = n;

        for (int i = 2; i * i <= n2; i++)
        {
            if (!(n2 % i))
            {
                dif = i;
                break;
            }
        }

        if (dif == 1)
            cout << 1 << " " << n - 1 << "\n";
        else
        {
            ll div = n / dif;
            cout << div << " " << n - div << "\n";
        }
    }
}
