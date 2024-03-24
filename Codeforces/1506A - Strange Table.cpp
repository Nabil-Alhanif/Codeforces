#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e12, MOD = 1e9+7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x;
        cin >> n >> m >> x;
        ll row, col;
        row = ((x-1)/n)+1;
        col = x%n;
        if (col==0)
            col = n;
        ll ans = m * (col-1) + row;
        cout << ans << "\n";
    }
}
