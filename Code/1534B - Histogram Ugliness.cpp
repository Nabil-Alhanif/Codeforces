#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, ans = 0;
        cin >> n;

        vector<ll> histogram(n+2);
        for (int i = 1; i <= n; i++)
            cin >> histogram[i];
        histogram[n+1] = 0;

        for (int i = 1; i <= n; i++)
        {
            ll new_height = min(histogram[i], max(histogram[i-1], histogram[i+1]));
            ans += histogram[i] - new_height + abs(new_height - histogram[i-1]);
            histogram[i] = new_height;
        }

        cout << ans + histogram[n] << "\n";
    }
}
