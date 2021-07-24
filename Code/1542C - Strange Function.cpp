#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

ll __lcm(ll a, ll b)
{
    return ((a*b)/__gcd(a,b));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, div = 1, ans = 0;
        cin >> n;

        for (ll i = 1; div <= n; i++)
        {
            div = __lcm(div, i);
            if (div > n)
                break;
            ans += n/div;
            ans %= MOD;
        }
        
        cout << (ans+n)%MOD << "\n";
    }
}
