#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t, n, ans;
    string s[2];

    cin >> t;

    while (t--)
    {
        cin >> n;
        ans = 0;

        cin >> s[0] >> s[1];

        vector<vector<short>> state(2, vector<short>(n + 2));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
                state[i][j] = s[i][j - 1] - '0';
        }

        state[0][0] = -1;
        state[0][n + 1] = -1;

        for (int i = 1; i <= n; i++)
        {
            if (state[1][i])
            {
                if (state[0][i - 1] == 1)
                {
                    ans++;
                    state[0][i - 1] = -1;
                    state[1][i] = 0;
                }
                else if (state[0][i] == 0)
                {
                    ans++;
                    state[0][i] = -1;
                    state[1][i] = 0;
                }
                else if (state[0][i + 1] == 1)
                {
                    ans++;
                    state[0][i + 1] = -1;
                    state[1][i] = 0;
                }
            }
        }

        cout << ans << "\n";
    }
}
