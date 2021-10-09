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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    count_combinatoric();

    ll k, ans = 1, total = 0;
    cin >> k;

    vector<ll> balls(k);
    for (auto &i:balls)
    {
        cin >> i;
        //cout << i << " " << total << " " << ans << " " << combinatoric[total + i - 1][i - 1] << "\n";
        ans = (ans * combinatoric[total + i - 1][i - 1]) % MOD;
        total += i;
    }

    cout << ans << "\n";
}
