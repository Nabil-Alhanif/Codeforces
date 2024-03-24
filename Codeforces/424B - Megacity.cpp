#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, s;
    cin >> n >> s;

    if (s >= 1000000)
        return cout << "0\n", 0;

    vector<pair<double, int>> dist(n);
    for (auto &i: dist)
    {
        double x, y;
        cin >> x >> y >> i.second;
        i.first = sqrt((x * x) + (y * y));
    }
    sort(dist.begin(), dist.end());

    double ans = -1;
    for (auto i:dist)
    {
        s += i.second;
        if (s >= 1000000)
        {
            ans = i.first;
            break;
        }
    }
    
    cout << setprecision(12) << ans << "\n";
}
