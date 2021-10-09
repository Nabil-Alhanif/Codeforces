#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;

    int ans = a + b;
    cout << ans << "\n";
}
