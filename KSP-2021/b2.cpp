#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

ll solve(ll a, ll b)
{
    if (a > b)
        swap(a, b);

    //cout << a << " " << b << " ab\n";

    if (b % a == 0)
        return a;
    else
        return solve((b % a), a);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;

    ll ans = __gcd(a, b);
    cout << ans << "\n";
}
