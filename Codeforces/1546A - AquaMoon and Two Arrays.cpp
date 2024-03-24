#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, sum = 0;
        cin >> n;

        vector<int> arr(n+1);
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            arr[i] -= m;
            sum += arr[i];
        }

        if (sum != 0)
        {
            cout << "-1\n";
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= arr[i]; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (arr[k] < 0)
                    {
                        ans.push_back({i, k});
                        arr[k]++;
                        break;
                    }
                }
            }
        }

        cout << ans.size() << "\n";
        for (auto i:ans)
            cout << i.first << " " << i.second << "\n";
    }
}
