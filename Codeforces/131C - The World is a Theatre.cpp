#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(61, vector<ll>(61));

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 60; i++)
        combinatoric[i][0] = 1;

    for (int i = 1; i <= 60; i++)
    {
        for (int j = 1; j <= 60; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1]) + (combinatoric[i-1][j]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Precompute
    count_combinatoric();

    ll n, m, t, ans = 0;
    cin >> n >> m >> t;

    for (int boy = 4; (boy < t) && (boy <= n); boy++)
    {
        ans += (combinatoric[n][boy] * combinatoric[m][t - boy]);
        //cout << boy << " " << combinatoric[n][boy] << " " << combinatoric[m][t - boy] << " " << ans << "\n";
    }

    cout << ans << "\n";
}
