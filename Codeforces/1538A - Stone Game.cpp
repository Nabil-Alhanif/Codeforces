#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> stone(n);
        int mins = 1000, maks = -1000, mins_stone = 1000, maks_stone = -1000;
        for (int i = 0; i < n; i++)
        {
            cin >> stone[i];
            if (stone[i] < mins_stone)
            {
                mins_stone = stone[i];
                mins = i;
            }
            if (stone[i] > maks_stone)
            {
                maks = i;
                maks_stone = stone[i];
            }
        }
        int ans = 0;
        int mins_mins = min(mins + 1, n - mins);
        int mins_maks = min(maks + 1, n - maks);
        ans = min(mins_maks, mins_mins);
        if (mins_mins <= mins_maks)
        {
            if (mins + 1 <= n - mins)
                ans += min(maks - mins, n - maks);
            else ans += min(maks + 1, mins - maks);
        }
        else
        {
            if (maks + 1 <= n - maks)
                ans += min(mins - maks, n - mins);
            else ans += min(mins + 1, maks - mins);
        }
        cout << ans << "\n";
    }
}
