#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, ans = INF;
        cin >> n >> k;

        for (ll i = min(k, (ll)sqrt(n)); i >= 1; i--)
        {
            if (n%i == 0)
            {
                ll div1 = i;
                ll div2 = n/i;

                if (div1 <= k && div2 <= k)
                    ans = min(ans, min(div1, div2));
                else if (div1 <= k)
                    ans = min(ans, div2); // kalau div1 kurang dari k, beli paket yang isinya div1.
                else if (div2 <= k)       // Jadi, jumlah paket total yang dibeli adalah div2
                    ans = min(ans, div1); // Dan sebaliknya.
            }
        }
        cout << ans << "\n";
    }
}
