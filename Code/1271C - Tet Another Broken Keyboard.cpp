#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    string s;
    cin >> n >> k >> s;

    ll cnt = 0;
    ll ans = 0;

    map<char, bool> ada;
    while (k--)
    {
        char c;
        cin >> c;
        ada[c] = 1;
    }

    for (auto i:s)
    {
        if (!ada[i])
        {
            ans += (cnt * (cnt + 1)) / 2;
            //cout << cnt << " cnt\n";
            cnt = 0;
        }
        else cnt++;
    }

    ans += (cnt * (cnt + 1)) / 2;
    //cout << cnt << " cnt\n";
    cout << ans << "\n";
}
