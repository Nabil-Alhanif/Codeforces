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

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k, ans = 0;
        cin >> n >> k;

        vector<ll> gift(n), friends(k);

        for (auto &i:gift)
            cin >> i;
        sort(gift.begin(), gift.end(), greater<ll>());

        for (auto &i:friends)
            cin >> i;
        sort(friends.begin(), friends.end());

        for (int i = 0; i < k; i++)
        {
            if (friends[i] == 1)
                ans += (gift[i] * 2);
            else ans += gift[i];

            friends[i]--;
        }

        int pos = k - 1;
        for (int i = 0; i < k; i++)
        {
            if (friends[i])
            {
                pos += friends[i];
                ans += gift[pos];
            }
        }

        cout << ans << "\n";
    }
}
