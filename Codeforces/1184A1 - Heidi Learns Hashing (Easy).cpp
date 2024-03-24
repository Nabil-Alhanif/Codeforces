#include <bits/stdc++.h>
using namespace std;
typedef uint_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll r;
    cin >> r;

    bool bisa = 0;

    for (int i = 1; i <= 1e6; i++)
    {
        ll tot = (i * i) + i + 1;
        if (tot > r)
            break;
        tot = r - tot;
        if ((tot % (2 * i) == 0) && ((tot / (2 * i)) > 0))
        {
            cout << i << " " << tot / (2 * i) << "\n";
            bisa = 1;
            break;
        }
    }

    if (!bisa)
        cout << "NO\n";
}
