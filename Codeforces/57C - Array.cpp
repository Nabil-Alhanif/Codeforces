#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(1001, vector<ll>(1001));

vector<ll> f(400005);

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 1000; i++)
        combinatoric[i][0] = 1;

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1] % MOD) + (combinatoric[i-1][j] % MOD)) % MOD;
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

    f[0] = 1;
    for (int i = 1; i <= 400000; i++)
        f[i] = (f[i-1] * i) % MOD;

    ll n, ans;
    cin >> n;
    ans = ((comb(2*n-1, n-1)*2) - n) % MOD;

    cout << ans % MOD << "\n";
}
