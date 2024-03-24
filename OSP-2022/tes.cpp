#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;

const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    ll board[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    ll dp[n][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int hor = 0; hor < m; hor++) {
        for (int ver = 0; ver < n; ver++) {
            for (int nhor = hor; (nhor < m) && (nhor <= hor + board[ver][hor]); nhor++) {
                for (int nver = ver; (nver < n) && (nver <= ver + board[ver][hor]); nver++) {
                    //cout << hor << " " << ver << " " << nhor << " " << nver << "\n";
                    if ((nhor != hor) || (nver != ver))
                        dp[nver][nhor] += dp[ver][hor];

                    /*
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++)
                            cout << dp[i][j] << " ";
                        cout << "\n";
                    }

                    cout << "\n\n";
                    */
                }
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";
}
