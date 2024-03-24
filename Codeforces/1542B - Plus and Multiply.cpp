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
        ll n, a, b, dif;
        cin >> n >> a >> b;

        bool ans = 0;

        if (b == 1)
        {
            cout << "Yes\n";
            continue;
        }

        if (a == 1)
        {
            if ((n-1) % b)
                cout << "No\n";
            else cout << "Yes\n";
            continue;
        }

        for (ll i = 1; i <= n; i *= a)
        {
            dif = n - i;
            ans |= (!(dif % b));
        }
        
        if (ans)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
