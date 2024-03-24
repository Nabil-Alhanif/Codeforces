#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;

    cin >> n;
    vector<int> fs(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> fs[i];

    cin >> m;
    vector<int> ss(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> ss[i];

    // Coba bikin LCS dulu lah ya
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (fs[i] == ss[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (auto i:dp)
    {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }

    vector<int> ans;

    int r = n, c = m;
    while ((r > 0) && (c > 0))
    {
        if (fs[r] == ss[c])
        {
            ans.push_back(fs[r]);
            r--, c--;
        }
        else
        {
            if (dp[r - 1][c] > dp[r][c - 1])
                r--;
            else c--;
        }
    }

    cout << dp[n][m] << "\n";
    for (auto i = ans.rbegin(); i != ans.rend(); i++)
        cout << *i << " ";
    cout << "\n";
}
