#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const inf = 1e15;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, sum = 0;
        cin >> n;
        for (int i=1; i<n; i++)
        {
            ll tmp;
            cin >> tmp;
            sum += tmp;
        }
        ll ans = n*(n+1)/2;
        ans -= sum;
        cout << ans << "\n";
    }
}