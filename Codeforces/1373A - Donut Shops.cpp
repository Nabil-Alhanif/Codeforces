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
        ll a, b, c;
        cin >> a >> b >> c;

        if (a < c)
            cout << 1;
        else cout << "-1";

        cout << " ";

        if (a*b > c)
            cout << b;
        else cout << "-1";

        cout << "\n";
    }
}
