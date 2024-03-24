#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

ll d(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n+1);
        vector<pair<int, int>> dp(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            dp[i] = dp[i-1];
            
            if (arr[i] > dp[i-1].first)
                dp[i] = {arr[i], i};
        }

        int idx = n;
        int pos = n;
        int lim = n;
        while (idx != 0)
        {
            pos = dp[idx].second;
            //cout << "IDX " << idx << " " << pos << " " << lim << "\n";
            for (int i = pos; i <= lim; i++)
                cout << arr[i] << " ";
            lim = pos - 1;
            idx = dp[pos-1].second;
        }
        cout << "\n";
    }
}
