#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;

const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    if (n == 1) {
        vector<vector<ll>> dp(m + 1, vector<ll>(2)); // idx, state
        vector<ll> tot(m + 1);

        dp[1][0] = 1;
        dp[1][1] = 1;
        tot[1] = 2;

        for (int i = 2; i <= m; i++) {
            dp[i][0] = dp[i - 1][1] + tot[i - 1];
            dp[i][0] %= MOD;
            dp[i][1] = dp[i - 1][0] + tot[i - 1];
            dp[i][1] %= MOD;
            tot[i] = dp[i][0] + dp[i][1];
            tot[i] %= MOD;
        }
        cout << tot[m] << "\n";
    }
    else {
        vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(m + 1, vector<ll>(2))); // tinggi, lebar, state
        vector<vector<ll>> tot(2, vector<ll>(m + 1));

        dp[0][1][0] = 1;
        dp[0][1][1] = 1;
        tot[0][1] = 2;

        dp[1][1][0] = 3;
        dp[1][1][1] = 3;
        tot[1][1] = 6;

        for (int i = 2; i <= m; i++) {
            dp[0][i][0] = dp[0][i - 1][1] + tot[0][i - 1];
            dp[0][i][0] %= MOD;
            dp[0][i][1] = dp[0][i - 1][0] + tot[0][i - 1];
            dp[0][i][1] %= MOD;
            tot[0][i] = dp[0][i][0] + dp[0][i][1];
            tot[0][i] %= MOD;

            // Isi state 0 baris 2
            // Kalau dia nggak sambung sama atas dan kiri nya
            dp[1][i][0] = tot[0][i] * tot[1][i - 1];
            // Kalau dia sambung sama kiri tapi nggak sambung sama atas
            dp[1][i][0] += tot[0][i] * dp[1][i - 1][1];
            // Kalau dia sambung sama atas tapi nggak sambung sama kiri
            dp[1][i][0] += dp[0][i][1] * tot[1][i - 1];
            // Kalau dua duanya nyambung
            dp[1][i][0] += dp[0][i][1] * dp[1][i - 1][1];
            dp[1][i][0] %= MOD;

            // Isi state 1 baris 2
            // Kalau dia nggak sambung sama atas dan kiri nya
            dp[1][i][1] = tot[0][i] * tot[1][i - 1];
            // Kalau dia sambung sama kiri tapi nggak sambung sama atas
            dp[1][i][1] += tot[0][i] * dp[1][i - 1][0];
            // Kalau dia sambung sama atas tapi nggak sambung sama kiri
            dp[1][i][1] += dp[0][i][0] * tot[1][i - 1];
            // Kalau dua duanya nyambung
            dp[1][i][1] += dp[0][i][0] * dp[1][i - 1][0];
            dp[1][i][1] %= MOD;

            tot[1][i] = dp[1][i][0] + dp[1][i][1];
            tot[1][i] %= MOD;
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= m; j++)
                cout << tot[i][j] << " ";
            cout << "\n";
        }
    }
}
