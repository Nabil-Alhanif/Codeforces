#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int n, q;

int solve(int id, vector<pair<int, int>> &pos)
{
    int ret = 0, mins = 1e9;

    vector<int> dp(n + 2), cnt(n + 2), pref(n + 2);
    for (int i = 0; i < q; i++)
    {
        if (i == id)
            continue;
        dp[pos[i].first]++;
        dp[pos[i].second + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i - 1] + dp[i];
        if (cnt[i] != 0)
            ret++;
    }

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1];
        if (cnt[i] == 1)
            pref[i]++;
    }

    for (int i = 0; i < q; i++)
    {
        if (i == id)
            continue;
        mins = min(mins, pref[pos[i].second] - pref[pos[i].first - 1]);
    }

    return (ret - mins);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ans = 0;
    cin >> n >> q;

    vector<pair<int, int>> pos(q);
    for (auto &i:pos)
        cin >> i.first >> i.second;

    for (int i = 0; i < q; i++)
        ans = max(ans, solve(i, pos));
    cout << ans << "\n";
}
