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

    int t, n, m, tmp;
    bool flag = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        flag = 1;

        vector<pair<int, int>> ar(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i].first;
            ar[i].second = i;
        }
        sort(ar.begin(), ar.end());

        set<int> cnt;
        while (m--)
        {
            cin >> tmp;
            cnt.insert(--tmp);
        }

        for (int i = 0; i < n; i++)
        {
            if (ar[i].second < i) // Harus dipindah ke kanan
            {
                for (int j = ar[i].second; j < i; j++)
                    flag &= (bool)(cnt.count(j));
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}
