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
        vector<int> candy(n);

        int total = 0;
        for (auto &i: candy)
        {
            cin >> i;
            total += i;
        }

        if (total%n)
        {
            cout << "-1\n";
            continue;
        }

        int fair = total/n;
        int ans = 0;
        for (auto i:candy)
        {
            if (i > fair)
                ans++;
        }
        cout << ans << "\n";
    }
}
