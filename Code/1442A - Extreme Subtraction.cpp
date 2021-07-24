#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> ar(n);
        for (auto &i:ar)
            cin >> i;

        ll ans = ar[n-1];
        for (int i = 0; i < n-1; i++)
        {
            if (ar[i] < ar[i+1])
                ans += (ar[i] - ar[i+1]);
        }

        if (ans >= 0)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
