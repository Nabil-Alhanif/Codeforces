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
        int n, k, tmp;
        cin >> n >> k;

        set<int> sets;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            sets.insert(tmp);
        }

        if (sets.size() > k)
        {
            cout << "-1\n";
            continue;
        }

        for (int i = 1; (i <= n) && (sets.size() < k); i++)
            sets.insert(i);

        cout << (ll)(n * k) << "\n";
        for (int i = 0; i < n; i++)
        {
            for (auto j:sets)
                cout << j << " ";
        }
        cout << "\n";
    }
}
