#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, size;
    cin >> n;

    vector<pair<int, int>> point(n);
    for (auto &i:point)
        cin >> i.first >> i.second;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                size = point[i].first * (point[j].second - point[k].second) + 
                    point[j].first * (point[k].second - point[i].second) +
                    point[k].first * (point[i].second - point[j].second);

                if (size)
                    ans++;
            }
        }
    }

    cout << ans << "\n";
}
