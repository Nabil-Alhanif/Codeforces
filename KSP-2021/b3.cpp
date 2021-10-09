#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<pair<pair<ll, ll>, ll>> obat(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> obat[i].first.first >> obat[i].first.second >> obat[i].second;

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (obat[i].first.first <= j)
            {
                //cout << j << " " << obat[i].first.first << " iobat\n";
                if (obat[i].second == 1)
                {
                    //cout << "ij " << i << " " << j << " " << obat[i].first.first << " " << obat[i].first.second << " " << obat[i].second << "\n";
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - obat[i].first.first] + obat[i].first.second);
                }
            }
        }
    }

    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    */
    cout << dp[n][m] << "\n";
}

/*
5 7
2 7 1
5 23 1
1 4 1
3 15 1
4 19 1
*/
