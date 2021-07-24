#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    while (k--)
    {
        ll n, x, t;
        cin >> n >> x >> t;
        ll dis = min(n, t/x);
        ll ans = max((ll)0, dis * (n - dis));
        //cout << dis << " " << ans << "\n";
        ans += (dis * (dis + 1)) / 2;
        ans -= dis;
        cout << ans << "\n";
    }
}
