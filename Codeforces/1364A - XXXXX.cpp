#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, ans = -1;
        cin >> n >> x;
        vector<ll> ar(n+1);
        for (ll i=1; i<=n; i++)
        {
            cin >> ar[i];
            ar[i]+=ar[i-1];
            if (ar[i]%x)
                ans = max(ans, i);
        }
        for (ll i=0; i<=n; i++)
        {
            ll dif = ar[n]-ar[i];
            if (dif%x)
                ans = max(ans, n-i);
        }
        cout << ans << "\n";
    }
}
