#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(1001, vector<ll>(1001));

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

ll inv(ll base, ll pow)
{
    if(pow == 0)
        return 1;
    ll ret = inv(base, pow/2);
    if (pow % 2 == 0)
        return ret * ret % MOD;
    else
        return ret * ret % MOD * base % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

    ll ans = 1;
    for(int i=1; i<=n+1; i++)
        ans = ans * (i + n + 1) % MOD * inv(i, MOD - 2) % MOD;
    cout << ans-1 << "\n";
    return 0;
}
