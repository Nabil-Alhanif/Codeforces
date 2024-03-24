#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

ll __lcm(ll a, ll b)
{
    return ((a * b) / __gcd(a, b));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll x, ans;
    cin >> x;

    for (ll i = 1; i * i <= x; i++)
    {
        if ((x % i == 0) && (__lcm(i, x/i) == x))
            ans = i;
    }

    cout << ans << " " << x/ans << "\n";
}
