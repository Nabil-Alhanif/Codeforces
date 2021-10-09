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

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int pos_cnt = 0;

        vector<int> seq(n);
        for (auto &i:seq)
        {
            cin >> i;
            if (i > 0)
                pos_cnt++;
        }
        sort(seq.begin(), seq.end());

        if (pos_cnt == 0)
        {
            cout << n << "\n";
            continue;
        }

        if (pos_cnt == n)
        {
            cout << "1\n";
            continue;
        }

        int mins = MOD;
        for (int i = 1; i < n; i++)
        {
            mins = min(seq[i] - seq[i - 1], mins);

            if (seq[i] > 0)
                break;
        }

        if (mins >= seq[n - pos_cnt])
            cout << n - pos_cnt + 1 << "\n";
        else cout << n - pos_cnt << "\n";
    }
}
