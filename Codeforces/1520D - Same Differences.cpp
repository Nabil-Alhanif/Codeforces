#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, ans = 0, a;
        cin >> n;
        map<ll, ll> cnt;

        for (ll i = 0; i < n; i++)
        {
            cin >> a;
            ans += cnt[a-i];
            cnt[a-i]++;
        }

        cout << ans << "\n";
    }
}
