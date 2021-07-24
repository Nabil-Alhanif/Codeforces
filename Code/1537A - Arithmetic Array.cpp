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
        ll n, a, ans = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            ans += a;
        }

        if (ans < n)
            cout << "1\n";
        else if (ans == n)
            cout << "0\n";
        else cout << ans - n << "\n";
    }
}
