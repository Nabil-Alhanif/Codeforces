#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int size = s.size();
    vector<vector<ll>> dp(size + 2, vector<ll>(size + 2)); // Number of palindromic substring from i to j
    vector<ll> start(size + 2);
    vector<vector<bool>> pal(size + 2, vector<bool>(size + 2)); // Does the substring i to j palindrome?

    // Palindrome of single length
    for (int i = 1; i <= size; i++)
    {
        pal[i][i] = 1;
        start[i]++;
    }

    // Palindrome of length 2
    for (int i = 1; i < size; i++)
    {
        if (s[i - 1] == s[i])
        {
            pal[i][i + 1] = 1;
            dp[i][i + 1]++;
            start[i]++;
        }
    }

    // Palindrome of length more than 2
    for (int len = 2; len < size; len++)
    {
        for (int i = 1; i <= (size - len); i++)
        {
            int j = len + i;

            if ((s[i - 1] == s[j - 1]) && (pal[i + 1][j - 1]))
            {
                pal[i][j] = 1;
                start[i]++;
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1 - dp[i + 1][j - 1];
            }
            else dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        }
    }

    ll ans = 0;

    //cout << dp[1][size] << "\n";
    for (int i = 2; i <= size; i++)
    {
        ans += (start[i] * (dp[1][i - 1] + i - 1));
        //cout << start[i] << " " << dp[1][i - 1] + i - 1 << "\n";
    }
    cout << ans << "\n";
}
