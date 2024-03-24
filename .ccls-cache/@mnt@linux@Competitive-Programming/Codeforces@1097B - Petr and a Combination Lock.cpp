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

    vector<int> mask(16);
    mask[0] = 1;
    for (int i = 1; i < 16; i++)
        mask[i] = mask[i - 1] * 2;

    int n, tot = 0;
    cin >> n;

    vector<int> rotation(n);
    for (auto &i:rotation)
        cin >> i;

    bool flag = 0;
    for (int i = 0; i < mask[n]; i++)
    {
        //cout << "i " << i << "\n";
        tot = 0;
        for (int j = 0; j < n; j++)
        {
            //cout << "j " << j << "\n";
            if (i & mask[j])
                tot += rotation[j];
            else tot -= rotation[j];
            tot %= 360;
        }

        flag |= (tot == 0);
    }

    cout << (flag ? "YES\n" : "NO\n");
}