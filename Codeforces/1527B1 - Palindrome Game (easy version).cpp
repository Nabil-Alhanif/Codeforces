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
        int n, cnt = 0;
        cin >> n;

        string s;
        cin >> s;

        for (auto i:s)
            cnt += (int)(i == '0');

        if ((cnt == 1) || (cnt % 2 == 0))
            cout << "BOB\n";
        else cout << "ALICE\n";
    }
}
