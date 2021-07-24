#include <bits/stdc++.h>
typedef uint_least32_t ll;
using namespace std;
const ll MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<vector<ll>> dp(k+1, vector<ll>(n+1)); // Gerakan keberapa, Lantai apa
    vector<vector<ll>> pref_sum(k+1, vector<ll>(n+1));

    dp[0][a] = 1;
    for (int i = 1; i <= n; i++)
        pref_sum[0][i] = pref_sum[0][i - 1] + dp[0][i];

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll mid = (j + b) / 2;
            
            if (j > b)
            {
                dp[i][j] = dp[i][j] + pref_sum[i - 1][n] - pref_sum[i - 1][mid];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
                dp[i][j] = dp[i][j] - pref_sum[i - 1][j] + pref_sum[i - 1][j - 1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
            else if (j < b)
            {
                if (mid * 2 == j + b)
                    mid--; // Kalau mid * 2 == j + b, maka jarak dari mid ke j dan b sama, jadi di min min
                dp[i][j] = dp[i][j] + pref_sum[i - 1][mid] - pref_sum[i - 1][0];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
                dp[i][j] = dp[i][j] - pref_sum[i - 1][j] + pref_sum[i - 1][j - 1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }

            pref_sum[i][j] = pref_sum[i][j - 1] + dp[i][j];
            pref_sum[i][j] %= MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[k][i];
        ans %= MOD;
    }
    cout << ans << "\n";
}
