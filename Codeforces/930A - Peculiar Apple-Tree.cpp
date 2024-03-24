#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 998244353, INF = 1e18;
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

    int n, ans = 1;
    cin >> n;

    vector<int> graphs(n + 1);
    vector<int> dist(n + 1);
    map<int, int> apple;

    dist[1] = 1;

    for (int i = 1; i < n; i++)
    {
        cin >> graphs[i];
        dist[i + 1] = dist[graphs[i]] + 1;
        apple[dist[i + 1]]++;
    }

    for (auto i:apple)
        ans += (i.second % 2);

    cout << ans << "\n";
}
